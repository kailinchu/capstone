# Author: Dorian Knight of Capstone team 8
# Created: March 3rd 2026
# Updated: March 5th 2026
# Description: Plots all relevant data from Tourniquet PCB

import matplotlib.pyplot as plt
import matplotlib.animation as animation
# import numpy as np
import time
import serial
import struct
import keyboard

time_series = []
max_columns = 2 # Determines how many rows we will have

# Global quantities
quantities_to_graph = [
    # Quantity name, colour on graph
    # Put quantities you want displayed together in the same macro level list

    # Plot 1: Cuff pressure with set point pressure
    [["Cuff pressure", "black"], ["Set point pressure", "blue"]],

    # # Plot 2: BNO accelerometer readings
    # [["BNO_X", "blue"], ["BNO_Y", "red"], ["BNO_Z", "green"]],

    # Plot 3: Cuff pressure after high pass filter
    [["HPF cuff pressure", "black"]],

    # Plot 4: Disruption signals
    [["Motor active","blue"],["Movement detected","red"],["Summation paused","green"]],

    # Plot 5: Measured pulse strength and decision point
    [["Bloodflow summation", "green"], ["Bloodflow threshold", "black"]],

    # Plot 6: Bleed or no bleed?
    [["Bloodflow boolean", "black"]],

    # Plot 7: Motor PWM and Solenoid state
    [["Motor PWM", "red"], ["Solenoid state", "blue"]],

    # Plot 8: Initial search state
    [["Initial search state", "red"]],

    # Plot 9: Ideal pressure found
    [["Ideal pressure found", "blue"]],
    
    # Plot 10: Button status
    [["Increase signal", "green"], ["Decrease signal", "red"], ["Automode signal", "black"]],

    # Plot 11: Operating status
    [["Operation mode", "black"]],

    # Plot 12: Time
    # [["Time", "red"]],
]

graph_limits = [
    # Format: window, y_lower, y_upper, title

    # Plot 1: Cuff pressure with set point pressure
    {"window":100, "y_lower":-10, "y_upper":350, "graph title":"Cuff pressure vs time",    "graph y_label": "Cuff pressure (mmHg)", "plot start": 0, "advance by": 20},

    # # # Plot 2: BNO accelerometer readings
    # # {"window": 60, "y_lower": -10, "y_upper": 10, "graph title": "HPF Accelerometry vs time", "graph y_label": "Acceleration (m/s^2)", "plot start": 0, "advance by": 20},

    # Plot 3: Cuff pressure after high pass filter
    {"window": 60, "y_lower": -0.1, "y_upper": 5, "graph title": "HPF cuff pressure vs time", "graph y_label": "Filtered cuff pressure (mmHg)", "plot start": 0, "advance by": 20},

    # Plot 4: Disruption signals (movement, motor and paused summation signal)
    {"window": 60, "y_lower": -0.1, "y_upper": 2, "graph title": "Disruption boolean signals vs time", "graph y_label": "Signal level (unitless)", "plot start": 0, "advance by": 20},

    # Plot 5: Quantized blood flow strength
    {"window": 60, "y_lower": -10, "y_upper": 2000, "graph title": "Measured blood flow summation", "graph y_label": "Quantized pulse strength (unitless)", "plot start": 0, "advance by": 20},
    # {"window": 60, "y_lower": -10, "y_upper": 70000, "graph title": "Measured blood flow summation", "graph y_label": "Quantized pulse strength (unitless)", "plot start": 0, "advance by": 20},

    # Plot 6: Subject's bleeding status
    {"window": 60, "y_lower": -0.1, "y_upper": 1.1, "graph title": "Subect bleeding status", "graph y_label": "Bloodflow boolean (unitless)", "plot start": 0, "advance by": 20},

    # Plot 7: Motor and solenoid drive sitnals
    {"window": 60, "y_lower": -3, "y_upper": 2, "graph title": "Motor and Solenoid state", "graph y_label": "Signal level (unitless)", "plot start": 0, "advance by": 20},

    # Plot 8: Initial search state
    {"window": 60, "y_lower": -1, "y_upper": 4, "graph title": "Initial search state", "graph y_label": "State variable (unitless)", "plot start": 0, "advance by": 20},

    # Plot 9: Ideal pressure found
    {"window": 60, "y_lower": -1, "y_upper": 2, "graph title": "Ideal pressure found boolean", "graph y_label": "Indicator (unitless)", "plot start": 0, "advance by": 20},

    # Plot 10: Button status
    {"window": 60, "y_lower": -3, "y_upper": 4, "graph title": "Manual mode buttons", "graph y_label": "State (unitless)", "plot start": 0, "advance by": 20},

    # Plot 11: Operating mode
    {"window": 60, "y_lower": -1, "y_upper": 2, "graph title": "Operating status", "graph y_label": "State (unitless)", "plot start": 0, "advance by": 20},

    # Plot 12: Time
    # {"window": 100, "y_lower": 0, "y_upper": 100000, "graph title": "Time", "graph y_label": "State (unitless)", "plot start": 0, "advance by": 10},
]

# Dictionary storing all values read in from Serial buffer
data_list_complete = {"Cuff pressure": 0,
                      "Set point pressure": 0,
                      "BNO_X": 0,
                      "BNO_Y": 0,
                      "BNO_Z": 0,
                      "HPF cuff pressure":0,
                      "Motor active": 0,
                      "Movement detected": 0,
                      "Summation paused": 0,
                      "Bloodflow summation": 0,
                      "Bloodflow boolean": 0,
                      "Bloodflow threshold": 0,
                      "Motor PWM": 0,
                      "Solenoid state": 0,
                      "Initial search state": 0,
                      "Ideal pressure found": 0,
                      "Increase signal": 0,
                      "Decrease signal": 0,
                      "Automode signal": 0,
                      "Operation mode": 0,
                      "Milliseconds": 0,
                      "Seconds": 0,
                      "Minutes": 0,
                      "Hours":0,
                      }

num_of_subplots = len(quantities_to_graph)
incident_time = time.perf_counter()
ser = serial.Serial('COM10', 115200, timeout=1)

def grid_formater(num_of_subplots):
    # Uses global "quantities_to_graph" variable and comes up with the number of rows and columns needed to represent all data

    remainder = num_of_subplots % max_columns
    rows = num_of_subplots // max_columns # integer division
    columns = max_columns

    if (remainder != 0):
        # Will need one more row to represent all subplots
        rows += 1

    if (num_of_subplots < max_columns):
        # Less than max columns, only display number of columns needed
        columns = num_of_subplots

    return rows, columns

class grapher():
    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.fig, self.ax = plt.subplots(rows,columns,sharex=False)
        self.remove_unused_plots()
        self.fig.set_size_inches(15, 9)
        self.fig.subplots_adjust(wspace=0.3, hspace=0.7, left=0.05, right=0.95)
        self.fig.canvas.manager.window.wm_geometry("+20+20")

        self.ln = []
        self.quantity_data = []
        self.counter = 0
        self.presented_data = []

        # Correct row / column layout edge case
        if (rows == 1):
            # When there is only 1 row, the ax data structure is a 1d array
            # Turn this into a 2d array by placing it inside an array
            self.ax = [self.ax]
        if (columns == 1):
            # Where there is only 1 column, each row gets placed into the same array making it 1d
            # Go through and put each row on its own array
            for i in range(len(self.ax)):
                self.ax[i] = [self.ax[i]]

        # Add each quantity to the appropriate subplot
        for i in range(num_of_subplots):
            row = i//columns
            for j in range(len(quantities_to_graph[i])):
                line, = self.ax[row][i%columns].plot([],[], label=quantities_to_graph[i][j][0], color=quantities_to_graph[i][j][1]) # Comma automatically unpacks variable
                self.ln.append(line)
                self.quantity_data.append([]) # Add empty array to eventually hold quantity data
                self.presented_data.append(quantities_to_graph[i][j][0])


    def remove_unused_plots(self):
        # Take total number of plotted quantities and remove unused subplots
        created_subplots = self.rows * self.columns
        if (created_subplots > num_of_subplots):
            # If we have unused subplots - delete them
            subplots_to_remove = created_subplots - num_of_subplots
            print(created_subplots)
            print(subplots_to_remove)
            print(self.columns)
            for i in range(self.columns-1, self.columns - subplots_to_remove -1, -1):
                self.fig.delaxes(self.ax[-1][i]) # Removes unused plots in the last row


    # Set titles, axis and limits on subplots
    def graph_init(self):
        for i in range(num_of_subplots):
            row = i//self.columns
            subplot_details = graph_limits[i]
            self.ax[row][i%self.columns].set_xlim(0, subplot_details["window"]) # Set window
            self.ax[row][i%self.columns].set_ylim(subplot_details["y_lower"], subplot_details["y_upper"])
            self.ax[row][i%self.columns].set_title(subplot_details["graph title"])
            self.ax[row][i%self.columns].set_ylabel(subplot_details["graph y_label"])
            self.ax[row][i%self.columns].set_xlabel("Time (sec)")
            self.ax[row][i%self.columns].legend()


    # Read in data from serial
    def read_data(self, elapsed_time):
        ser.write(bytes("R", "utf-8")) # Request data
        # print("Requesting data")
        if (ser.in_waiting > 0):
            # print("Data received")
            time_series.append(elapsed_time)
            cuff_pressure_raw = ser.read(4) # Read in 4 bytes to reconstruct float
            pressure_set_point_raw = ser.read(4)
            bno_x_raw = ser.read(4)
            bno_y_raw = ser.read(4)
            bno_z_raw = ser.read(4)
            filtered_pressure_reading_raw = ser.read(4)
            motor_active_raw = ser.read(1)
            accelerometer_active_raw = ser.read(1)
            pause_summation_raw = ser.read(1)
            bloodflow_summation_raw = ser.read(2)
            bloodflow_boolean_raw = ser.read(1)
            bloodflow_threshold_raw = ser.read(2)
            motor_pwm_raw = ser.read(4)
            solenoid_state_raw = ser.read(1)
            initial_search_state_raw = ser.read(1)
            ideal_pressure_found_raw = ser.read(1)
            increase_signal_raw = ser.read(1)
            decrease_signal_raw = ser.read(1)
            automode_signal_raw = ser.read(1)
            operation_mode_raw = ser.read(1)
            milliseconds_raw = ser.read(1)
            seconds_raw = ser.read(1)
            minutes_raw = ser.read(1)
            hours_raw = ser.read(1)
            

            # Unpack serial reads only if data was received
            if (cuff_pressure_raw != ''):
                data_list_complete["Cuff pressure"] = struct.unpack('<f', cuff_pressure_raw)[0] # Reconstruct float
                data_list_complete["Set point pressure"] = struct.unpack('<f', pressure_set_point_raw)[0]
                data_list_complete["BNO_X"] = struct.unpack('<f', bno_x_raw)[0]
                data_list_complete["BNO_Y"] = struct.unpack('<f', bno_y_raw)[0]
                data_list_complete["BNO_Z"] = struct.unpack('<f', bno_z_raw)[0]
                data_list_complete["HPF cuff pressure"] = struct.unpack('<f', filtered_pressure_reading_raw)[0]
                data_list_complete["Motor active"] = struct.unpack('<?', motor_active_raw)[0]
                data_list_complete["Movement detected"] = struct.unpack('<?', accelerometer_active_raw)[0]
                data_list_complete["Summation paused"] = struct.unpack('<?', pause_summation_raw)[0]
                data_list_complete["Bloodflow summation"] = struct.unpack('<H', bloodflow_summation_raw)[0]
                data_list_complete["Bloodflow boolean"] = struct.unpack('<?', bloodflow_boolean_raw)[0]
                data_list_complete["Bloodflow threshold"] = struct.unpack('<H', bloodflow_threshold_raw)[0]
                data_list_complete["Motor PWM"] = struct.unpack('<f', motor_pwm_raw)[0]/255
                data_list_complete["Solenoid state"] = struct.unpack('<?', solenoid_state_raw)[0] - 2
                data_list_complete["Initial search state"] = struct.unpack('<B', initial_search_state_raw)[0]
                data_list_complete["Ideal pressure found"] = struct.unpack('<?', ideal_pressure_found_raw)[0]
                data_list_complete["Increase signal"] = struct.unpack('<?', increase_signal_raw)[0]
                data_list_complete["Decrease signal"] = struct.unpack('<?', decrease_signal_raw)[0] - 2
                data_list_complete["Automode signal"] = struct.unpack('<?', automode_signal_raw)[0] + 2
                data_list_complete["Operation mode"] = struct.unpack('<B', operation_mode_raw)[0]
                data_list_complete["Milliseconds"] = struct.unpack('<B', milliseconds_raw)[0]
                data_list_complete["Seconds"] = struct.unpack('<B', seconds_raw)[0]
                data_list_complete["Minutes"] = struct.unpack('<B', minutes_raw)[0]
                data_list_complete["Hours"] = struct.unpack('<B', hours_raw)[0]


                # print(data_list_complete["Cuff pressure"])
                # print(data_list_complete["Set point pressure"])
                # print(data_list_complete["Bloodflow summation"])
                print(data_list_complete["Milliseconds"], data_list_complete["Seconds"], data_list_complete["Minutes"], data_list_complete["Hours"])

                # Only append the data requested to be graphed
                for i in range(len(self.presented_data)):
                    self.quantity_data[i].append(data_list_complete[self.presented_data[i]])


    def scrollx(self,x):
        axes_update = False
        # Move screen rightwards as new data moves off window
        for i in range(num_of_subplots):
            # For each quantity measured, check if window should be moved and move it if needed
            data_window = graph_limits[i]["window"]
            plot_start = graph_limits[i]["plot start"]
            plot_end = plot_start + data_window

            if (len(x) > 0 and plot_end < x[-1]):
                # Advance plot
                plot_advance = graph_limits[i]["advance by"]
                row = i//self.columns
                self.ax[row][i%self.columns].set_xlim(plot_start + plot_advance, plot_end + plot_advance)

                # Reset the plot start key within the graph limits dictionary so this process can inch fowards
                graph_limits[i]["plot start"] = plot_start + plot_advance
                axes_update = True
        if (axes_update == True):
            self.fig.canvas.draw()


def animate(i):
    elapsed_time = time.perf_counter() - incident_time
    graphObj.read_data(elapsed_time)

    for j in range(len(graphObj.quantity_data)):
        # Graph data
        graphObj.ln[j].set_data(time_series, graphObj.quantity_data[j])

    graphObj.scrollx(time_series)
    return graphObj.ln

rows, columns = grid_formater(num_of_subplots)
graphObj = grapher(rows, columns)
graphObj.graph_init()
plot_animation = animation.FuncAnimation(graphObj.fig, animate, blit=True, interval=0.1)
plt.show()
print("Just before closing")

ser.close()
print("Serial port closed")





