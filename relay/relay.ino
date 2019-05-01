// Sandbox code to test the functionality of the intellegent power source logic

#include <Adafruit_INA219.h>
#include <Wire.h>

int Relay1 =7;
int val1=1;
Adafruit_INA219 ina219;

void setup() {
  
 Serial.begin(115200);
 ina219.begin();
 ina219.setCalibration_16V_400mA();

  pinMode(Relay1, OUTPUT);
  digitalWrite(Relay1, val1);
}

void loop() {

  //float voltage= 0;
  float  voltage=ina219.getBusVoltage_V();

  Serial.println("voltage: ");
  Serial.println(voltage);
delay(200);

if (voltage<=5)
{
  val1 = 1;

    digitalWrite(Relay1, HIGH);
  }
if (voltage>=15)
{
  val1=0;

  digitalWrite(Relay1, LOW);
  }
else{
  return;
  }
}
