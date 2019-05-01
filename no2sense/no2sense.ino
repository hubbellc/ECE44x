// Sandbox code to test the NO2 sensor

#include "Arduino.h"

float VrefAN= A1;
float VgasAN= A2;
float tempAN= A0;
float Voff=.5;
int Vcc= 3.3;
int sencon= 26.69;
int TIA= 499;
float M= 26.69*499*(10^-9)*(10^3);



float Vgas0;


void setup()
{
   Serial.begin(9600);
  
  
  Vgas0=zeroOut(10);
  
  }


void loop()
{

  Serial.println(getNO2(10));

  delay(200);
  
  
  }

  
float zeroOut(int x)
{
  unsigned long tme,i=0;
  unsigned long Avge;
 tme= millis()+x*1000;
  do
  {
    float Vgas0= analogRead(VrefAN)- Voff;
    delay(1);
    i++;
    
    }while(millis()<tme);

  int G0=Vgas0/i;
    
  return G0;
  }
float getNO2(int x)
{
  unsigned long tme,i=0,j=0;
  unsigned long Avge;

  tme= millis()+x*1000;

  do
  {
    Avge=Avge+analogRead(VgasAN);
    delay(1);
    i++;
    }
  while(millis()<tme);

  float vAvg=Avge/i;

  float Vgas = vAvg * 5 * 1000.0 / 1024.0;
  
  float Conc= 1/M*(Vgas-Vgas0);

  return Conc;
  }
