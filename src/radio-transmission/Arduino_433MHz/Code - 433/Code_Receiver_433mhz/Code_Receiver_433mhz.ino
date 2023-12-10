/*#include <SPI.h>      // SerialInterface library ... for sending / receiving data
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
  // Set buffer to message size
  uint8_t buf[24];
  uint8_t buflen = sizeof(buf);

  // check if received message has correct size
  if (rf_driver.recv(buf, &buflen)) {
    Serial.print("Message received: ");
    Serial.println((char*)buf);
  } else {
    Serial.println("Error: Wrong Buffer Size");
  }
}
*/

// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
 
void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[1];
    uint8_t buflen = sizeof(buf);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      Serial.print("Message Received: ");
      Serial.println((char*)buf);         
    }
}
