# Python: Arduino Projekt
# https://pypi.org/project/pyserial/#description
# https://pythonhosted.org/pyserial/
# Oliver Zott 
# ver 1.0.0
# 03.04.2019

import serial
import re
import datetime
import time





# ============= NEXT =============
# OOP ?
# function arguments, parameters ok like that?
# check clock-time for Serial-communication (15 sec ???) and adjust loop-timing





#===============================================================
# Serial communication & decoding
#===============================================================

def serial_open():
	port = serial.Serial()
	port.baudrate = 9600
	port.port = 'COM4'
	port.open()
	port_out = port.read(75)  #(72 min)
	#print (port);
	#print ("Data: ", port_out);
	#print ("Type: ", type(port_out));
	
	# Decode byte stream (byte --> str)
	data_str = port_out.decode("utf-8")  	
	return data_str
	
	#print ("Data: ", data_str)
	#print ("Type: ", type(data_str))


#===============================================================
# RegEx
#===============================================================

def values_re(data_str):
	temp_re = re.search(r"\d*\s\*C", data_str).group(0)		# group(0), damit str (<class 're.Match'>)
	#print ("temp_re", temp_re)
	#print ("Typ von temp_re", type(temp_re))
	temp = temp_re.rstrip(" *C")
	#print (temp)
	#print ("Typ von temp", type(temp))

	hum_re = re.search(r"\d*\s\%", data_str).group(0)
	hum = hum_re.rstrip(" %")

	lux_re = re.search(r"\d*\.\d*\slux", data_str).group(0)
	lux = lux_re.rstrip(" lux")
	
	return temp, hum, lux


#===============================================================
# File IO
#===============================================================

def file_io (temp, hum, lux):
	date = datetime.datetime.now().strftime("%Y-%m-%d")							# date for filename
	dateANDtime = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")			# date & time
	
	# meassurement-String
	measurement = dateANDtime + ":" " Temperature: " + temp + " C°, " + "Humidity: " + hum + " %, " + "Illuminance: " + lux + " lux" + "\n"	
	
	file_name = "Messwerte_"  + date +".txt"; 
	file = open(file_name, "a")
	file.write(measurement)
	file.close()
	

#===============================================================
# Loop
#===============================================================

print("Loop for data-logging starts...")

while True:
	t_s = datetime.datetime.now().second
	t_h = t = datetime.datetime.now().hour
	if 15 <= t_h < 17 and t_s == 00:
		serial_open()	
		values_re(serial_open())
		file_io(*values_re(serial_open()))
		#time.sleep(5)