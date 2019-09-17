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

#new_file = False

global tran_number # shows not real transmitter
tran_number = 0

fieldnames=['Date/time', 'Temp', 'Humidity', 'Air pressure', 'Lux', 'NO2', 'CH4', 'NH3']

# make the port
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

def sendit():
    threading.Timer(60, sendit).start()
    print("file being uploaded: ")
    toOpen = "/home/pi/Documents/code/gdrive-linux-rpi sync upload --keep-largest /home/pi/Documents/Data 1iR74rrbEBQ9Su3WMTcZe_SJnLB6R-aWm"
    os.system(toOpen)
    print ("full send to drive")
   
    
# test Mdot connection
response = ""
port.write("AT\n".encode())
time.sleep(3)

# look for valid response
for i in range(3):
    #print(response)
    response = port.read(3)
#print ("this one:" + response[1:3])

if response[1:3] == "OK":
   print("Connection successful")
    
   # configure dot to desired settings
   port.write("AT+NJM=3\n".encode()) # sets network join mode to peer to peer
   port.write("AT+NA=00112233\n".encode()) # sets network address
   port.write("AT+NSK=00112233001122330011223300112233\n".encode()) # sets network session key
   port.write("AT+DSK=33221100332211003322110033221100\n".encode()) # sets data session key
   port.write("AT+TXDR=DR2\n".encode()) # sets the transmit data rate (AS 923) //TODO, adjust to get better range!
   port.write("AT+TXF=920000000\n".encode()) # sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range!
   port.write("AT+ACK=8\n".encode())
   
   # use to write settings to flash
   #port.write("AT&W\n".encode()) # saves configuration 
   #port.write("ATZ\n".encode()) # resets CPU (takes 3 seconds) 
   #time.sleep(4) # 3.1 second delay for reset to take place
   
   port.write("AT+SD\n".encode()) # configures to send data (all data received is transmitted)
   time.sleep(3) 
   
   print("Programming complete")    
else:
   print("Error contacting Mdot...Try power cycling!!")
   
# flush input
port.flushInput()
port.flushOutput()
    
sendit()

# infinite loop!
while True:
    # Mdot is already configured, so can just start receiving in a loop with a delay, to see if sender is sending
    response = port.readline().decode()
    #port.write(time.strftime("%m/%e/%G %H:%M:%S"))
    #port.write("\n")
    print(response)
    #port.write((time.strftime("%m/%e/%G %H:%M:%S")+ "\n").encode())
    
    #test script below
    #response = "01/01/1997 06:30:23,10,14,19,70,0,60"
    if response:
        print("Received at " + time.strftime("%H:%M:%S")
               + " --> " + response) # for debugging
        port.write((time.strftime("%m/%e/%G %H:%M:%S")+ "\n").encode())
        
        # perform handshake and give teensy the time
        if "Time?" in response:
            print("hand shook")
            #print("time:" + time.strftime("%m/%e/%G %H:%M:%S"))
            #port.write("hello\r\n".encode())
            #port.write(time.strftime("%m/%e/%G %H:%M:%S").encode())
            #port.write("09/14/2019 14:22:52\n".encode())
            #port.write((time.strftime("%m/%e/%G %H:%M:%S") + "\n").encode())
            time.sleep(3)
            #port.read()
            #print("done sending time")

        #parse data into array
        data = response.rstrip().split(",")
        print(data) # for debug
        
        # extract the tran number, and then dont care
        try:
            tran_number = int(data[0])
            del data[0]
        except:
            tran_number = 0 #this is bad data
        
        if (tran_number > 0 and tran_number < 11):
            #write data if it is valid
            if (len(data) > 5):
                toOpen = "/home/pi/Documents/Data/data"+str(tran_number)+".csv"
#                if(new_file == True):
#                    file = open(toOpen, 'w+')
#                    with file as csvfile:
#                        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
#                        print("New file...writing header")
#                        writer.writeheader()

                file_exists = True
                try:
                    file = open(toOpen, 'r')
                except:
                    file_exists = False
                    
                if (file_exists):
                    file = open(toOpen, 'a+')
                    with file as csvfile:
                        print("Saving Data")
                        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
                        writer.writerow({fieldnames[0]: data[0], fieldnames[1]: data[1], fieldnames[2]: data[2],
                                        fieldnames[3]: data[3], fieldnames[4]: data[4], fieldnames[5]:data[5],
                                        fieldnames[6]: data[6], fieldnames[7]: data[7]})
                else:
                    file = open(toOpen, 'w+')
                    with file as csvfile:
                        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
                        print("New file...writing header")
                        writer.writeheader()
                        print("Saving Data")
                        writer.writerow({fieldnames[0]: data[0], fieldnames[1]: data[1], fieldnames[2]: data[2],
                                        fieldnames[3]: data[3], fieldnames[4]: data[4], fieldnames[5]:data[5],
                                        fieldnames[6]: data[6], fieldnames[7]: data[7]})
                        
                file.close()
