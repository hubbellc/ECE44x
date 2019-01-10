// program utilizes two serial ports, one to program/talk back
//   and one to talk to the Mdot
//   will relay all mdot command reponses back to the computer
//   and attempt to send to base mdot.


/*--------------------------------------------------------------------------------------
  Includes
  --------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------
  Definitions
  --------------------------------------------------------------------------------------*/
int count = 0;


void setup() 
{
  char response;
  
  // begin comm to computer for responses (USB)
  Serial.begin(115200);

  // begin comm to Mdot (port 0 and 1)
  Serial1.begin(115200);

  delay(3000); // 3 second delay

  // test Mdot connection
  // TODO, its a hack, but it worked!
  Serial1.write("AT\n");
  Serial1.flush();
  response = Serial1.read();
  Serial.println(response);
  if(response != -1)
  {
    Serial.println("Connection successful");

    // configure Mdot to desired settings
    // TODO, what is terminator?? Assuming println will work
    // TODO, need to read each time? Try this, than try commenting all but response out
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
    

    Serial.println("Programming complete");
  }
  else
  {
    Serial.println("Error connecting to Mdot");
  }

  delay(3000);
  Serial1.flush();
  Serial.flush();
}

void loop() 
{
  // Mdot is already configured, so can just start sending in a loop with a delay, to see if receiver will pick it up
  Serial1.write("\nHello World");
  Serial1.write(count);
  count = count + 1;
  /*if(Serial1.peek() != -1)
  {
    Serial.write(Serial1.read());
  }*/
  delay(3000); // 3 second delay
}
