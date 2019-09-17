// Program Illuminates onboard LED as long as it is receiving a signal from the mothership
//  Use to test wireless range, or basic wireless settings


/*--------------------------------------------------------------------------------------
  Includes
  --------------------------------------------------------------------------------------*/


/*--------------------------------------------------------------------------------------
  Definitions
  --------------------------------------------------------------------------------------*/
int count = 0;
String temp = "";
int x,y,z;
char * idx;


void setup() 
{
  char response;

  //for LED
  pinMode(13, OUTPUT);
  
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
    Serial1.write("AT+ACK=8\n");
//    Serial1.write("AT&W\n"); // saves configuration 
//    Serial1.write("ATZ\n"); // resets CPU (takes 3 seconds) 
//    delay(4000); // delay for reset to take place
    Serial1.write("AT+SD\n"); // configures to send data (all data received is transmitted)

    Serial.println("Programming complete");
  }
  else
  {
    Serial.println("Error connecting to Mdot");
  }

  delay(3000);
  // clear input buffers
  while (Serial.available() > 0 ) {
    Serial.read();
  }
  while (Serial1.available() > 0 ) {
    Serial1.read();
  }
  Serial1.flush();
  Serial.flush();

  // shake hand
  delay(1000); 
  Serial1.write("Transmitter1\n");

  //flash to know on
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}

void loop() 
{
  // Mdot is already configured, so can just start sending in a loop with a delay, to see if receiver will pick it up
  if(Serial1.peek() != -1)
  {   
    temp = Serial1.readString();
    Serial.print("Received: ");
    Serial.println(temp);
    //Serial1.println(temp);
    digitalWrite(13, HIGH);
    delay(500);
    Serial1.println("Time?\n");
  }
  else
  {
    digitalWrite(13, LOW);
  }
}
