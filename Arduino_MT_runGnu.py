# https://pymotw.com/3/subprocess/


import os
import re


#===============================================================
# Path with log files ('r' to ignore '\' in string --> raw_string)
#===============================================================
path = r'D:\Users\Dura\Documents\Arduino\Projekt_1\Messwerte'		


# print(os.access(path, os.F_OK | os.R_OK))  		# test if access to path (exists | readable)
# print(type(path))


#===============================================================
# RegEx-Function for date from log-files (format: "Log_20181024.txt")
#===============================================================

def gnu_plot(filename):

	date_full = filename.lstrip("Messwerte_")
	print(date_full)

	#date_full = re.search(r"2\d{10}",filename).group(0)
	#date_YYYY = re.search(r"20\d{2}'-'\d{2}'-'\d{2}",filename).group(0)
	date_YYYY = date_full[0:4]
	date_MM = date_full[5:7]
	date_DD = date_full[8:10]

	
	#date_file = date_DD + "." + date_MM + "." + date_YYYY;
	date_file = date_YYYY + "-" + date_MM + "-" + date_DD;
	print(date_file)

	chart_name = "Chart_" + date_file
	print(chart_name)

			#gnuplot -e "filename='Log_20190402.txt'; DATE='02.04.2019'" auswertung.gpl
	
	gnu = "gnuplot -e \"filename='" +filename+   "'; DATE='"+date_file+"'\" auswertung.gpl"
	print(gnu)
	os.system(gnu)
	
	
'''	
#===============================================================
# Gnuplot command (commandline input)
#===============================================================

# error... kann date nicht übergeben wiel noch nicht definiert
def gnucmd(filname, date_file):
	gnu = "gnuplot -e \"filename='"+filename+"'; DATE='12.03.2019'\" auswertung.gpl"
	print(gnu)
	os.system(gnu)
'''


#===============================================================
# loop to obtain every log-file in directory
#===============================================================


for file in os.listdir(path):
	if file.endswith('.txt'):
		#print(type(file))
		#print(file)
		gnu_plot(file)
		#gnucmd(file, date_file)

	


'''
fname = 'Log_20190312.txt'
gnucmd = "gnuplot -e \"filename='"+fname+"'; DATE='12.03.2019'\" auswertung.gpl"

# = "gnuplot -e \"filename='Log_20190312.txt'; DATE='12.03.2019'\" auswertung.gpl"

os.system(gnucmd)


'' ' import subprocess
with open("Log_20190314.txt", "r") as filename:
	cmd = ['D:\Software\gnuplot\bin\gnuplot.exe', "Log_20190314.txt"]
	process = subprocess.Popen(cmd, stdout=subprocess.PIPE)
	process.wait()
	for line in process.stdout:
		print(line)
'''