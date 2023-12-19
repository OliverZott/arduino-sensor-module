#include "DHT11Implementation.h"
#include <SimpleDHT.h>

// DHT11:
//  VCC: 5V or 3V
//  GND: GND
//  DATA: 2

DHT11Implementation::DHT11Implementation(int pin = 2) : pinDHT11(pin) {}

DHT11Result DHT11Implementation::getData()
{
    delay(5000);
    byte temperature = 0;
    byte humidity = 0;
    byte data[40] = {0};
    if (dht11.read(pinDHT11, &temperature, &humidity, data))
    {
        return {0, 0, true};
    }
    return {(int)temperature, (int)humidity};
}
