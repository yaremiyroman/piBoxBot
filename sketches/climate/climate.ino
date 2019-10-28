#include <stdio.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

struct sensor DHT11_1 = { 4, "dht11_1" };
struct sensor DHT11_2 = { 5, "dht11_2" };
struct sensor DHT11_3 = { 6, "dht11_3" };
struct sensor DHT11_4 = { 7, "dht11_4" };

struct sensor MOI_1 = { 0, "moisture_1" };
struct sensor MOI_2 = { 1, "moisture_2" };
struct sensor MOI_3 = { 2, "moisture_3" };
struct sensor LIGHT_1 = { 3, "light_1" };
struct sensor STEAM = { 4, "steam" };

DHT dht11_1(DHT11_1.pin, DHT11);
DHT dht11_2(DHT11_2.pin, DHT11);
DHT dht11_3(DHT11_3.pin, DHT11);
DHT dht11_4(DHT11_4.pin, DHT11);

void setup() {

  dht11_1.begin();
  dht11_2.begin();
  dht11_3.begin();
  dht11_4.begin();

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

  print_dht(DHT11_1.label, dht11_1.readTemperature(), dht11_1.readHumidity());
  print_dht(DHT11_2.label, dht11_2.readTemperature(), dht11_2.readHumidity());
  print_dht(DHT11_3.label, dht11_3.readTemperature(), dht11_3.readHumidity());
  print_dht(DHT11_4.label, dht11_4.readTemperature(), dht11_4.readHumidity());

  print_analog(MOI_1.label, analogRead(MOI_1.pin));
  print_analog(MOI_2.label, analogRead(MOI_2.pin));
  print_analog(MOI_3.label, analogRead(MOI_3.pin));
  print_analog(LIGHT_1.label, analogRead(LIGHT_1.pin));
  print_analog(STEAM.label, analogRead(STEAM.pin));

  Serial.println();
  delay(REST);
}
