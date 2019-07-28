/* 
 * Range Test nRF24 - Receiver  
 *Oliver Zott
 * 26.06.209
 */

/* Libraries */

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
  radio.setPALevel(RF24_PA_MAX);                    //                                - set power amplifier level (for different distances) --> higher level => bypass capacitators between gnd - 3.3v for more stable voltage while operating
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
    int arr[1] = { };                           
    
    radio.read( &arr, sizeof(arr) );
    Serial.println(arr[0]);

  }
}
