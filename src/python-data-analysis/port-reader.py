import time
from datetime import datetime

import serial

# check ports in console: python -m serial.tools.list_ports


ser = serial.Serial("/dev/ttyACM0", 9600)  # linux
# ser = serial.Serial("COM3", 9600)  # windows


while True:
    date_string = datetime.now().strftime("%Y%m%d")
    timestamp = datetime.now().isoformat()

    log_file_path = rf"src/python-data-analysis/{date_string}_sensor.log"

    with open(log_file_path, "a") as f:  # 'a' apends
        # Read, decode line as ASCII and remove trailing newlines.
        line = ser.readline()
        line = line.decode("ascii").rstrip()

        log_line = f"{timestamp},{line}\n"

        f.write(log_line)

        print(log_line)
        time.sleep(2)
