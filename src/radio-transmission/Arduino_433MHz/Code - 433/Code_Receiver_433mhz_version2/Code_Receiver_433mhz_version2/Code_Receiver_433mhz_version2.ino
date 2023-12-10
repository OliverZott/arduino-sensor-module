#include <VirtualWire.h>

#include<VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN];           // buffer to store incoming message
byte messageLength = VW_MAX_MESSAGE_LEN;    // size of msg buffer


void setup() {
  Serial.begin(9600);
  Serial.println("Device is ready...");
  
  vw_set_rx_pin(12);
  vw_setup(1000);   // bps
  vw_rx_start();

}

void loop() {
  if(vw_get_message(message, &messageLength)) // non blocking
  {
    Serial.print("Received: ");
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.println();
  }
}
