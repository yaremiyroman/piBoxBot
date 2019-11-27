#include <stdio.h>
#include <DHT.h>
#include <OneWire.h>
#include <Adafruit_Sensor.h>
#include <DallasTemperature.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;                   
const int REST = 250;

struct sensor PIRAHNIA = { 2, "green_led" };
struct sensor DS18B20 = { 3, "ds18b20" };
struct sensor DHT_1 = { 4, "dht_1" };
struct sensor DHT_2 = { 5, "dht_2" };
struct sensor DHT_3 = { 6, "dht_3" };
struct sensor DHT_4 = { 7, "dht_4" };
struct sensor DHT_5 = { 8, "dht_5" };
struct sensor DHT_6 = { 9, "dht_6" };
struct sensor DHT_7 = { 10, "dht_7" };
struct sensor DHT_8 = { 11, "dht_8" };
//struct sensor PIRAHNIA = { 12, "green_led" };
struct sensor FIRE = { 13, "fire" };

struct sensor MOI = { 0, "moi" };
struct sensor LIGHT = { 1, "light" };
struct sensor STEAM = { 2, "steam" };
struct sensor LM35 = { 3, "lm35" };

DHT dht_1(DHT_1.pin, DHT11);
DHT dht_2(DHT_2.pin, DHT11);
DHT dht_3(DHT_3.pin, DHT11);
DHT dht_4(DHT_4.pin, DHT11);
DHT dht_5(DHT_5.pin, DHT11);
DHT dht_6(DHT_6.pin, DHT11);
DHT dht_7(DHT_7.pin, DHT11);
DHT dht_8(DHT_8.pin, DHT11);
OneWire oneWire(DS18B20.pin);
DallasTemperature sensors(&oneWire);

void setup() {
  dht_1.begin();
  dht_2.begin();
  dht_3.begin();
  dht_4.begin();
  dht_5.begin();
  dht_6.begin();
  dht_7.begin();
  dht_8.begin();
  sensors.begin();

  pinMode(PIRAHNIA.pin, OUTPUT);

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
  dht_out(DHT_5.label, dht_5.readTemperature(), dht_5.readHumidity());
  dht_out(DHT_6.label, dht_6.readTemperature(), dht_6.readHumidity());
  dht_out(DHT_7.label, dht_7.readTemperature(), dht_7.readHumidity());
  dht_out(DHT_8.label, dht_8.readTemperature(), dht_8.readHumidity());   
  d_out(FIRE.label, digitalRead(FIRE.pin));

  delay(REST);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(REST);

  a_out(MOI.label, analogRead(MOI.pin));
  a_out(LIGHT.label, analogRead(LIGHT.pin));
  a_out(STEAM.label, analogRead(STEAM.pin));
  a_out(LM35.label, (analogRead(LM35.pin) / 1023) * 500);

  delay(REST);
  digitalWrite(LED_BUILTIN, LOW);
  delay(REST);

  Serial.println();
  delay(PAUSE);
}
