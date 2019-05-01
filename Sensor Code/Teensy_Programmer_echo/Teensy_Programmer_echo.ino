// program utilizes two serial ports, one to program/talk back
//   and one to talk to the Mdot
//   will relay all serial received commands to mdot, and vice-versa

//   Use to write single commands to Mdot/ check connection


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
  //int response;
  
  // begin comm to computer for responses (USB)
  Serial.begin(115200);

  // begin comm to Mdot (port 0 and 1)
  Serial1.begin(115200);

//  Serial1.write("ATZ\n");
//  delay(4000);
//  Serial1.write("AT+NJM=3\n"); // sets network join mode to peer to peer
//  Serial1.write("AT+NA=00112233\n"); // sets network address
//  Serial1.write("AT+NSK=00112233001122330011223300112233\n"); // sets network session key
//  Serial1.write("AT+DSK=33221100332211003322110033221100\n"); // sets data session key
//  Serial1.write("AT+ACK=8\n"); // turn on ACK, and set to max retries
//  Serial1.write("AT+TXDR=DR3\n"); // sets the transmit data rate (AS 923) //TODO, adjust to get better range!
//  Serial1.write("AT+TXF=920000000\n"); // sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range! 
}

void loop() 
{
  if (Serial.available()) Serial1.write(Serial.read());
  if (Serial1.available()) Serial.write(Serial1.read());
}
