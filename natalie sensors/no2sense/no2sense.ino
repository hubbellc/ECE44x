
#include "Arduino.h"

float Vref=analogRead(A1); //setting up analog pin for Vref
float VgasAN= A2; //analog pin for Vgas
float tempAN= A0; //pin for temp 
float Voff; //setting Voffset to equal -1
int Vcc= 5; // Vin is 5V
int sencon= 26.69; // Sensitity code found on device
int TIA= 499; //trans-impedance amplifier (TIA) found on data sheet https://media.digikey.com/pdf/Data%20Sheets/SPEC%20Sensors%20PDFs/968-047_8-25-17.pdf
float M= sencon*TIA*(10^-9)*(10^3); //Sensor calibaration factor. equation found on data sheet



float Vgas0; //Vgas in clean air also Vref

float getTmp(int x)

{
  unsigned long tme,i=0;
  unsigned long Avge;
  tme= millis()+x*1000;
  float temp;
  float tA;
  float Volt;
  do
  {
     Avge= analogRead(tempAN);
    delay(1);
    i++;
    }while(millis()>tme);

    tA=Avge/float(i);

    Volt= tA *Vcc/ 1024;
     temp = (87 / 3.3) * Volt - 18;
    return temp;
  }

//function to find the value of gas in clean air. used to calibrate and zero out the sensor
float zeroOut(int x)
{
  unsigned long tme,i=0; 
  unsigned long Vav;
  
 tme= millis()+x*1000;
  do// taking an average of Vref over input time
  {
     Vav= analogRead(VgasAN);
    delay(1);
    i++;
    
    }while(millis()<tme);

  float G0=Vav/float(i);
  float Vgas = G0 * Vcc;

  Voff=Vgas-Vref;
  Vgas0=Vref-Voff;
  return Vgas0;
  }

  //finds the value of concertion of NO2 in the air. takes an average of Vgas and then using the equation used in the data sheet
float getNO2(int x)
{
  float Vav;
  unsigned long tme,i=0,j=0;
  unsigned long Avge;

  tme= millis()+x*1000;

  do 
  {
    Avge=analogRead(VgasAN);
    delay(1);
    i++;
    }
  while(millis()<tme);

  float vAvg=float(Avge)/float(i);

  float Vgas = vAvg * Vcc  ;
 
  float Conc= (Vgas-Vgas0)*float(1/M);
  
  return Conc;
  }

void setup()
{
  Serial.flush();
   Serial.begin(9600);
  
  
 // Vgas0=zeroOut(10);
  //Vgas0=3.3;
  }


void loop()
{
  Serial.print("Concentraion of NO2: ");
  Serial.println(getNO2(10));
  Serial.print (" Temp in Celsious: ");
  Serial.println(getTmp(10));
  delay(2000);
  
  
  }

  
