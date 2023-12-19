#include <SimpleDHT.h>

// DHT11:
//  VCC: 5V or 3V
//  GND: GND
//  DATA: 2

class DHT11Implementation
{
private:
    int pinDHT11;
    SimpleDHT11 dht11;

public:
    DHT11Implementation(int pin = 2) : pinDHT11(pin) {}

    void setup()
    {
        Serial.begin(9600);
    }

    void loop()
    {

        // read with raw sample data.
        byte temperature = 0;
        byte humidity = 0;
        byte data[40] = {0};
        if (dht11.read(pinDHT11, &temperature, &humidity, data))
        {
            Serial.println("NaN,NaN");
            delay(5000);
            return;
        }

        Serial.print((int)temperature);
        Serial.print(",");
        Serial.print((int)humidity);
        Serial.println("");

        // DHT11 sampling rate is 5HZ.
        delay(5000);
    }
}
