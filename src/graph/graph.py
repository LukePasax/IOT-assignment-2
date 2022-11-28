import serial
import matplotlib.pyplot as plt
import numpy as np
plt.ion()
fig=plt.figure()

x=[]
y=[]
i=0
ser = serial.Serial('/dev/cu.usbmodem14201',9600)
ser.close()
ser.open()
while True:

    data = ser.readline()

    x.append(i)
    y.append(float(data.decode()))
    plt.plot(x,y, 'b')
    plt.axis([-0.001, i, 0, 4])
    i += 1
    plt.show()
    plt.pause(0.5)
    if plt.fignum_exists(fig.number) == False:
        break  

#ser.close()
