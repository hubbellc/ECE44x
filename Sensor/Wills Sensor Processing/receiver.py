#!/usr/bin/python

import time
import serial
port = serial.Serial("/dev/ttyS0", baudrate=9600)

import gspread
from oauth2client.service_account import ServiceAccountCredentials

# use creds to create a client to interact with the Google Drive API
scope = ['https://spreadsheets.google.com/feeds', 'https://www.googleapis.com/auth/drive']
creds = ServiceAccountCredentials.from_json_keyfile_name('/home/pi/client_secret1.json', scope)
client = gspread.authorize(creds)

# Find a workbook by name and open the first sheet
# Make sure you use the right name here.
sheet = client.open("Sensor Data").sheet1

def updateDrive(input):
	#data = [timestamp, light, temperature, humidity, pressure, methane, ammonia]
	data_list = ['1', '2', '3', '4', '5', '6', '7']
	sheet.insert_row(data_list, 2, 'RAW')

updateDrive(0)
while 1:
	if port.in_waiting:
		input = port.readline()
		updateDrive(input)
		
