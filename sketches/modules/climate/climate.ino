#include <stdio.h>
#include <math.h>
#include <OneWire.h>
#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

////////////////////////////////////////////////////////////////////////
// DIGITAL
////////////////////////////////////////////////////////////////////////

struct sensor DS18B20 = { 2, "DS18b20" };
OneWire ds(DS18B20.pin);
// struct sensor DHT22_1 = { 3, "DHT22_1" };

struct sensor DHT11_1 = { 4, "DHT11_1" };
DHT dht11_1(DHT11_1.pin, DHT11);
struct sensor DHT11_2 = { 5, "DHT11_2" };
DHT dht11_2(DHT11_2.pin, DHT11);
struct sensor DHT11_3 = { 6, "DHT11_3" };
DHT dht11_3(DHT11_3.pin, DHT11);
struct sensor DHT11_4 = { 7, "DHT11_4" };
DHT dht11_4(DHT11_4.pin, DHT11);

struct sensor FIRE = {8, "FIRE" };
struct sensor LIGHT_1 = { 9, "LIGHT_1" };
struct sensor RAIN = { 10, "RAIN" };

////////////////////////////////////////////////////////////////////////
// ANALOGUE
////////////////////////////////////////////////////////////////////////

struct sensor LIGHT_2 = { 0, "light_2" };
struct sensor LIQUID = { 1,  "liquid_lvl" };
struct sensor STEAM = { 2,  "steam_1 " };

struct sensor MOUSTURE_1 = { 3, "mousture_1" };
struct sensor MOUSTURE_2 = { 4, "mousture_2" };
struct sensor MOUSTURE_3 = { 5, "mousture_3" };

struct sensor HALL = { 6,  "hall" };

////////////////////////////////////////////////////////////////////////
// SETTINGS
////////////////////////////////////////////////////////////////////////

const int PAUSE = 1000;
const int INTERVAL = 2000;
const int REST = 10000;

////////////////////////////////////////////////////////////////////////
// FUNCS
////////////////////////////////////////////////////////////////////////

float getDS18B20Temp() {
  byte data[12];
  byte addr[8];

  if (!ds.search(addr)) {
    ds.reset_search();
    return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Device is not recognized");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);

  ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad

  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;
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

    Serial.print(">>>");
    delay(PAUSE);
  }
}

void setup() {
  pinMode(DS18B20.pin, OUTPUT);

  // pinMode(DHT22_1.pin, OUTPUT);
  // dht22_1.begin();

  pinMode(DHT11_1.pin, OUTPUT);
  dht11_1.begin();

  pinMode(DHT11_2.pin, OUTPUT);
  dht11_2.begin();

  pinMode(DHT11_3.pin, OUTPUT);
  dht11_3.begin();

  pinMode(DHT11_4.pin, OUTPUT);
  dht11_4.begin();

  pinMode(FIRE.pin, OUTPUT);
  pinMode(LIGHT_1.pin, OUTPUT);
  pinMode(RAIN.pin, OUTPUT);

  Serial.begin(9600);
}

////////////////////////////////////////////////////////////////////////
// RUN
////////////////////////////////////////////////////////////////////////

void loop() {
  // START LOOP
  delay(INTERVAL);

  // DS18B20
  float ds18b20 = getDS18B20Temp();
  printSensor(DS18B20.label, ds18b20);

  // DHT22_1
  // printSensor(DHT22_1.label, dht22_1.readTemperature(), dht22_1.readHumidity());

  // DHT11_1
  printSensor(DHT11_1.label, dht11_1.readTemperature(), dht11_1.readHumidity());

  // DHT11_2
  printSensor(DHT11_2.label, dht11_2.readTemperature(), dht11_2.readHumidity());

  // DHT11_3
  printSensor(DHT11_3.label, dht11_3.readTemperature(), dht11_3.readHumidity());

  // DHT11_4
  printSensor(DHT11_4.label, dht11_4.readTemperature(), dht11_4.readHumidity());

  // FIRE
  printSensor(FIRE.label, digitalRead(FIRE.pin));

  // LIGHT_1
  printSensor(LIGHT_1.label, digitalRead(LIGHT_1.pin));

  // RAIN
  printSensor(RAIN.label, digitalRead(RAIN.pin));




  // MOUSTURE_1
  float mousture_1 = analogRead(MOUSTURE_1.pin);
  printSensor(MOUSTURE_1.label, mousture_1);

  // MOUSTURE_2
  float mousture_2 = analogRead(MOUSTURE_2.pin);
  printSensor(MOUSTURE_2.label, mousture_2);

  // MOUSTURE_3
  float mousture_3 = analogRead(MOUSTURE_3.pin);
  printSensor(MOUSTURE_3.label, mousture_3);

  // STEAM
  float steam = analogRead(STEAM.pin);
  printSensor(STEAM.label, steam);

  // LIQUID LEVEL
  float liquid = analogRead(LIQUID.pin);
  printSensor(LIQUID.label, liquid);

  // ANALOG AMBIENT LIGHT
  float light_2 = analogRead(LIGHT_2.pin);
  printSensor(LIGHT_2.label, light_2);

  // END LOOP
  Serial.println();
  delay(REST);
}
