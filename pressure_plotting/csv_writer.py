import serial
import csv
from datetime import date,datetime
import numpy as np
import matplotlib.pyplot as plt
import msvcrt


# Sample data


arduino_port="COM5" #arduino serial port
baud=115220 #baud rate used in arduino
nameDate=str(date.today())+"_"+str(datetime.now().strftime("%Hh%M"))
fileName=nameDate+".csv"
figureName=nameDate+".png"

ser=serial.Serial(arduino_port,baud)
print("Connected to Arduino port: " + arduino_port)

file=open(fileName,"a")
print(fileName+" created")


pressure_data=[]

##WRITE SOMETHING THAT DOES THIS PER EXERCISE AND WRITES TO THE SAME FILE
indexVal=0                                   
# collect the samples
while (True):
    if ser.in_waiting>0:
        try: 
            data_point = ser.readline().decode('utf-8').strip()
            print(data_point)
            pressure_data.append(float(data_point))
        except ValueError:
            print("skipped")
    if msvcrt.kbhit():
        break

        
# create the CSV
with open(fileName, 'w', encoding='UTF8', newline='') as f:
    for i in (pressure_data):
        writer = csv.writer(f)
        writer.writerow([indexVal,i])
        indexVal+=1

print("collection to CSV complete!")
file.close()

