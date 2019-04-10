// program utilizes two serial ports, one to program/talk back
//   and one to talk to the Mdot
//   will relay all mdot command reponses back to the computer
//   and attempt to send to base mdot.


/*--------------------------------------------------------------------------------------
  Includes
  --------------------------------------------------------------------------------------*/
#include <TimeLib.h>
#include <SD.h>
#include <SPI.h>
#include <Wire.h> 
#include "cactus_io_BME280_I2C.h" 

/*--------------------------------------------------------------------------------------
  Definitions
  --------------------------------------------------------------------------------------*/
// general
String temp = "";

// for timekeeping
long int timeHold[6];

// for SD card
File myFile;
const int chipSelect = BUILTIN_SDCARD;
// NOTE: name cannot include a "_"...plaintext only
//TODO, test to make sure > 24hrs
const char * file_string = "raitong.csv"; // <<------------------- set file here!!

// for timekeeping
#define MINELAPSED .2 // <<------------------- set timer here!!
#define TIMERMIN (1000UL * 60 * MINELAPSED)
unsigned long rolltime = millis() + TIMERMIN;

// for datakeeping
const String header = "Date,Temperature,Humidity,Air Pressure,Lux,NO2,CH4";
int temperature = 12;
int humidity = 34;
int airP = 56;
int light = 78;
int NO2 = 91;
int CH4 = 23;

// for sensing
BME280_I2C bme(0x76); // I2C using address 0x76

void setup() 
{
  // begin comm to computer for responses (USB)
  Serial.begin(115200);

  // begin comm to Mdot (port 0 and 1)
  Serial1.begin(115200);

  //for LED
  pinMode(13, OUTPUT);

  //for analog
  pinMode(A14, INPUT);

  // for sensing
  //if (!bme.begin()) { 
  //Serial.println("Could not find a valid BME280 sensor, check wiring!"); 
  //while (1); 
  //} 

  delay(3000); // 3 second delay

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
  delay(300);

  // get the current time
  getTime(); //TODO, bring back!

  // configure SD card .. needs to be after time, uses time to init!
  configSD();

  //flash to know on
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  
  Serial.println("---------------------beginning main loop--------------------");
}

void loop() 
{
  // only do stuff every minElapsed minutes
  if((long)(millis() - rolltime) >= 0)
  {    
    // get measurements
    //bme.readSensor(); 
    //airP = bme.getPressure_MB();
    //humidity = bme.getHumidity();
    //temperature = bme.getTemperature_C();
    NO2 = analogRead(A14);
    
    // save data
    saveData();

    // timekeeping
    rolltime += TIMERMIN;
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
  Serial1.write("AT\n");
  Serial1.flush();
  response = Serial1.read();
  if(response != -1)
  {
    Serial.println("Connection successful");

    // configure Mdot to desired settings
    Serial1.write("AT+NJM=3\n"); // sets network join mode to peer to peer
    Serial1.write("AT+NA=00112233\n"); // sets network address
    Serial1.write("AT+NSK=00112233001122330011223300112233\n"); // sets network session key
    Serial1.write("AT+DSK=33221100332211003322110033221100\n"); // sets data session key
    Serial1.write("AT+TXDR=DR3\n"); // sets the transmit data rate (AS 923) //TODO, adjust to get better range!
    Serial1.write("AT+TXF=920000000\n"); // sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range! 
    Serial1.write("AT&W\n"); // saves configuration 
    Serial1.write("ATZ\n"); // resets CPU (takes 3 seconds) 
    delay(4000); // 3.1 second delay for reset to take place
    Serial1.write("AT+SD\n"); // configures to send data (all data received is transmitted)
    
    Serial.println("mDot programming complete");
  }
  else
  {
    Serial.println("Error connecting to mDot");
  }
}

// helper to get the time wirelessly and set it on the teensy
void getTime()
{
  // loop until handshake is complete
  while(year() < 2019) // guaranteed to work, year wont go back
  {
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
  
  Serial.print("Time set: ");
  Serial.println(digitalClock());  
}

// helper function to configure the SD reader and set the current time
void configSD()
{
  SdFile::dateTimeCallback(dateTime);
  if (!SD.begin(chipSelect)) {
    Serial.println("SD initialization failed!");
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
  toSend += airP;
  toSend += ",";
  toSend += light;
  toSend += ",";
  toSend += NO2;
  toSend += ",";
  toSend += CH4;

  // write to serial
  Serial.println(toSend); //TODO, remove
  
  // write to PI
  //TODO, if lots of missed transmissions, do a while loop or ACK
  Serial1.println(toSend);
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
    //TODO, maybe put this in loop until it works??
    Serial.print("Error writing data to SD card...");
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
