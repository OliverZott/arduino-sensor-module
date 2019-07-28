#include <VirtualWire.h>


void setup() {
  Serial.begin(9600);

  // virtual wire
  vw_set_tx_pin(12);  // set pin
  vw_setup(1000);     // bps bits per second - min=1000 (lower = more range)

}


void sendString(String message, bool wait) {
  byte messageLength = message.length() + 1;    // stores length in chars

  // converting string to char array
  char charBuffer[messageLength];
  message.toCharArray(charBuffer, messageLength);

  vw_send((uint8_t *)charBuffer, messageLength);

  if (wait)vw_wait_tx();

  Serial.println("sent:" + message);
}


void loop() {
  sendString("message", true);  // true.. methode waits till message was send, else code will continue
  delay(100);

}
