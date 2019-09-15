#!/bin/bash

import time
import serial
import RPi.GPIO as GPIO 

GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.OUT)
GPIO.output(24, 0)
time.sleep(1)
port = serial.Serial("/dev/ttyS0", baudrate=9600)
port.write(bytes("AT+B1200"))
GPIO.output(24, 1)

