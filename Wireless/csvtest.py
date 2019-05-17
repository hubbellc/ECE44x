import serial # https://github.com/pyserial/pyserial
import time
import os
import csv
import threading

response = "01/01/1997 06:30:23,10,14,19,70,0,60"
data = response.rstrip().split(",")
fieldnames=['Date/time', 'Temp', 'Humidity', 'Air pressure', 'Lux', 'NO2', 'CH4']
with open('/home/pi/Documents/ECE44x/Wireless/test.csv', 'w') as csvfile:
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    writer.writeheader()

    while True:
        #with open('/home/pi/Documents/ECE44x/Wireless/test.csv', 'a') as csvfile:
        time.sleep(3)
        if (len(data) > 6):
            writer.writerow({fieldnames[0]: data[0], fieldnames[1]: data[1], fieldnames[2]: data[2],
                    fieldnames[3]: data[3], fieldnames[4]: data[4], fieldnames[5]:data[5],
                    fieldnames[6]: data[6]})
#    f.close()