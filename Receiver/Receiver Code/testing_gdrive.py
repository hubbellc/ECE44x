import os

# try and get files names
files = str(os.system("/home/pi/Documents/code/gdrive-linux-rpi sync upload /home/pi/Documents/Data 1iR74rrbEBQ9Su3WMTcZe_SJnLB6R-aWm"))
print(files)
print(type(files))

parsed_files = files.split("\t")
print(files)
  
  
  

#upload if we have made a file!
#if tran_number > 0:
#for i in range(10):
#    try:
#        print("file being uploaded: ")
#          #  toOpen = "/home/pi/Documents/ECE44x/Wireless/gdrive-linux-rpi upload --parent 1DXNoqiL6IrSj4Qq8Vzcjfm8o7wAowkwT /home/pi/Documents/Data/data"+str(tran_number)+".csv"
#        toOpen = "/home/pi/Documents/code/gdrive-linux-rpi update 1MaAuFibs0VxOXIV2-WT_5v7mjQtjygrC /home/pi/Documents/Data/data"+str(i)+".csv"
#        os.system(toOpen)
#        print ("full send to drive")
#    except:
#        print("file doesn't exist in drive, go make one")
# filenum = filenum + 1
#new_file = False
