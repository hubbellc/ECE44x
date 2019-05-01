/*
  ULP - Library for reading SPEC Sensors ULP.
  Created by David E. Peaslee, OCT 27, 2017.
  Released into the SPEC Sensors domain.
*/

/* The library is built to use several SPEC ULP sensors. An Arduino Uno can handle 3 sensors, since 2 analog pins are required for each sensor.
  Functions include getTemp(seconds, C/F): returns temperature, setTSpan(seconds, "HIGH"/"LOW"): for calibrating temperature, setVref(R1,R2,R3) for custom sensors,
  getVgas(seconds): for getting voltage of sensor, getConc(seconds, temperature in degC): for getting temperature corrected concentration,
  setXSpan(): for setting the calibration factor with known concentration of gas. Variable include _Vcc: the voltage ref of the ADC, _Vsup: the voltage to the ULP, 
  and _Gain the value of resistor R6. For more details see ULP.cpp in the libraries folder and the data sheet at http://www.spec-sensors.com/wp-content/uploads/2016/06/Analog-SDK-Users-Manual-v18.pdf
*/  

/* As an example, the ULP is connected this way: Vgas (pin1) to A0, Vtemp (Pin3) to A3, Gnd (Pin6) to Gnd, V+ (Pin7 or Pin8) to 3.3V of Arduino (must not be above 3.3V!!!).*/

#include "Arduino.h"
#include "ULP.h"

// These constants won't change.  They're used to give names to the pins used and to the sensitivity factors of the sensors:

const int C1 = A0;
const int T1 = A3;
//const int C2 = A1;
//const int T2 = A4;

const float Sf1 =-26.69; //nA/ppm


float temp1;
float TZero;
float Vzero1;


NO2 sensor1(C1, T1, Sf1);	//Sensor Types are EtoH, H2S, CO, IAQ, SO2, NO2, RESP, O3, and SPEC (custom)
 


void setup() {
  Serial.flush();
  Serial.begin(9600);    // initialize serial communications at 9600 bps:

 Vzero1 = sensor1.zero();   //.zero() sets and returns the baseline voltage at current temperature with only clean air present
 
  
 

}

void loop() {
  temp1 = sensor1.getTemp(1);//the  temp in celcius 
    
  Serial.print(temp1);
  Serial.print(", ");

float concern=sensor1.getConc(1,temp1); //gets the gas value

if (concern<0)
{concern =0;}

  //Use .getConc(1, temp1) where temp1 is in deg C for temperature corrected span
  Serial.print(", ");
  Serial.println(concern);

  delay(100);
}
