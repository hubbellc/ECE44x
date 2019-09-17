// THIS IS THE MAIN CODE

// Program talks to a number of external sensors, compiles data, stores it locally on an SD card, and wirelessly transmits it.
//  Performs a wireless 2-way handshake, intelligent power switching, and accurate data collection
//  Data is stored in a .CSV format

/*--------------------------------------------------------------------------------------
  Includes
  --------------------------------------------------------------------------------------*/
#include <TimeLib.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h> 
#include "cactus_io_BME280_I2C.h" 
#include <Adafruit_INA219.h> // Current sensor library
#include <Wire.h>
#include <Adafruit_Sensor.h> // Light sensor library
#include <Adafruit_TSL2561_U.h> // Light sensor libaray...Can use other i2c!!
#include "ULP.h"

/*--------------------------------------------------------------------------------------
  Definitions
  --------------------------------------------------------------------------------------*/
// pins used
#define relay 33 
#define builtin_LED 13
#define C1 A16 //TODO, check!
#define NH3 A15 //TODO, check!
#define CH4_pin A6

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define tran_number 1

// general
String temp = "";
bool error = 0;

// for timekeeping
long int timeHold[6];

// for SD card
File myFile;
const int chipSelect = BUILTIN_SDCARD;
const char * file_string = "raitong.csv"; // << set file here!! (NOTE: name cannot include a "_"...26 character letters only)

// for timekeeping
#define MINELAPSED .5 // <<------------------- set frequency for reading sensors here!!
#define LOOPTIME .5 // 30 seconds to try
#define TIMERMIN (1000UL * 60 * MINELAPSED)
#define TIMEOUT (1000UL * 60 * LOOPTIME)
unsigned long rolltime = millis() + TIMERMIN;
unsigned long starttime = millis();

// for datakeeping
const String header = "Tran#,Date,Temperature,Humidity,Air Pressure,Lux,NO2,CH4,NH3";
int temperature = 0;
int humidity = 0;
int airP = 0;
int light = 0;
int NO2_data = 0;
int CH4 = 0;
int NH3_data = 0;

// for power
float voltage;
Adafruit_INA219 ina219;

// for BME sensor
BME280_I2C bme(0x76); // I2C using address 0x76

// for lux sensor
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

// for NO2 sensor
const float Sf1 =-26.69; //nA/ppm
float temp1;
float TZero;
float Vzero1;
NO2 sensor1(C1, 0, Sf1);

void setup() 
{
  // begin comm to computer for responses (USB)
  Serial.begin(115200);

  // begin comm to Mdot (port 0 and 1)
  Serial1.begin(115200);

  // for status LED
  pinMode(builtin_LED, OUTPUT);
  digitalWrite(builtin_LED, HIGH);

  // for power
  pinMode(relay, OUTPUT);
  ina219.begin(&Wire1);
  ina219.setCalibration_16V_400mA();
 
  if((int)ina219.getBusVoltage_V() == 32)
  {
    Serial.println("Could not find a valid current sensor, check wiring!"); 
    error = 1;
  }

  // for sensing humidity and air pressure
  starttime = millis();
  while(!bme.begin() && millis() - starttime <= TIMEOUT){}
  if(!bme.begin())
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    error = 1;
  }
  bme.setTempCal(-2);// Calibration

  // for temp and NO2
  Vzero1 = sensor1.zero();

  //Lux setup:
  tsl.enableAutoRange(true);  
  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */ 
  /* Initialise the sensor */
  //use tsl.begin() to default to Wire, 
  //tsl.begin(&Wire2); // directs api to use Wire2, etc.

  starttime = millis();
  while(!tsl.begin(&Wire1) && millis() - starttime <= TIMEOUT){}
  if(!tsl.begin(&Wire1))
  {
    Serial.println("Could not find a valid light sensor, check wiring!");
    error = 1;
  }

  // program the Mdot
  progMdot();

  delay(1000); // 1 second delay ...TODO, refine
  
  // clear input buffers
  while (Serial.available() > 0 ) {
    Serial.read();
  }
  while (Serial1.available() > 0 ) {
    Serial1.read();
  }
  Serial1.flush();
  Serial.flush();

  // small delay needed
  delay(1000);

  // get the current time
  getTime();

  // configure SD card
  configSD(); // needs to be after time, uses time to init!

  //flash to tell status
  if(error) // three quick flashes
  {
    digitalWrite(builtin_LED, HIGH);
    delay(200);
    digitalWrite(builtin_LED, LOW);
    delay(200);
    digitalWrite(builtin_LED, HIGH);
    delay(200);
    digitalWrite(builtin_LED, LOW);
    delay(200);
    digitalWrite(builtin_LED, HIGH);
    delay(200);
    digitalWrite(builtin_LED, LOW);
    delay(200);
  }
  else // two long flashes
  {
    digitalWrite(builtin_LED, HIGH);
    delay(500);
    digitalWrite(builtin_LED, LOW);
    delay(500);
    digitalWrite(builtin_LED, HIGH);
    delay(500);
    digitalWrite(builtin_LED, LOW);
    delay(500);
  }
  
  Serial.println("---------------------beginning main loop--------------------");
  Serial.println(header);
}

void loop() 
{

  // for debug
//  temp = Serial1.readString();
//    
//  Serial.print("got:");
//  Serial.print(temp.length());
//  Serial.println(temp);
  
  // only do sensor stuff every minElapsed minutes
  if((long)(millis() - rolltime) >= 0)
  {    
    // read sensors
    bme.readSensor(); 
    sensors_event_t event;
    tsl.getEvent(&event);

    // set parmeters
    airP = (bme.getPressure_MB())*.10; //kPa
    humidity = bme.getHumidity();
    temperature = bme.getTemperature_C();
    light = event.light;

    // get NO2
    NO2_data = sensor1.getConc(1,temp1);
    if(NO2_data < 0)
    {
      NO2_data = 0;
    }

    // get CH4
    CH4 = analogRead(CH4_pin)/5.0;

    //get NH3
    NH3_data = analogRead(NH3);
    
    // save data
    saveData();

    // timekeeping
    rolltime += TIMERMIN;

    // status update
    digitalWrite(builtin_LED, HIGH);
    delay(500);
    digitalWrite(builtin_LED, LOW);
    delay(500);
    
    //indicate if we have found an issue
    if(error)
    {
      digitalWrite(builtin_LED, HIGH);
    }
  }

  // always do power management
  // when signal is low, AC pwr will be used
  voltage=ina219.getBusVoltage_V();
  //Serial.println(voltage);
  if (voltage<=10)
  {
    digitalWrite(relay, LOW); //SWAP THESE
  }
  if (voltage>=12)
  {
    digitalWrite(relay, HIGH); //SWAP THESE
  }
}

/*--------------------------------------------------------------------------------------
  Helper Functions
  --------------------------------------------------------------------------------------*/

// helper to program the MDOT if need be
void progMdot()
{
  char response;
 
  // see if the wireless module needs programmed
  starttime = millis();
  Serial1.write("AT\n");
  Serial1.flush();
  response = Serial1.read();

  while((response == -1) && millis() - starttime <= TIMEOUT)
  {
    delay(1);
    Serial1.write("AT\n");
    Serial1.flush();
    response = Serial1.read();
  }
  
  if(response != -1)
  {
    Serial.println("Connection successful");

    // configure Mdot to desired settings
    Serial1.write("AT+NJM=3\n"); // sets network join mode to peer to peer
    Serial1.write("AT+NA=00112233\n"); // sets network address
    Serial1.write("AT+NSK=00112233001122330011223300112233\n"); // sets network session key
    Serial1.write("AT+DSK=33221100332211003322110033221100\n"); // sets data session key
    Serial1.write("AT+TXDR=DR2\n"); // (0-6) sets the transmit data rate (AS 923) //TODO, adjust to get better range!
    Serial1.write("AT+TXF=920000000\n"); // sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range! 
    Serial1.write("AT+ACK=8\n"); // Turn on ACK
    Serial.println("dude2");
//    Serial1.write("AT&W\n"); // saves configuration 
//    Serial1.write("ATZ\n"); // resets CPU (takes 3 seconds) 
//    delay(4000); // delay for reset to take place
    Serial1.write("AT+SD\n"); // configures to send data (all data received is transmitted)
    
    Serial.println("mDot programming complete");
  }
  else
  {
    Serial.println("Error connecting to mDot");
    error = 1;
  }
}

// helper to get the time wirelessly and set it on the teensy
void getTime()
{
  // loop until handshake is complete, or timeout
  starttime = millis();

  //TODO, Caleb fix later!!
  while((year() < 2019) && (millis() - starttime <= TIMEOUT)) // guaranteed to work, year wont go back
  {
    Serial1.write("Time?\n");
    
//    while(Serial1.peek() == -1)
//    {   
//      temp = Serial1.readString();
//      Serial.println(temp);
//    }
    delay(100);
    temp = Serial1.readString();

    if (temp.length() > 0)
    {
      temp = temp.substring(0, temp.length() - 1);
    }
    
    Serial.print("got time:");
    Serial.print(temp.length());
    Serial.print("  ");
    Serial.println(temp);

    if(temp.length() == 19)
    {
      // get the time
      timeHold[0] = ((temp.substring(0,2)).toInt()); // Month
      timeHold[1] = ((temp.substring(3,5)).toInt()); // Day
      timeHold[2] = ((temp.substring(6,10)).toInt()); // Year
      timeHold[3] = ((temp.substring(11,13)).toInt()); // Hour
      timeHold[4] = ((temp.substring(14,16)).toInt()); // Minute
      timeHold[5] = ((temp.substring(17,19)).toInt()) + 2; // Second, has minor adjustment to account for transmission delay
  
      Serial.println("set time");
      // Sets all time info
      setTime(timeHold[3], timeHold[4], timeHold[5], timeHold[1], timeHold[0], timeHold[2]);
    }
  }
  //Serial.println("got it!");

  // if unsuccessful, use RTC
  // TODO, check!! Use File > Examples > Time > TimeTeensy3 
  if(year() < 2019)
  {
    Serial.println("Could not receive time wirelessly, defaulting to RTC");
    setSyncProvider(getTeensy3Time);
    if (timeStatus()!= timeSet) 
    {
      Serial.println("  Unable to sync with the RTC");
    }
    else 
    {
      Serial.println("  RTC has set the system time");
    }
  }
  
  Serial.print("Time set: ");
  Serial.println(digitalClock());  
}

// helper function to configure the SD reader and set the current time
void configSD()
{
  SdFile::dateTimeCallback(dateTime);
  if (!SD.begin(chipSelect)) 
  {
    Serial.println("SD initialization failed!");
    error = 1;
  }
  Serial.println("SD initialized");
}

// helper to both transmit the new measurements, and save locally
void saveData()
{
  bool first = false;
  
  // generate string from data
  String toSend = "";
  toSend += tran_number;
  toSend += ",";
  toSend += digitalClock();
  toSend += ",";
  toSend += temperature;
  toSend += ",";
  toSend += humidity;
  toSend += ",";
  toSend += airP;
  toSend += ",";
  toSend += light;
  toSend += ",";
  toSend += NO2_data;
  toSend += ",";
  toSend += CH4;
  toSend += ",";
  toSend += NH3_data;

  // write to serial
  Serial.println(toSend);
  
  // write to Wireless
  Serial1.println(toSend); // TODO, test verbosity, ACK's have been enabled
  Serial.print("Writing data to LoRa...");
  
  // write to SD
  // see if the file exists, if not, write header
  myFile = SD.open(file_string, FILE_READ);
  if (!myFile) 
  {
    first = true;
  }
  // write the data
  myFile = SD.open(file_string, FILE_WRITE);
  if (myFile) 
  {
    if (first)
    {
      Serial.print("Writing header to SD...");
      myFile.println(header);
    }
    
    Serial.print("Writing data to SD...");
    myFile.println(toSend);
  }
  else 
  {
    // if the file didn't open, print an error:
    Serial.print("Error writing data to SD card...");
    error = 1;
  }

  // close the file, yes this needs done each time, as this actually writes to the SD
  myFile.close();
  Serial.println("done.");
}

// helper to display the time nicely
String digitalClock() 
{
  String nowTime = "";
  
  nowTime += day();
  nowTime += "/";
  nowTime += month();
  nowTime += "/";
  nowTime += year(); 
  nowTime += " ";
  nowTime += hour();
  nowTime += ":";
  if(minute() < 10)
  {
    nowTime += "0";
  }
  nowTime += minute();
  nowTime += ":";
  if(second() < 10)
  {
    nowTime += "0";
  }
  nowTime += second();
  
  return nowTime;
}

// helper function to get the SD card date and time accurate
void dateTime(uint16_t* date, uint16_t* time)
{
  *date = FAT_DATE(year(), month(), day());
  *time = FAT_TIME(hour(), minute(), second());
}

// helper to get the RTC time
time_t getTeensy3Time()
{
  return Teensy3Clock.get();
}

unsigned long processSyncMessage() {
  unsigned long pctime = 0L;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013 

  if(Serial.find(TIME_HEADER)) {
     pctime = Serial.parseInt();
     return pctime;
     if( pctime < DEFAULT_TIME) { // check the value is a valid time (greater than Jan 1 2013)
       pctime = 0L; // return 0 to indicate that the time is not valid
     }
  }
  return pctime;
}
