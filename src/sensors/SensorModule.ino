#include <TSL2561Implementation.h>

#include "DHT11Implementation.h"

DHT11Implementation dht11Implementation(2);
TSL2561Implementation tsl2561Implementation;

void setup()
{
    Serial.begin(9600);
    tsl2561Implementation.configureSensor();
}

void loop()
{

    DHT11Result dht11Result = dht11Implementation.getData();
    if (dht11Result.error)
    {
        Serial.print("NaN,NaN,");
    }
    else
    {
        Serial.print(dht11Result.temperature);
        Serial.print(",");
        Serial.print(dht11Result.humidity);
        Serial.print(",");
    }

    TSL2561Result tsl2561Result = tsl2561Implementation.getData();
    if (tsl2561Result.luminosity == 0)
    {
        Serial.println("NaN");
    }
    else
    {
        Serial.print(tsl2561Result.luminosity);
        Serial.println("");
    }

    delay(2000);
}
