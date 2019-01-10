#! /usr/bin/env python

#to run: python Pi_Echo.py

# follow this: https://www.elinux.org/Serial_port_programming, http://embeddedlaboratory.blogspot.com/2017/03/serial-communication-in-raspberry-pi.html
# use the good UART: https://spellfoundry.com/2016/05/29/configuring-gpio-serial-port-raspbian-jessie-including-pi-3/
# enable serial port, and install python-serial


# program utilizes the serial port to talk to the Mdot, configuring it before setting it to listen for incomming messages
import serial # https://github.com/pyserial/pyserial
import time

# make the port
port = serial.Serial("/dev/ttyAMA0", baudrate=115200, timeout=3.0)

# infinite loop!
while True:
   port.write(input().encode()) #TODO, work?
   response = port.read(3)
   print(response)
    
    
    