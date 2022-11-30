import serial
import matplotlib.pyplot as plt
import numpy as np
plt.ion()
fig=plt.figure()


x=[]
y=[]
i=0
ser = serial.Serial("COM7", 9600)
ser.close()
ser.open()
while True:
    data = ser.readline()
    nums = data.decode()
    print(nums)
    nums = nums.split(' ')[0]
    x.append(i)
    y.append(float(nums))
    plt.plot(x,y, 'b')
    plt.axis([-0.001, i, 0, 1])
    i += 1
    plt.show()
    plt.pause(0.5)
    if plt.fignum_exists(fig.number) == False:
        break  
ser.close()
