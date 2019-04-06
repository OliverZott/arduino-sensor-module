# Python: Arduino Projekt
# https://pypi.org/project/pyserial/#description
# https://pythonhosted.org/pyserial/
# Oliver Zott 
# ver 1.0.0
# 03.04.2019

import serial
import re
import datetime


# ============= NEXT =============
# Alles in Funktionen packen
# OOP ???
# Loop für minütliches Logging / oder Batchjob aufruf ?!



#===============================================================
# Serial communication & decoding
#===============================================================
print("Serial Port - Test:")
port = serial.Serial()
port.baudrate = 9600
port.port = 'COM4'
port.open()
port_out = port.read(61)
#print (port);
print ("Data: ", port_out);
print ("Type: ", type(port_out));

# Decode byte stream (byte --> str)
data_str = port_out.decode("utf-8") 
#print ("Data: ", data_str)
#print ("Type: ", type(data_str))



#===============================================================
# RegEx
#===============================================================

temp_re = re.search(r"\d*\s\*C", data_str).group(0)		# group(0), damit str (<class 're.Match'>)
#print ("temp_re", temp_re)
#print ("Typ von temp_re", type(temp_re))
temp = temp_re.rstrip(" *C")
#print (temp)
#print ("Typ von temp", type(temp))

hum_re = re.search(r"\d*\s\%", data_str).group(0)
hum = hum_re.rstrip(" %")



#===============================================================
# File IO
#===============================================================

date = datetime.datetime.now().strftime("%Y-%m-%d")								# date for filename
datetime = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")				# date & time
measurement = datetime + ":" " Temperature: " + temp + " C°, " + "Humidity: " + hum + " %\n"	# meassurement-String

file_name = "Messwerte_"  + date +".txt"; 
file = open(file_name, "a")
file.write(measurement)
file.close()


