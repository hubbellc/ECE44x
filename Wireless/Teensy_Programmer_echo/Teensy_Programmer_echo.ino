// program utilizes two serial ports, one to program/talk back
//   and one to talk to the Mdot
//   will relay all serial received commands to mdot, and vice-versa


/*--------------------------------------------------------------------------------------
  Includes
  --------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------
  Definitions
  --------------------------------------------------------------------------------------*/
/*USES:
AT&V = Status update, check if programming worked (it did)
*/

void setup() 
{
  int response;
  
  // begin comm to computer for responses (USB)
  Serial.begin(115200);

  // begin comm to Mdot (port 0 and 1)
  Serial1.begin(115200);
}

void loop() 
{
  if (Serial.available()) Serial1.write(Serial.read());
  if (Serial1.available()) Serial.write(Serial1.read());
}
