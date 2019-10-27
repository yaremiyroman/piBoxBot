#include <stdio.h>
// #include <OneWire.h>
// #include <DallasTemperature.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

// struct sensor DS18B20 = { 2, "ds18b20" };
struct sensor DHT11_1 = { 4, "DHT11_1" };
struct sensor DHT11_2 = { 5, "DHT11_2" };
struct sensor DHT11_3 = { 6, "DHT11_3" };
struct sensor DHT11_4 = { 7, "DHT11_4" };
// struct sensor FIRE = {8, "FIRE" };
// struct sensor LIGHT_1 = { 9, "LIGHT_1" };
// struct sensor RAIN = { 10, "RAIN" };

// struct sensor LIGHT_2 = { 0, "light_2" };
// struct sensor LIQUID = { 1,  "liquid_lvl" };
// struct sensor STEAM = { 2,  "steam_1" };
// struct sensor MOISTURE_1 = { 3, "moisture_1" };
// struct sensor MOISTURE_2 = { 4, "moisture_2" };
// struct sensor MOISTURE_3 = { 5, "moisture_3" };
// struct sensor HALL = { 6,  "hall" };

// OneWire oneWire(DS18B20.pin);
// DallasTemperature sensors(&oneWire);
DHT dht11_1(DHT11_1.pin, DHT11);
DHT dht11_2(DHT11_2.pin, DHT11);
DHT dht11_3(DHT11_3.pin, DHT11);
DHT dht11_4(DHT11_4.pin, DHT11);

void setup() {
  Serial.begin(9600);

  // sensors.begin();

  dht11_1.begin();
  dht11_2.begin();
  dht11_3.begin();
  dht11_4.begin();

  Serial.println();
}

void printSensor(String label, float val, float val2 = NAN) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    if (isfinitef(val2)) {
      Serial.print("=");
      Serial.print(val2);
    }
    Serial.print(" || ");
    delay(PAUSE);
  }
}

void loop() {
  delay(PAUSE);
  // sensors.requestTemperatures();

  // printSensor(DS18B20.label, sensors.getTempCByIndex(0));
   printSensor(DHT11_1.label, dht11_1.readTemperature(), dht11_1.readHumidity());
   printSensor(DHT11_2.label, dht11_2.readTemperature(), dht11_2.readHumidity());
   printSensor(DHT11_3.label, dht11_3.readTemperature(), dht11_3.readHumidity());
   printSensor(DHT11_4.label, dht11_4.readTemperature(), dht11_4.readHumidity());
  // printSensor(FIRE.label, digitalRead(FIRE.pin));
  // printSensor(LIGHT_1.label, digitalRead(LIGHT_1.pin));
  // printSensor(RAIN.label, digitalRead(RAIN.pin));

  // printSensor(MOISTURE_1.label, analogRead(MOISTURE_1.pin));
  // printSensor(MOISTURE_2.label, analogRead(MOISTURE_2.pin));
  // printSensor(MOISTURE_3.label, analogRead(MOISTURE_3.pin));
  // printSensor(STEAM.label, analogRead(STEAM.pin));
  // printSensor(LIQUID.label, analogRead(LIQUID.pin));
  // printSensor(LIGHT_2.label, analogRead(LIGHT_2.pin));

  Serial.println();
  delay(REST);
}
