#include <Wire.h> 
#include "cactus_io_BME280_I2C.h" 

// Create BME280 object 
BME280_I2C bme(0x76); // I2C using address 0x77 
// or BME280_I2C bme(0x76); // I2C using address 0x76 
int Hum;
int pres;
void setup() { 

Serial.begin(9600); 


if (!bme.begin()) { 
Serial.println("Could not find a valid BME280 sensor, check wiring!"); 
while (1); 


} 

//bme.setTempCal();// Temp was reading high so subtract 1 degree 

 
} 

void loop() { 
Serial.println("work");
bme.readSensor(); 
pres=(bme.getPressure_MB()-7)/33.864;
Hum=bme.getHumidity()+5;
Serial.print("The Air pressure is: ");
Serial.print(pres); Serial.println(" Hg\t"); // Pressure in millibars 
Serial.print("The Humidity is: ");Serial.print(Hum); Serial.println(" %\t\t"); 
; 

// Add a 2 second delay. 
delay(10000); //just here to slow down the output. 
}
