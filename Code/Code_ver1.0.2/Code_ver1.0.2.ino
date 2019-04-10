/* Projekt-0.2 Temp/Hum + Lux  
 * 1. DHT11 implementieren            - done
 *    1.1. Sensor information         - 
 *    
 * 2. Python for serial communication - done
 * 
 * 3. TSL 2561 implementieren         - wip
 *    3.1. Sensor information         - done
 *    
 * 4. Pthon anpassen                  - wip
 * 
*/

// https://www.arduino.cc/en/Reference/Wire






#include <SimpleDHT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>


/* 
 * =========================================================================================
 * Temperatur & Humidity Modul (DHT11)
 * =========================================================================================
 */

// library: <SimpleDHT.h>
// DHT11:
//  VCC: 5V or 3V
//  GND: GND
//  DATA: 2

int pinDHT11 = 2;
SimpleDHT11 dht11;

/* 
 * =========================================================================================
 * Luxmeter Modul (TSL 2561)
 * =========================================================================================
 */
 
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

/* 
 * --------------------------------------------------------------------------
 * Display some basic information
 * --------------------------------------------------------------------------
*/
void displaySensorDeteils(void) {
  sensor_t sensor;
  tsl.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" lux");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" lux");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" lux");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}
/* 
 * --------------------------------------------------------------------------
 * Configures the gain and integration time for the TSL2561
 * --------------------------------------------------------------------------
*/
void configureSensor(void) {
  /* You can also manually set the gain or enable auto-gain support */
  // tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation*/
  // tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity*/
  tsl.enableAutoRange(true);            /* Auto-gain ... switches automatically between 1x and 16x */
  
  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */

  /* Update these values depending on what you've set above! */  
  //Serial.println("------------------------------------");
  //Serial.print  ("Gain:         "); Serial.println("Auto");
  //Serial.print  ("Timing:       "); Serial.println("13 ms");
  //Serial.println("------------------------------------");
}

/* 
 * =========================================================================================
 * Arduino setup funtion (automatically called at startup)
 * =========================================================================================
 */

void setup(void) 
{
  Serial.begin(9600);
  //Serial.println("Light Sensor Test"); Serial.println("");

  /* Initializing Sensor */
  if(!tsl.begin()){
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.print("Ooops, no TSL2561 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }

  //displaySensorDeteils();
  configureSensor();
  
}


/* 
 * =========================================================================================
 * MAIN void loop (): Arduino loop function, called once 'setup' is complete (COde goes here)
 * =========================================================================================
 */

void loop() {

/* 
 * --------------------------------------------------------------------------
 * Temperatur/Humidity
 * --------------------------------------------------------------------------
*/
   
  // read with raw sample data.
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  // Output: Sample Bits
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);             // byte data[40] in dht11.h / 
    if (i > 0 && ((i + 1) % 4) == 0) {      // macht Abstand zwischen 4er Gruppen
      Serial.print(' '); 
    }
  }
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.print(" %, ");
  
  
  


/* 
 * --------------------------------------------------------------------------
 * Luxmeter
 * --------------------------------------------------------------------------
*/

  sensors_event_t event;
  tsl.getEvent(&event);

  if (event.light) {
    Serial.print(event.light); Serial.println(" lux");
  }
  
  

  //  sampling rate is 0.2HZ (DHT11 / TSL2561)
  delay(5000);
}






















