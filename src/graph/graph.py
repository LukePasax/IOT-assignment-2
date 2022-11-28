import serial
import matplotlib.pyplot as plt
import numpy as np
plt.ion()
fig=plt.figure()


<<<<<<< Updated upstream
x=[]
y=[]
=======
i=0
x=list()
y=list()
>>>>>>> Stashed changes
i=0
ser = serial.Serial("COM3", 9600)
ser.close()
ser.open()
while True:

    data = ser.readline()
<<<<<<< Updated upstream

    x.append(i)
    y.append(float(data.decode()))
    plt.plot(x,y, 'b')
    plt.axis([-0.001, i, 0, 4])
=======
    #print(data.decode())
    x.append(i)
    y.append(data.decode())
    plt.plot(x, y)
    # naming the x axis
    plt.xlabel('x - axis')
    # naming the y axis
    plt.ylabel('y - axis')
>>>>>>> Stashed changes
    i += 1
    plt.show()
    plt.pause(0.5)
    if plt.fignum_exists(fig.number) == False:
        break  

ser.close()
