

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
#include <Adafruit_INA219.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include <Adafruit_AM2315.h>
//#include "ULP.h"

/*--------------------------------------------------------------------------------------
  Definitions
  --------------------------------------------------------------------------------------*/
// pins used
#define Relay1 34
#define builtin_LED 13
#define tempAN A19
#define VrefAN A18
#define VgasAN A14

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
#define MINELAPSED .25 // <<------------------- set frequency for reading sensors here!!
#define LOOPTIME .25 // 30 seconds to try
#define TIMERMIN (1000UL * 60 * MINELAPSED)
#define TIMEOUT (1000UL * 60 * LOOPTIME)
unsigned long rolltime = millis() + TIMERMIN;
unsigned long starttime = millis();

// for datakeeping
const String header = "Date,Temperature,Humidity,Air Pressure,Lux,NO2,CH4";
int temperature = 12;
int humidity = 34;
int airP = 56;
int light = 78; //TODO, Samir needs to write the framework still
int NO2_data = 91;
int CH4 = 23; //TODO, Samir needs to write the framework still

// for power
int val1=1;
float voltage;
Adafruit_INA219 ina219;

// for BME sensor
BME280_I2C bme(0x76); // I2C using address 0x76
//for am2315 (temp/hum)
Adafruit_AM2315 am2315;
// for lux sensor
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

// for NO2 sensor
float Voff=.5;
int Vcc= 3.3;
int sencon= 26.69;
int TIA= 499;
float M= 26.69*499*(10^-9)*(10^3);
float Vgas0 = 0;
float Vgas = 0;
float Conc = 0;
unsigned long tme=0,i=0,j=0;
unsigned long Avge=0;
unsigned long vAvg=0;
int G0 = 0;
//NO2 sensor1(tempAN, VgasAN, sencon);

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
  pinMode(Relay1, OUTPUT);
  ina219.begin();
  ina219.setCalibration_16V_400mA();
  if(!ina219.getBusVoltage_V()) // TODO, how know if fail??
  {
    Serial.println("Could not find a valid current sensor, check wiring!"); 
    error = 1;
  }

  // for sensing
  starttime = millis();
  while(!bme.begin() && millis() - starttime <= TIMEOUT){}
  if(!bme.begin())
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    error = 1;
  }

  Vgas0=zeroOut(10); //Call helper function which takes mean of gas

  //Lux setup:
  tsl.enableAutoRange(true);  
  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */ 
  /* Initialise the sensor */
  //use tsl.begin() to default to Wire, 
  //tsl.begin(&Wire2) directs api to use Wire2, etc.

  starttime = millis();
  while(!tsl.begin() && millis() - starttime <= TIMEOUT){}
  if(!tsl.begin())
  {
    Serial.println("Could not find a valid light sensor, check wiring!");
    error = 1;
  }
  
  delay(3000); // 3 second delay ...TODO, refine

  // program the Mdot
  progMdot();
  
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
  //getTime();
//Serial.println("time made it");
  // configure SD card
  configSD(); // needs to be after time, uses time to init!
Serial.println("SD made it");
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
}

void loop() 
{
  // only do sensor stuff every minElapsed minutes
  if((long)(millis() - rolltime) >= 0)
  {    
    // get measurements
    bme.readSensor(); 
    airP = bme.getPressure_MB();
    //humidity = bme.getHumidity();
//    temperature = sensor1.getTemp(1,"F");
    NO2_data = getNO2(10);
    humidity=am2315.readHumidity();
    temperature=am2315.readTemperature();
    sensors_event_t event;
    tsl.getEvent(&event);
    if (event.light)
    {
       light = event.light;
       //Serial.print(event.light); Serial.println(" lux");
    }
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
  voltage=ina219.getBusVoltage_V();
  if (voltage<=5)
  {
    val1 = 1;
    digitalWrite(Relay1, LOW);
  }
  if (voltage>=15)
  {
    val1=0;
    digitalWrite(Relay1, HIGH);
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
    Serial1.write("AT+ACK=8\n"); // turn on ACK, and set to max retries
    Serial1.write("AT+TXDR=DR3\n"); // sets the transmit data rate (AS 923) //TODO, adjust to get better range!
    Serial1.write("AT+TXF=920000000\n"); // sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range! 
    Serial1.write("AT&W\n"); // saves configuration 
    Serial1.write("ATZ\n"); // resets CPU (takes 3 seconds) 
    delay(3000); // 3 second delay for reset to take place
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
  
  while((year() < 2019) && (millis() - starttime <= (TIMEOUT * 2))) // guaranteed to work, year wont go back
  {
    delay(300);
    Serial1.write("Transmitter1\n");
    temp = Serial1.readString();
    
    // get the time
    timeHold[0] = ((temp.substring(0,2)).toInt()); // Month
    timeHold[1] = ((temp.substring(3,5)).toInt()); // Day
    timeHold[2] = ((temp.substring(6,10)).toInt()); // Year
    timeHold[3] = ((temp.substring(11,13)).toInt()); // Hour
    timeHold[4] = ((temp.substring(14,16)).toInt()); // Minute
    timeHold[5] = ((temp.substring(17,19)).toInt()) + 2; // Second, has minor adjustment to account for transmission delay
    
    // Sets all time info
    setTime(timeHold[3], timeHold[4], timeHold[5], timeHold[1], timeHold[0], timeHold[2]);
  }

  // if unsuccessful, use RTC
  // TODO, check!! Use File > Examples > Time > TimeTeensy3 
  if(year() < 2019)
  {
    Serial.println("Could not receive time wirelessly, defaulting to RTC");
    setSyncProvider(getTeensy3Time);

    //operating under the assumption that time will have been gotten from PC
    /*time_t t = ??;
    Teensy3Clock.set(t); // set the RTC
    setTime(t);*/
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
  toSend += digitalClock();
  toSend += ",";
  toSend += temperature;
  toSend += ",";
  toSend += humidity;
  toSend += ",";
  toSend += 20;
  toSend += ",";
  toSend += light;
  toSend += ",";
  toSend += NO2_data;
  toSend += ",";
  toSend += CH4;

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
  
  nowTime += month();
  nowTime += "/";
  nowTime += day();
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

// TODO, samir?? Does something to get gas
float zeroOut(int x)
{
  i=0;
  
  tme= millis()+x*1000;
  
  do
  {
    Vgas0= analogRead(VrefAN)- Voff;
    delay(1);
    i++;
    
  }
  while(millis()<tme);

  G0 = Vgas0/i;
    
  return G0;
}

// TODO, samir?? Does something to get gas
float getNO2(int x)
{
  i=0;
  j=0;

  tme= millis()+x*1000;

  do
  {
    Avge=Avge+analogRead(VgasAN);
    delay(1);
    i++;
  }
  while(millis()<tme);

  vAvg = Avge/i;

  Vgas = vAvg * 5 * 1000.0 / 1024.0;
  
  Conc = 1/M*(Vgas-Vgas0);

  return Conc;
}
