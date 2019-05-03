#include <Wire.h> 
#include "cactus_io_BME280_I2C.h" 

// Create BME280 object 
BME280_I2C bme(0x76); // I2C using address 0x77 
// or BME280_I2C bme(0x76); // I2C using address 0x76 
float Hum;
float pres;
float temp;
void setup() { 
Serial.begin(9600); 
delay(300);

Serial.println("here");
while (!bme.begin()) { 
Serial.println("Could not find a valid BME280 sensor, check wiring!"); 


} 

bme.setTempCal(-2);// Temp was reading high so subtract 1 degree 
Serial.println("Found it!");
 
} 

void loop() { 
Serial.println("work");
bme.readSensor(); 
temp = bme.getTemperature_F();
pres=(bme.getPressure_MB())*.10;
Hum=bme.getHumidity()+5;
Serial.print("The Air pressure is: ");
Serial.print(pres); Serial.println(" kPa\t");
Serial.print("The Humidity is (%): ");Serial.print(Hum); Serial.println(" %\t\t"); 
Serial.print("The Temp is (F): ");Serial.println(temp); 

// Add a 2 second delay. 
delay(2000); //just here to slow down the output. 
}
