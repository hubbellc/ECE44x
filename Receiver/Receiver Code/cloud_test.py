import threading
import os

def sendit():
    threading.Timer(30.0, sendit).start()
    os.system('/home/pi/Documents/ECE44x/Wireless/gdrive-linux-rpi upload --parent 1DXNoqiL6IrSj4Qq8Vzcjfm8o7wAowkwT /home/pi/Documents/ECE44x/Wireless/test.csv')
    print ("full send")
    
sendit()
#os.system('./gdrive-linux-rpi upload --parent 1DXNoqiL6IrSj4Qq8Vzcjfm8o7wAowkwT test.csv')