#include "DHT11Implementation.h"

DHT11Implementation dht11Implementation(2);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    DHT11Result dht11Result = dht11Implementation.getData();
    if (dht11Result.error)
    {
        Serial.println("NaN,NaN SFDFGHDE");
    }

    Serial.print(dht11Result.temperature);
    Serial.print(",");
    Serial.print(dht11Result.humidity);
    Serial.println("");
}