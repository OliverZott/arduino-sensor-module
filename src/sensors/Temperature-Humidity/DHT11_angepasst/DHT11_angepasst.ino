/* Projekt-0.1 Temp/Hum  
 * 1. DHT11 implementieren
 * 2. Python for serial communication
 * 
 * Based on:
 * www.elegoo.com
 * 2016.12.9
*/

#include <SimpleDHT.h>

// DHT11:
//  VCC: 5V or 3V
//  GND: GND
//  DATA: 2

int pinDHT11 = 2;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.print("Sample RAW Bits: ");
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);             // was is 'data' ???
    if (i > 0 && ((i + 1) % 4) == 0) {      // macht Abstand zwischen 4er Gruppen
      Serial.print(' '); 
    }
  }
  Serial.println("");
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  
  // DHT11 sampling rate is 5HZ.
  delay(5000);
}
