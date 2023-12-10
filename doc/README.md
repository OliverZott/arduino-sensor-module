# Sensor Module - Project

- Modzules
  - DHT11
  - TSL2561
- Data Storage
  - SD Card Module
- Wireless Data Transfer (ISM band - industrial, scientific, and medical)
  - 433 MHz
  - 2.4 GHz

## Data storage

```c
include <SPI.h>
include <SD.h>
include <DHT.h>
define DHTPIN 4
define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  if (!SD.begin()) {
    Serial.println("Card initialization failed!");
    return;
  }
  Serial.println("Card initialization done.");
}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  File dataFile = SD.open("DHT11Log.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Humidity: ");
    dataFile.print(h);
    dataFile.print(" %\t");
    dataFile.print("Temperature: ");
    dataFile.print(t);
    dataFile.println(" *C");
    dataFile.close();
  } else {
    Serial.println("Error opening datalog.txt");
  }
}
```

### links

- <https://randomnerdtutorials.com/guide-to-sd-card-module-with-arduino/>
- <https://lastminuteengineers.com/arduino-micro-sd-card-module-tutorial/>
- <http://lab.dejaworks.com/arduino-nano-sd-card-connection/>
