#ifndef TSL2581IMPLEMENTATION_H
#define TSL2581IMPLEMENTATION_H

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

struct TSL2561Result
{
    int luminosity;
    bool error;
};

class TSL2561Implementation
{
private:
    Adafruit_TSL2561_Unified tsl;

public:
    TSL2561Implementation();

    void displaySensorDetails();
    void testConnection();

    void configureSensor();
    TSL2561Result getData();
};

#endif