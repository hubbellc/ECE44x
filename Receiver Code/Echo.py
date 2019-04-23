import serial
import time

port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

# infinite loop!
while True:
    word = raw_input()
    port.write(word.encode()) #TODO, work?
    while True:
        time.sleep(3)
        response = port.read()
        if response:
            print(ord(response))