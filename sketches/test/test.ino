#include <stdio.h>
#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 500;

struct sensor DHT11_1 = { 4, "DHT11_1" };
struct sensor DHT11_2 = { 5, "DHT11_2" };
struct sensor DHT11_3 = { 6, "DHT11_2" };
struct sensor DHT11_4 = { 7, "DHT11_2" };

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

  printSensor(DHT11_1.label, dht11_1.readTemperature(), dht11_1.readHumidity());
  printSensor(DHT11_2.label, dht11_2.readTemperature(), dht11_2.readHumidity());
  printSensor(DHT11_3.label, dht11_3.readTemperature(), dht11_3.readHumidity());
  printSensor(DHT11_4.label, dht11_4.readTemperature(), dht11_4.readHumidity());

  Serial.println();
  delay(PAUSE);
}
