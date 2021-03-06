#!/bin/bash

xterm -e 'sudo python /home/pi/Documents/ECE44x/Sensor/Wills\ Sensor\ Processing/lora_init.py'

while :
do
	#hostname -I >> /home/pi/IPADDRESS
	sleep 900
	xterm  -e 'sudo python /home/pi/Documents/ECE44x/Sensor/Wills\ Sensor\ Processing/read_sensors.py'
	echo "Read complete"
	if [ -e /dev/sda1 ]
	then
		usb="/dev/sda1"
	elif [ -e /dev/sdb1 ]
	then
		usb="/dev/sdb1"
	else
		echo "USB not found"
		continue
	fi
	directory="/home/pi/USB$(date +%s)"
	sudo mkdir $directory
	sudo mount -t vfat -o uid=pi,gid=pi $usb $directory
	#echo "USB mounted to $directory"
	rm -f $directory/test-data.csv
	#echo "Pre-copy"
	cp /home/pi/test-data.csv $directory
	#echo "Data copied to USB"
	sudo umount $directory
	#echo "USB unmounted"
	sudo rm -f -r /home/pi/USB*
done
