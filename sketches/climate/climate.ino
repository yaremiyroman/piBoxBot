#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;
const int REST = 250;

struct sensor DHT_1 = { 4, "dht1" };
struct sensor DHT_2 = { 5, "dht2" };
struct sensor DHT_3 = { 6, "dht3" };
struct sensor DHT_4 = { 7, "dht4" };

DHT dht_1(DHT_1.pin, DHT11);
DHT dht_2(DHT_2.pin, DHT11);
DHT dht_3(DHT_3.pin, DHT11);
DHT dht_4(DHT_4.pin, DHT11);

void setup() {
  dht_1.begin();
  dht_2.begin();
  dht_3.begin();
  dht_4.begin();

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

void loop() {
  delay(250);
  Serial.print("||");

  dht_out(DHT_1.label, dht_1.readTemperature(), dht_1.readHumidity());
  dht_out(DHT_2.label, dht_2.readTemperature(), dht_2.readHumidity());
  dht_out(DHT_3.label, dht_3.readTemperature(), dht_3.readHumidity());
  dht_out(DHT_4.label, dht_4.readTemperature(), dht_4.readHumidity());

  Serial.println();
  delay(PAUSE);
}
