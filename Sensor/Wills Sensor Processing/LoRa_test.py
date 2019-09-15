#!/usr/bin/python

import time
import serial
port = serial.Serial("/dev/ttyS0", baudrate=1200)
cnt = 0
while(True):

	port.write(bytes("AT+RX"))
	#port.write(bytes("0,1,2,3,4,5,6"))
	print(cnt)
	cnt = cnt + 1
	time.sleep(3)

	if (port.in_waiting):
		print("output: ")
		x = port.readline()
		print(x)
	time.sleep(2)

