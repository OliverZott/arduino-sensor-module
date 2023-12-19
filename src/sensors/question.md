I have the following 3 files and for the h files respective implementations in cpp files.... how use them in arduino sketch in arduino ide?


// Sensor1.h
class Sensor1 {
public:
    void setup() {
        // Setup code for Sensor1
    }

    void loop() {
        // Loop code for Sensor1
    }
};



// Sensor2.h
class Sensor2 {
public:
    void setup() {
        // Setup code for Sensor2
    }

    void loop() {
        // Loop code for Sensor2
    }
};



// sensor.ino
#include "Sensor1.h"
#include "Sensor2.h"

Sensor1 sensor1;
Sensor2 sensor2;

void setup() {
    sensor1.setup();
    sensor2.setup();
}

void loop() {
    sensor1.loop();
    sensor2.loop();
}