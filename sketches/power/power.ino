#include <DHT.h>
#include <LM35.h>
#include <OneWire.h>
#include <DallasTemperature.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;
const float MIN = 27.5;
const float MAX = 28.5;

struct sensor RED = { 2, "red" };
struct sensor GREEN = { 3, "green" };
struct sensor DHT_22 = { 8, "DHT22" };
struct sensor DHT_1 = { 9, "DHT_1" };
struct sensor DHT_2 = { 10, "DHT_2" };
struct sensor DS = { 11, "DS" };
struct sensor TEPLIK = { 12, "teplik" };

struct sensor LM_35 = { 5, "LM35" };

DHT dht_22(DHT_22.pin, DHT22);
DHT dht_1(DHT_1.pin, DHT11);
DHT dht_2(DHT_2.pin, DHT11);
LM35 lm_35(LM_35.pin);
OneWire ds18b20(DS.pin);
DallasTemperature sensors(&ds18b20);

void setup() {
  pinMode(GREEN.pin, OUTPUT);
  pinMode(RED.pin, OUTPUT);
  pinMode(TEPLIK.pin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(DHT_22.pin, INPUT);
  pinMode(DHT_1.pin, INPUT);
  pinMode(DHT_2.pin, INPUT);

  digitalWrite(GREEN.pin, LOW);
  digitalWrite(RED.pin, LOW);
  digitalWrite(TEPLIK.pin, LOW);

  sensors.begin();
  dht_22.begin();
  dht_1.begin();
  dht_2.begin();

  Serial.begin(9600);
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print(" >>> t = ");
    Serial.print(temp);
    Serial.print("° > h = ");
    Serial.print(humidity);
    Serial.println(" %");
  }
}

void out(String label, float val, String prefix, String postfix) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print(" >>> ");
    Serial.print(prefix);
    Serial.print(" = ");
    Serial.print(val);
    Serial.println(postfix);
  }
}

void loop() {
  delay(PAUSE);
  float dht_22_t = dht_22.readTemperature();
  delay(PAUSE);
  float dht_22_h = dht_22.readHumidity();
  delay(PAUSE);
  float dht_1_t = dht_1.readTemperature();
  delay(PAUSE);
  float dht_1_h = dht_1.readHumidity();
  delay(PAUSE);
  float dht_2_t = dht_2.readTemperature();
  delay(PAUSE);
  float dht_2_h = dht_2.readHumidity();
  delay(PAUSE);
  float lm_35_t = lm_35.cel();
  delay(PAUSE);
  sensors.requestTemperatures();
  float ds18b20_t = sensors.getTempCByIndex(0);

  float T = (dht_22_t + dht_1_t + dht_2_t + lm_35_t + ds18b20_t) / 5;
  float H = (dht_22_h + dht_1_h + dht_2_h) / 3;

  Serial.print(" T = ");
  Serial.print(T);
  Serial.print("°  H = ");
  Serial.print(H);
  Serial.println(" %");

  int heating = digitalRead(TEPLIK.pin);
  
  if (T < MIN && heating == LOW) {
    digitalWrite(TEPLIK.pin, HIGH);
    digitalWrite(GREEN.pin , LOW);
    digitalWrite(RED.pin, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
  if (T > MAX && heating == HIGH) {
    digitalWrite(TEPLIK.pin, LOW);
    digitalWrite(GREEN.pin, HIGH);
    digitalWrite(RED.pin , LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
