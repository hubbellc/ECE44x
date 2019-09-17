#! /usr/bin/env python

# to run: python Pi_LoRa_Test.py

# follow this: https://www.elinux.org/Serial_port_programming
# enable serial port, and install python-serial


# program utilizes the serial port to talk to the Mdot, configuring it before setting it to listen for incomming messages
import serial # https://github.com/pyserial/pyserial
import time

# make the port
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

# test Mdot connection
response = ""
port.write("AT\n".encode()) #TODO, need newline?
time.sleep(3)
response = port.read(3)
print(response)
if response:
   print("Connection successful")
    
   # configure Mdot to desired settings
   # TODO, what is terminator?? Assuming println will work
   # TODO, need to read each time? Try this, than try commenting all but response out
   port.write("AT+NJM=3\n".encode()) # sets network join mode to peer to peer
   port.write("AT+NA=00112233\n".encode()) # sets network address
   port.write("AT+NSK=00112233001122330011223300112233\n".encode()) # sets network session key
   port.write("AT+DSK=33221100332211003322110033221100\n".encode()) # sets data session key
   #port.write("AT+ACK=8\n".encode()) # turn on ACK, and set to max retries
   port.write("AT+TXDR=DR3\n".encode()) # sets the transmit data rate (AS 923) //TODO, adjust to get better range!
   port.write("AT+TXF=920000000\n".encode()) # sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range! 
#   port.write("AT&W\n".encode()) # saves configuration 
#   port.write("ATZ\n".encode()) # resets CPU (takes 3 seconds) 
#   time.sleep(4) # 3.1 second delay for reset to take place
   port.write("AT+SD\n".encode()) # configures to send data (all data received is transmitted)
   time.sleep(4) 
   
   print("Programming complete")    
else:
   print("Error connecting to Mdot")
   
# flush input
port.flushInput()
port.flushOutput()

# infinite loop!
while True:
    # Mdot is already configured, so can just start receiving in a loop with a delay, to see if sender is sending
    #response = port.readline()
    #if response:
       #print(response)
       #TODO, spits out garbage, but works!
    
    #Now configure to send time
    print(time.strftime("%H:%M:%S"))
    port.write(time.strftime("%H:%M:%S").encode())
    port.write("\n".encode())
    #port.write((time.strftime("%m/%e/%G %H:%M:%S") + "\n").encode())
    time.sleep(3)    
       
    response = port.readline() #TODO, only will work if newline seperated
    print(response)
    
    
    