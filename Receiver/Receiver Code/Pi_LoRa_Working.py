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
import datetime
import copy

global tran_number
global writer
global csvfile
global fieldnames
global data
global toOpen
global file_exists
global file


tran_number = 0  #shows not real transmitter

fieldnames=['Date/time', 'Temp', 'Humidity', 'Air pressure', 'Lux', 'NO2', 'CH4', 'NH3']
last_data = []

# make the port
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

def sendit():
    global toOpen
    threading.Timer((30 * 60), sendit).start()
    print("file being uploaded: ")
    toOpen = "/home/pi/Documents/code/gdrive-linux-rpi sync upload --keep-local /home/pi/Documents/Data 1L64c2_xVbF6h7E_f_MyjHyAoZmkn_PQ0 "
    os.system(toOpen)
    print ("full send to drive")
    
def writeIt():
    global writer, csvfile, fieldnames, data
    print("Saving Data")
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writerow({fieldnames[0]: data[0], fieldnames[1]: data[1], fieldnames[2]: data[2],
                    fieldnames[3]: data[3], fieldnames[4]: data[4], fieldnames[5]:data[5],
                    fieldnames[6]: data[6], fieldnames[7]: data[7]})
    
def saveIt():
    global toOpen, file, file_exists, file, writer, csvfile, fieldnames
    toOpen = "/home/pi/Documents/Data/data"+str(tran_number)+".csv"
    file_exists = True
    try:
        file = open(toOpen, 'r')
    except:
        file_exists = False
        
    if (file_exists):
        file = open(toOpen, 'a+')
        with file as csvfile:
            writeIt()
    else:
        file = open(toOpen, 'w+')
        with file as csvfile:
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            print("New file...writing header")
            writer.writeheader()
            writeIt()
            
    file.close()
   
    
# test Mdot connection
response = ""
port.write("AT\n".encode())
time.sleep(3)

# look for valid response
for i in range(3):
    response = port.read(3)

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
    if response:
        response = response.rstrip()
        print("Received at " + time.strftime("%H:%M:%S")
               + " --> " + response) # for debugging
        
        # respond with the current time
        port.write((time.strftime("%m/%e/%G %H:%M:%S")+ "\n"))
        
        # perform handshake and give teensy the time
        if "Time?" in response:
            print("hand shook")
            time.sleep(5)

        #parse data into array
        data = response.split(",")
        #print(data) # for debug
        
        #fix the time if it is
        if (len(data) > 2):
            received_time_string = data[1]
            if(len(received_time_string) == 19):
                # extract the time
                received_time = time.strptime(received_time_string, "%d/%m/%Y %H:%M:%S")
                #print("time received: " + time.strftime("%m/%e/%G %H:%M:%S", received_time))
                #print("pi time: " + time.strftime("%e/%m/%G %H:%M:%S"))
                now = datetime.datetime.now()
                
                if (received_time.tm_year != now.year or received_time.tm_mon != now.month or received_time.tm_mday != now.day
                    or (received_time.tm_hour < now.hour - 3) or (received_time.tm_hour > now.hour + 3)):
                    print("time invalid, defaulting to receiver timestamp")
                    data[1] = time.strftime("%e/%m/%G %H:%M:%S")
        
        # extract the tran number, and then dont care
        try:
            tran_number = int(data[0])
        except:
            tran_number = 0 #this is bad data
        
        print(data)
        #write data if it is valid
        if (len(data) == 9 and tran_number > 0 and tran_number < 11):
            del data[0]
            saveIt()
        else:
            # try and use old data
            last_last_data = copy.deepcopy(last_data)
            last_data = copy.deepcopy(data)
            data.extend(last_last_data)
            print("Merged data: " + str(data))
            
            #work?
            if (len(data) == 9 and tran_number > 0 and tran_number < 11):
                del data[0]
                saveIt()
