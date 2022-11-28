import serial
import matplotlib.pyplot as plt
import numpy as np
plt.ion()
fig=plt.figure()


i=0
#x=list()
#y=list()
i=0
ser = serial.Serial("COM3", 9600)
ser.close()
ser.open()
while True:

    data = ser.readline()
    #print(data.decode())
    #x.append(i)
    #y.append(data.decode())

    plt.scatter(i, float(data.decode()))
    i += 1
    plt.show()
    plt.pause(1)  # Note this correction
    #if i close the plot, close the program
    if plt.fignum_exists(fig.number) == False:
        break  

ser.close()
