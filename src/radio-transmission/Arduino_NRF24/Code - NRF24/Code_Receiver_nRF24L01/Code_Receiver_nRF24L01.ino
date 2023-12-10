/* Projekt1-0.3 NRF24L01 Receiver TEST  
 * 1. MEGA2560 as Transmitter         - wip
 *    
 * 2. UNO as Receiver                 -
 * 
 * 3. Transmitter+Sensors             -
 *    
 * 4. Docs and references:
 * https://tmrh20.github.io/RF24/                 - RF24 library
 * https://www.arduino.cc/en/Reference/SPI        - SPI library
 * 
 * Tutorial
 * https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/
 * https://www.youtube.com/watch?v=7rcVeFFHcFM
*/



/* 
 * =========================================================================================
 * Libraries 
 * =========================================================================================
 */

// Serial Peripheral Interface (for communication with SPI devices)
#include <SPI.h>
// NRF24 libraries
#include <nRF24L01.h>
#include <RF24.h>
// not sure yet
//#include <RF24_config.h>
//#include <printf.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printf.h"

/* 
 * --------------------------------------------------------------------------
 * Create Object & Array   (line 110 in RF24.h // 
 * --------------------------------------------------------------------------
*/

RF24 radio(7,8);    // Arguments: CNS, CE

const byte address[6] = "00001";  // Array represanting Adress (Pipe) to communication (5-letter String)



/* 
 * =========================================================================================
 * Arduino setup funtion (automatically called at startup)
 *        - Methods in "RF24.h" / "RF24.cpp"
 * =========================================================================================
 */

void setup() {
  Serial.begin(9600);
  radio.begin();                                    // lines: 137(h) / 589(cpp)       - Checks if the chip is connected to the SPI bus
  radio.openReadingPipe(0, address);                // lines: 257(h) / 1145(cpp)      - Open a pipe for reading (up to 6)
  radio.setPALevel(RF24_PA_MIN);                    //                                - set power amplifier level (for different distances) --> higher level => bypass capacitators between gnd - 3.3v for more stable voltage while operating
  radio.startListening();
}



/* 
 * =========================================================================================
 * MAIN void loop (): Arduino loop function, called once 'setup' is complete 
 * =========================================================================================
 */

void loop() {
  if (radio.available()) {

    /* create array to save incoming data */
    float arr[3] = { };                           
    
    radio.read( &arr, sizeof(arr) );
    Serial.print(arr[0]);
    Serial.print(", ");
    Serial.print(arr[1]);
    Serial.print(", ");
    Serial.println(arr[2]);

  }
}
