#!/usr/bin/python

import smbus # i2c
import time
import Adafruit_ADS1x15 as ADS1x15 # adc hat
import Adafruit_DHT # temp/humidity
import csv
import sys
import bme280
import os
import serial
from math import log10
from timeit import default_timer as timer

sys.path.append("/home/pi/.local/lib/python2.7/site-packages")

import datetime
import bme280
#import gspread
#from oauth2client.service_account import ServiceAccountCredentials

# use creds to create a client to interact with the Google Drive API
#scope = ['https://spreadsheets.google.com/feeds', 'https://www.googleapis.com/auth/drive']
#creds = ServiceAccountCredentials.from_json_keyfile_name('/home/pi/client_secret1.json', scope)
#client = gspread.authorize(creds)

# Find a workbook by name and open the first sheet
# Make sure you use the right name here.
#sheet = client.open("Sensor Data").sheet1

# create a 12-bit ADC instance
adc = ADS1x15.ADS1015()
GAIN = 2/3 # 2/3 for +/-6.144 V; 1 for +/-4.096 V

# create an i2c bus object
bus = smbus.SMBus(1)

# from i2cdetect -y 1
pressure_addr = 0x60
ADC_addr = 0x48

tran_number = 2
fieldnames=['Date/time', 'Temp', 'Humidity', 'Air pressure', 'Lux', 'NO2', 'CH4', 'NH3'] #TODO, yes?

# assign serial port for LoRa module
port = serial.Serial("/dev/serial0", baudrate=115200, timeout=3.0)

# Minute and seconds for calculating collection time
def timer():
    now = datetime.datetime.now()
    minute = now.minute
    second = now.second
    return (minute, second)

# Update the data in the Google Dive
def updateDrive(light, temperature, humidity, pressure, methane, ammonia):
    now = datetime.datetime.now()
    date = "{} {}, {}".format(now.month, now.day, now.year)
    time = "{}:{}:{}".format(now.hour, now.minute, now.second)
    row = [date,time]
    data = [light, temperature, humidity, pressure, methane, ammonia]
    data_list = sheet.range('C2:I2')
    i = 0
    for cell in data_list:
        cell.value = data[i]
        i = i + 1
    sheet.insert_row(row, 2, 'USER_ENTERED')
    sheet.update_cells(data_list, 'USER_ENTERED')

def bme_280():
    temperature, pressure, humidity = bme280.readBME280All()
    return temperature, pressure, humidity

def pressure_test(addr):
    bus.write_byte_data(0x60, 0x13, 0x07)
    bus.write_byte_data(0x60, 0x26, 0x39)
    time.sleep(1)
    # MPL3115A2 address, 0x60(96)
    # Read data back from 0x00(00), 4 bytes
    # status, pres MSB1, pres MSB, pres LSB
    data = bus.read_i2c_block_data(0x60, 0x00, 4)
    # Convert the data to 20-bits
    pres = ((data[1] * 65536) + (data[2] * 256) + (data[3] & 0xF0)) / 16
    pressure = (pres / 4.0) / 1000.0
    #pressure = pressure - 0.334 # calibration adjustment
    #print('pressure: %d' % pressure)
    return (pressure)

def light_test(channel):
    light_data = adc.read_adc(channel, gain = GAIN) # reads 12-bit ADC channel
    light_data = 10.0**((log10(light_data) - log10(1088.0))/((log10(99.0)-log10(1088.0))/log10(415.0))) # converts raw data to LUX
    return int(light_data)

def humtemp_test():
    humidity, temperature = Adafruit_DHT.read_retry(Adafruit_DHT.AM2302, 4)
    if humidity is not None and temperature is not None:
        #print('Temp={0:0.1f}  Humidity={1:0.1f}%'.format(temperature, humidity))
        return (str(humidity), str(temperature))
    else:
        #print('Failed to get reading!')
        return ('No value', 'No value')

def ammonia_test(channel, temp, humidity):
    ammonia = adc.read_adc(channel, gain = GAIN)# reads 12-bit ADC channel
    ammonia = 0.28*ammonia  #agreeability with transmitter1 factor
    #ammonia = (4096.0/ammonia - 1)*4600 # calculate internal resistance
    #ammonia = correct_ammonia(ammonia, temp, humidity) # correct for temperature and humidity
    #ammonia = ammonia/correct_ammonia(123500, 30, 75) # divide by reference resistance
    #print(ammonia)
    #ammonia = ammonia_ppm(ammonia) # find ppm from Rs/Ro
    #print(ammonia)
    return ammonia

def correct_ammonia(ammonia, temp, humidity):
    c_33 = [8.57142842e-04, -7.14285705e-02, 2.38857142e+00]
    c_85 = [1.42857052e-04, -2.35714231e-02, 1.41142849e+00]

    if humidity <= 33:
        c = c_33
    elif humidity < 85:
        c = [(c_85[0] - c_33[0])*(humidity - 33)/(85-33)  + c_33[0],
             (c_85[1] - c_33[1])*(humidity - 33)/(85-33) + c_33[1],
         (c_85[2] - c_33[2])*(humidity - 33)/(85-33) + c_33[2]]
    else:
        c = c_85

    factor = c[0]*temp**2 + c[1]*temp + c[2]
    return ammonia/factor

def ammonia_ppm(ammonia):
    ppm = -542.59067943*ammonia**3 + 2072.83026394*ammonia**2 -2656.31309922*ammonia + 1161.66386303
    #if ppm < 0:
    #   ppm = 0
    return ppm

def methane_test(channel, temp, humidity):
    methane = adc.read_adc(channel, gain = GAIN) # reads 12-bit ADC channel
    #methane = (4096.0/methane - 1)*36800 # calculate internal resistance
    #methane = correct_methane(methane, temp, humidity) # correct for temperature and humidity
    #methane = methane/correct_methane(1950000, 30, 75) # divide by reference resistance
    #print(methane)
    #methane = methane_ppm(methane) # find ppm from Rs/Ro
    #print(methane)
    methane = 0.8 * methane #agreeability with transmitter1 factor
    return methane

def correct_methane(methane, temp, humidity):
    c_35 = [8.57142842e-04, -7.14285705e-02, 2.38857142e+00]
    c_65 = [1.42857052e-04, -2.35714231e-02, 1.41142849e+00]
    c_95 = [0, -0.01, 1]

    if humidity <= 35:
        c = c_35
    elif humidity < 65:
        c = [(c_65[0] - c_35[0])*(humidity - 35)/30 + c_35[0],
             (c_65[1] - c_35[1])*(humidity - 35)/30 + c_35[1],
         (c_65[2] - c_35[2])*(humidity - 35)/30 + c_35[2]]
    elif humidity < 95:
        c = [(c_95[0] - c_65[0])*(humidity - 65)/30 + c_65[0],
             (c_95[1] - c_65[1])*(humidity - 65)/30 + c_65[1],
         (c_95[2] - c_65[2])*(humidity - 65)/30 + c_65[2]]
    else:
        c = c_95

    factor = c[0]*temp**2 + c[1]*temp + c[2]
    return methane/factor

def methane_ppm(methane):
    ppm = -5863.91786*methane**3 + 16488.98841*methane**2 - 15513.40826*methane + 4890.12072
    #if ppm < 0:
    #   ppm = 0
    return ppm

def record():

    #start = True
    print("record function started")
    file_name = '/home/pi/test-data.csv'
    temp_file_name = '/home/pi/test-data-temp.csv'
    now = datetime.datetime.now()
    previous_day = int(now.day)
    current_day = int(now.day)

    if (current_day != previous_day):
        previous_day = current_day
        file_size = 0
        current = open(file_name, 'r') 
        temp = open(temp_file_name, 'w+')
        csv_reader = csv.reader(current)
        csv_writer = csv.writer(temp)

        for row in csv_reader:
            file_size = file_size + 1

        if (file_size > 4032):
            x = file_size - 4032
            current.seek(x)
            #csv_writer.writerow(['date', 'methane', 'ammonia', 'pressure', 'temperature', 'humidity', 'light'])
            csv_writer.writerow(fieldnames)

            for row in csv_reader:
                csv_writer.writerow(row)

            current.close()
            temp.close()
            print("removing test file")
            os.remove(file_name)
            os.rename(temp_file_name, file_name)

        else:
            current.close()
            temp.close()

        print("opening file")        

    with open(file_name, 'a+') as csv_file:
        csv_writer = csv.writer(csv_file, quoting=csv.QUOTE_NONE)

        try:
            # select pressure sensor
            #pressure = "%0.2f" % pressure_test(pressure_addr)
            pressure = "%0.2f" % (bme_280()[1]/10.0)
            #pressure = pressure / 10.0
        except:
            print("Failure during pressure test")
            pressure = "null"

        try: 
            #humidity, temperature = humtemp_test()
            #humidity = "%0.2f" % float(humidity)
            #temperature = "%0.2f" % float(temperature)
            # select temperature/humidity sensor
            temperature = "%0.2f" % bme_280()[0]
            humidity = "%0.2f" % bme_280()[2]
            print(humidity)
            print(temperature)
        except:
            print("Failure during temperature/humidity test")
            humidity = "null"
            temperature = "null"

        try: 
            light = "%d" % light_test(2)
        except:
            light = "null"
        try: 
            light = "%d" % light_test(2)
        except:
            print("Failure during light test")
            light = "null"

        try: 
            ammonia = "%0.2f" % ammonia_test(1, float(temperature), float(humidity))
        except:
            print("Failure during ammonia test")
            ammonia = "null"

        try:
            #methane = adc.read_adc(channel, gain = GAIN)
            methane = "%.2f" % methane_test(0, float(temperature), float(humidity))
            #print(methane)
        except:
            print("Failure during methane test")
            methane = "null"
            
        NO2 = 0 # we dont have an NO2 sensor    
        
        #timestamp = "{}/{}/{} {}:{}:{}".format(now.day, now.month, now.year, now.hour, now.minute, now.second)
        timestamp = time.strftime("%e/%m/%G %H:%M:%S")
        #print("timestamp, methane [ppm], ammonia [ppm], pressure [hPa], temperature [C], humidity [%RH], light [Lux]")
        #print(timestamp + ", " + methane + ", " + ammonia + ", " + pressure + ", " + temperature + ", " + humidity + ", " + light)
        csv_writer.writerow([timestamp, temperature, humidity, pressure, light, NO2, methane, ammonia])
        csv_file.close()

        # send over LoRa module
        lora_string = "{},{},{},{},{},{},{},{},{}\n".format(tran_number, timestamp, temperature, humidity, pressure, light, NO2, methane, ammonia)
        port.write(lora_string.encode())
        #updateDrive(light, temperature, humidity, pressure, methane, ammonia)


#while(True):
record()
 #   time.sleep(3)

