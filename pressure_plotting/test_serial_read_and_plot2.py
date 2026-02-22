# Author: Dorian Knight
# Date: February 22nd 2026
# Test the Serial read functionality on Python as proof of concept that the Serial output from an Arduino can be read

import matplotlib.pyplot as plt
import matplotlib.animation as animation
import numpy as np
import time
import serial
import struct

count = 0
y_lower = -1.5
y_upper = 300

x = []
y = []
set_point_arr = []
prev_data = []
period = 1
window = 120 # seconds
incident_time = time.perf_counter()
ser = serial.Serial('COM5', 9600, timeout=1)
data = 0

fig, ax = plt.subplots()
ln, = ax.plot(x,y, label='Data', color='black')
ln2, = ax.plot(x,set_point_arr, label='Set Point', color='blue')

def graph_init():
    ax.set_xlim(0, window)
    ax.set_ylim(y_lower, y_upper)
    ax.set_title("Cuff pressure vs Time")
    ax.set_ylabel("Cuff pressure (mmHg)")
    ax.set_xlabel("Time (sec)")
    return ln, ln2,

def animate(i):
    elapsed_time = time.perf_counter() - incident_time
    
    if (ser.in_waiting > 0):
        raw_data = ser.read(4) # Read in 4 bytes to reconstruct float
        set_point = ser.read(4)
        
        # print(ser.in_waiting)
        if (raw_data != ''):
            # print(raw_data)
            data = struct.unpack('<f', raw_data)[0] # Reconstruct float
            set_point_data = struct.unpack('<f', set_point)[0]
            print(set_point_data)

            x.append(elapsed_time)
            y.append(data)
            set_point_arr.append(set_point_data)
            ln.set_data(x,y)
            ln2.set_data(x,set_point_arr)
            # print(data)
    
        if (elapsed_time > window):
            ax.set_xlim(elapsed_time - window, elapsed_time)
    return ln, ln2,

elapsed_time = time.perf_counter() - incident_time
plot_animation = animation.FuncAnimation(fig, animate, init_func=graph_init, blit=True, interval=0.1)

plt.legend()
plt.show()