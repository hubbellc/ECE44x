#! /usr/bin/env python
#(Forces to use Python 2)

#to run: python Pi_Echo.py

# follow this: https://www.elinux.org/Serial_port_programming,           ttp://embeddedlaboratory.blogspot.com/2017/03/serial-communication-in-raspberry-pi.html
# use the good UART: https://spellfoundry.com/2016/05/29/configuring-gpio-serial-port-raspbian-jessie-including-pi-3/
# enable serial port, and install python-serial


# program utilizes the serial port to talk to the Mdot, configuring it before setting it to listen for incomming messages
import serial # https://github.com/pyserial/pyserial
import time
import sys

# make the port
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=30.0)
port.close()
port.open()

# infinite loop!
while True:
    word = raw_input()
    port.write(word.encode()) #TODO, work?
    time.sleep(3)
    response = port.read(size=300)
    print(response)
    
    
    