#include <stdio.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DallasTemperature.h>
#include <OneWire.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

struct sensor DS18B20 = { 4, "ds18b20" };
struct sensor DHT_11 = { 5, "dht11_1" };

struct sensor MOI_1 = { 0, "moi_1" };
struct sensor MOI_2 = { 1, "moi_2" };
struct sensor RAIN = { 2, "rain" };
struct sensor LIQUID = { 3, "liquid" };
struct sensor MOI_3 = { 4, "moi_3" };
//struct sensor MOI_3 = { 5, "moisture_3" };
struct sensor LIGHT = { 6, "light" };
struct sensor STEAM = { 7, "steam" };

DHT dht11(DHT_11.pin, DHT11);

void setup() {
  dht11.begin();

  Serial.begin(9600);
  Serial.println();
}

void print_dht(String label, float val, float val2 = NAN) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    if (isfinitef(val2)) {
      Serial.print("=");
      Serial.print(val2);
    }
    delay(PAUSE);
    Serial.print("||");
  }
}

void print_analog(String label, int val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    Serial.print("||");
  }
}

void loop() {
  delay(PAUSE);
  Serial.print("||");

  print_dht(DHT_11.label, dht11.readTemperature(), dht11.readHumidity());

  print_analog(MOI_1.label, analogRead(MOI_1.pin));
  print_analog(MOI_2.label, analogRead(MOI_2.pin));
  print_analog(RAIN.label, analogRead(RAIN.pin));
  print_analog(LIQUID.label, analogRead(LIQUID.pin));
  print_analog(MOI_3.label, analogRead(MOI_3.pin));
  //  print_analog(MOI_1.label, analogRead(MOI_1.pin));
  print_analog(LIGHT.label, analogRead(LIGHT.pin));
  print_analog(STEAM.label, analogRead(STEAM.pin));

  Serial.println();
  delay(REST);
}
