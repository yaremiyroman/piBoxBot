#include <stdio.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <OneWire.h>
#include <DallasTemperature.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;                   
const int REST = 250;

struct sensor DS18B20 = { 2, "ds18b20" };
struct sensor DHT_1 = { 4, "dht_1" };
struct sensor DHT_2 = { 5, "dht_2" };
struct sensor DHT_3 = { 6, "dht_3" };
struct sensor DHT_4 = { 7, "dht_4" };

// struct sensor LM35 = { 0, "lm35" };
// struct sensor MOI = { 1, "moi" };
// struct sensor LIGHT = { 2, "light" };
// struct sensor STEAM = { 3, "steam" };

DHT dht_1(DHT_1.pin, DHT11);
DHT dht_2(DHT_2.pin, DHT11);
DHT dht_3(DHT_3.pin, DHT11);
DHT dht_4(DHT_4.pin, DHT11);
OneWire oneWire(DS18B20.pin);
DallasTemperature sensors(&oneWire);

void setup() {
  dht_1.begin();
  dht_2.begin();
  dht_3.begin();
  dht_4.begin();
  sensors.begin();

  Serial.begin(9600);
  Serial.println();
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(temp);
    Serial.print("=");
    Serial.print(humidity);
    Serial.print("||");
    delay(PAUSE);
  }
}

void d_out(String label, float val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    Serial.print("||");
    delay(PAUSE);
  }
}

void a_out(String label, int val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    Serial.print("||");
    delay(PAUSE);
  }
}

void loop() {
  delay(PAUSE);
  sensors.requestTemperatures();
  Serial.print("||");

  d_out(DS18B20.label, sensors.getTempCByIndex(0));
  dht_out(DHT_1.label, dht_1.readTemperature(), dht_1.readHumidity());
  dht_out(DHT_2.label, dht_2.readTemperature(), dht_2.readHumidity());
  dht_out(DHT_3.label, dht_3.readTemperature(), dht_3.readHumidity());
  dht_out(DHT_4.label, dht_4.readTemperature(), dht_4.readHumidity());

  // a_out(LM35.label, (analogRead(LM35.pin) / 1023) * 500);
  // a_out(MOI.label, analogRead(MOI.pin));
  // a_out(LIGHT.label, analogRead(LIGHT.pin));
  // a_out(STEAM.label, analogRead(STEAM.pin));

  Serial.println();
  delay(PAUSE);
}
