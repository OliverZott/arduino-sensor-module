//*
#include <SPI.h>      // SerialInterface library ... for sending / receiving data
#include <RH_ASK.h>   // Amplitude Shift Key (RadioHead)


// Create Amplitude Shift Keying Object (Class in "RH_ASK.h"-line 251 / )
RH_ASK rf_driver;



void setup() {
  // For testing purposes - Serial Output:
  Serial.begin(9600);
  // Initialize ASK Object (RH_ASK.h line:266 / RH_ASK.cpp - line:57)
  rf_driver.init();

}

void loop() {
  // Create Char of chars
  const char *msg = "p";
  // Serial.println(strlen(msg));
  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();
  //Serial.println(msg);
  delay(1000);
}
//*/


/*
#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK rf_driver;

void setup() {
    // Initialize ASK Object
    rf_driver.init();
}

void loop() {
    const char *msg = "Welcome to the Workshop!";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
}
//*/
