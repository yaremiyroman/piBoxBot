#include <stdio.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>

#define DHT2pin 7

DHT dht22(DHT2pin, DHT22);

void setup()
{
  Serial.begin(9600);// open serial port, set the baud rate to 9600 bps
}

void loop()
{
  Serial.println("=========================================");
  delay(300);

  // DHT_22 TEMPERATURE AND HUMIDITY

  float h2 = dht22.readHumidity();
  float t2 = dht22.readTemperature();

  
    Serial.print("\033[1;36mDHT_22 t\033[0m = ");
    Serial.print(t2);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h2);
    Serial.println("\033[1;32m % \033[0m");
  
  delay(300);
}
