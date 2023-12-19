#ifndef DHT11IMPLEMENTATION_H
#define DHT11IMPLEMENTATION_H

#include <SimpleDHT.h>

class DHT11Implementation
{
private:
    int pinDHT11;
    SimpleDHT11 dht11;

public:
    DHT11Implementation(int pin);
    void loop;
    void setup;
}

#endif DHT11IMPLEMENTATION_H