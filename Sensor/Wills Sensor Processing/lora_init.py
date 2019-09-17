#!/usr/bin/python

import time
import serial
import RPi.GPIO as GPIO 

TIMEOUT = 30

# assign serial port for LoRa module
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

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
    port.write("AT+TXDR=DR0\n".encode()) # sets the transmit data rate (AS 923) //TODO, adjust to get better range!
    port.write("AT+TXF=921000000\n".encode()) # sets the transmit frequency (920000000 - 928000000) //TODO, adjust to get better range!
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
time.sleep(1)

getTime()

def getTime():
    # loop until handshake is complete, or timeout
    starttime = timer()

    os.system('sudo timedatectl set-ntp false') # turn off internet sync

    #TODO, Caleb fix later!!
    while((year() < 2019) and (timer() - starttime <= (TIMEOUT))): # guaranteed to work, year wont go back

        port.write("Time?\n".encode())
        time.sleep(1)
        temp = port.readline().decode()

        if (len(temp) > 0):
            temp = temp[:-1]

        print("got time:" + len(temp) + " " + temp)
        #print(temp.length())
        #print("  ")
        #print(temp)

        if(len(temp) == 19):
            # extract the time
            month = int(temp[0:2])
            day = int(temp[3:5]) 
            year = int(temp[6:10])
            hour = int(temp[11:13])
            minute = int(temp[14:16])
            second = int(temp[17:19]) + 2 # has minor adjustment to account for transmission delay

            print("set time")

            # Sets all time info
            ct = datetime(year=year, month=month, day=day, hour=hour, minute=minute, second=second)
            print(ct)
            os.system('sudo timedatectl set-time %s' % ct.strftime('%Y-%m-%d %H:%M:%S'))	  
            print("got it!")

    if(year < 2019):
        print("Could not receive time wirelessly")
        os.system('sudo timedatectl set-ntp true') # just go with the system clock


    print("Time set: ")
    print(time.strftime("%m/%e/%G %H:%M:%S"))

