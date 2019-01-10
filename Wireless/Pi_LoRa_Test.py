#! /usr/bin/env python

#to run: python Pi_LoRa_Test.py

# follow this: https://www.elinux.org/Serial_port_programming
# enable serial port, and install python-serial


# program utilizes the serial port to talk to the Mdot, configuring it before setting it to listen for incomming messages
import serial # https://github.com/pyserial/pyserial
import time

# make the port
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

# test Mdot connection
port.write("AT".encode()) #TODO, need newline?
response = port.read(3)
print(response)
if reponse == 'OK':
   print("Connection successful")
    
   # configure Mdot to desired settings
   # TODO, what is terminator?? Assuming println will work
   # TODO, need to read each time? Try this, than try commenting all but response out
   port.write("AT+NJM=3".encode()); # sets network join mode to peer to peer
   port.write("AT+NA=00112233".encode()); # sets network address
   port.write("AT+NSK=00112233001122330011223300112233".encode()); # sets network session key
   port.write("AT+DSK=33221100332211003322110033221100".encode()); # sets data session key
   port.write("AT+TXDR=DR3".encode()); # sets the transmit data rate (AS 923) //TODO, adjust to get better range!
   port.write("AT+TXF=920000000".encode()); # sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range! 
   port.write("AT&W".encode()); # saves configuration 
   port.write("ATZ".encode()); # resets CPU (takes 3 seconds) 
   time.sleep(3.1); # 3.1 second delay for reset to take place
   port.write("AT+SD".encode()); # configures to send data (all data received is transmitted)
   
   Serial.println("Programming complete")    
else:
   print("Error connecting to Mdot")

# infinite loop!
while True:
   # Mdot is already configured, so can just start receiving in a loop with a delay, to see if sender is sending
   response = port.read(12) # limits read to 12 characters
   print(response)
   #response = port.readline() #TODO, only will work if newline seperated
    
    
    