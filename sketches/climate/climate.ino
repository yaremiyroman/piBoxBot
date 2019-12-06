#include <stdio.h>
#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;

struct sensor DHT_1 = { 4, "dht1" };
struct sensor DHT_2 = { 5, "dht2" };
struct sensor DHT_3 = { 6, "dht3" };
struct sensor DHT_4 = { 7, "dht4" };

DHT dht1(DHT_1.pin, DHT11);
DHT dht2(DHT_2.pin, DHT11);
DHT dht3(DHT_3.pin, DHT11);
DHT dht4(DHT_4.pin, DHT11);

void setup() {
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();

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

void loop_end() {
  
}

void loop() {
  Serial.print("||");

  dht_out(DHT_1.label, dht1.readTemperature(), dht1.readHumidity());
  dht_out(DHT_2.label, dht2.readTemperature(), dht2.readHumidity());
  dht_out(DHT_3.label, dht3.readTemperature(), dht3.readHumidity());
  dht_out(DHT_4.label, dht4.readTemperature(), dht4.readHumidity());

  Serial.println();

  delay(PAUSE);
}
