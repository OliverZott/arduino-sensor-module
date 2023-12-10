/* Range Test for nRF24 */

#include <SimpleDHT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

// Serial Peripheral Interface (for communication with SPI devices)
#include <SPI.h>
// NRF24 libraries
#include <nRF24L01.h>
#include <RF24.h>

/*
// not sure yet (delete in case of error)
#include <RF24_config.h>
#include <printf.h>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* 2.4Ghz Transmitter (RF24L01) */
RF24 radio(7,8);    // Create Object & Array (line 110 in RF24.h / Arguments: CNS, CE)
const byte address[6] = "00001";  // Array represanting Adress (Pipe) to communication (5-letter String)


/* Arduino setup funtion (automatically called at startup) */
void setup(void) 
{
  Serial.begin(9600);
  /* Configure RF24L01 Transceiver */
  radio.begin();                                    // lines: 137(h) / 589(cpp)       - Checks if the chip is connected to the SPI bus
  radio.openWritingPipe(address);                   // lines: 257(h) / 1145(cpp)      - Open a pipe for reading (up to 6)
  radio.setPALevel(RF24_PA_MAX);                    // lines: 31(h) / 1434 (cpp)      - set power amplifier level (for different distances) --> higher level => bypass capacitators between gnd - 3.3v for more stable voltage while operating
  radio.stopListening();

  /* Signal start of Testing */
  // Serial.println("Start testing by sending count increasing in each second:");
  
}


/*
 * =================================================================================================================
 * MAIN void loop (): Arduino loop function, called once 'setup' is complete (Code goes here)
 * =================================================================================================================
 */

void loop() {
  
    while(true) {
      int arr[1] = {};
      for (int i = 1; i < 21; i++) {
        arr[0] = i;
        Serial.println(arr[0]);
        radio.write(&arr, sizeof(arr));            
        delay(1000);
      }
      delay(5000);
    }
     
}
