# Arduino_Projekt1

Testing possible wireless transmission technologies for conductive mediums (e.g. Seawater).

- Sensors
- wireless data transfer
- local data storage

-------------------------------------------------------

## GIT

cd d:/Users/Dura/Documents/Arduino/Projekt_1
dir -ls
git status
git diff / git show

git add filename.extension
git commit -m "comment to descripe changes"

git remote
git push origin master

## Fehlerbehandlung & Modularisierung

Ex.: lux-Sensor error (error.log)

1.Step:
C-Code for Arduino: array<float,3>

2.Step:
C-Code for Arduino: vector / struct instead array  

3.Step:
.err and.log files

4.Step:
Fehlerbehandlung (exception handling)

5.Step:
Modularisierung / OOP

## Sensors and Python

1.Step:
Test python script with arduino-temp sensor module  - done

2.Step:
include lux-sensor and test python script again   - done

adding: loops for automated value logging   - done
 if-branches for automated value logging   - done
 test clock-time      - done

3.Step:

## Wireless Communication

1.Step:
Test Modules

- RFID        -
- 433 MHz      -
- 2.4 GHz      - done (low range!)

2.Step:
tweak RANGE!       -

3.Step:
send AND recive

## Combining (PCB + Nano)

1.Step:
Erster Versuchsaufbau auf einem BreadBoard   - done (2.4GHz)

2.Step:
Soldering on PCB      -

## Auswertung

1.Step:
Automated GnuPlot charts     - done
