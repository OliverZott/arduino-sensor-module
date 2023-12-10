import subprocess
import time

import psutil

script_path = r"src\python-data-analysis\port-reader.py"
venv_path = r"src\python-data-analysis\venv"
process_name = "port-reader.py"


def check_if_process_running(process_name):
    for proc in psutil.process_iter(["name"]):
        try:
            if process_name.lower() in proc.info["name"].lower():
                return True
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass
    return False


def run_script(script_path, venv_path):
    # return subprocess.Popen(f'{venv_path}/bin/python {script_path}', shell=True)  # linux version
    return subprocess.Popen(rf"call {venv_path}\Scripts\python {script_path}", shell=True)


def main():
    global process
    process = run_script(script_path, venv_path)

    while True:
        time.sleep(3)  # Check every second
        if not check_if_process_running(process_name):
            print(f"The script {process_name} stopped running. Restarting...")
            process = run_script(script_path, venv_path)


if __name__ == "__main__":
    main()
