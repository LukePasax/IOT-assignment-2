import matplotlib.pyplot as pl
from matplotlib import animation
import serial


pl.xlabel("Time (s)")
pl.ylabel("Water Level")
pl.title("Water level over time")

ser = serial.Serial('COM4', 9800, timeout=1)

data = []
time = []
count = 0

def draw_graph(i):
    global count
    count += 1
    line = ser.readline()
    if line:
        string = line.decode()
        num = int(string)
        data.append(num)
    time.append(count)
    if(data.__len__() > 4):
        data.pop(0)
        time.pop(0)
    pl.plot(data,time)
anim = animation.FuncAnimation(pl.gcf(), draw_graph, interval=1000)

pl.show()
