#! /usr/bin/env python

#to run: python Pi_LoRa_Test.py

# follow this: https://www.elinux.org/Serial_port_programming
# enable serial port, and install python-serial


# program utilizes the serial port to talk to the Mdot, configuring it before setting it to listen for incomming messages
import serial # https://github.com/pyserial/pyserial
import time
import os
import csv
import threading

# make the port
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

def sendit():
    threading.Timer(30.0, sendit).start()
    os.system('/home/pi/Documents/ECE44x/Wireless/gdrive-linux-rpi upload --parent 1DXNoqiL6IrSj4Qq8Vzcjfm8o7wAowkwT /home/pi/Documents/ECE44x/Wireless/test.csv')
    print ("full send")

# test Mdot connection
response = ""
port.write("AT\n".encode()) #TODO, need newline?
time.sleep(3)
response = port.read(3)
print(response)
if response:
   print("Connection successful")
    
   # configure dot to desired settings
   port.write("AT+NJM=3\n".encode()) # sets network join mode to peer to peer
   port.write("AT+NA=00112233\n".encode()) # sets network address
   port.write("AT+NSK=00112233001122330011223300112233\n".encode()) # sets network session key
   port.write("AT+DSK=33221100332211003322110033221100\n".encode()) # sets data session key
   port.write("AT+TXDR=DR3\n".encode()) # sets the transmit data rate (AS 923) //TODO, adjust to get better range!
   port.write("AT+TXF=920000000\n".encode()) # sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range!
   port.write("AT+ACK=8\n".encode())
   port.write("AT&W\n".encode()) # saves configuration 
   port.write("ATZ\n".encode()) # resets CPU (takes 3 seconds) 
   time.sleep(4) # 3.1 second delay for reset to take place
   port.write("AT+SD\n".encode()) # configures to send data (all data received is transmitted)
   time.sleep(3) 
   
   print("Programming complete")    
else:
   print("Error connecting to Mdot")
   print("Is Mdot already in serial mode?")
   
# flush input
port.flushInput()
port.flushOutput()

fieldnames=['Date/time', 'Temp', 'Humidity', 'Air pressure', 'Lux', 'NO2', 'CH4']
with open('/home/pi/Documents/ECE44x/Wireless/fuck.csv', 'w') as csvfile:
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    print("attempting to write header")
    writer.writeheader()
    
    
   # sendit()
# infinite loop!
    while True:
    # Mdot is already configured, so can just start receiving in a loop with a delay, to see if sender is sending
        response = port.readline()
    
    # perform handshake and give teensy the time
        if response == "Transmitter1\n":
           print("hand shook with: " + response)
           port.write(time.strftime("%m/%e/%G %H:%M:%S"))
           port.write("\n")
    #test script below
    #response = "01/01/1997 06:30:23,10,14,19,70,0,60"
        if response:
            print("Received at " + time.strftime("%H:%M:%S")
                  + " --> " + response) # for debugging

        #parse data into array
            data = response.rstrip().split(",")
            print(data) # for debug
        
            #write data
            with open('/home/pi/Documents/ECE44x/Wireless/fuck.csv', 'a') as csvfile:
                print("lux: " + data[4])
            #writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
                if (len(data) > 0):
                    writer.writerow({fieldnames[0]: data[0], fieldnames[1]: data[1], fieldnames[2]: data[2],
                                    fieldnames[3]: data[3], fieldnames[4]: data[4], fieldnames[5]:data[5],
                                    fieldnames[6]: data[6]})
                    print("attempting to write row")
        #sendit()   
    
