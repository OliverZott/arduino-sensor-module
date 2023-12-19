#ifndef DHT11IMPLEMENTATION_H
#define DHT11IMPLEMENTATION_H

#include <SimpleDHT.h>

struct DHT11Result
{
    int temperature;
    int humidity;
    bool error;
};

class DHT11Implementation
{
private:
    int pinDHT11;
    SimpleDHT11 dht11;

public:
    DHT11Implementation(int pin);
    DHT11Result getData();
};

#endif