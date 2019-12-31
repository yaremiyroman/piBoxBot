// #include <DHT.h>
// #include <LM35.h>
// #include <OneWire.h>
// #include <DallasTemperature.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;
const float MIN = 27.5;
const float MAX = 28.5;

// struct sensor RED = { 2, "red" };
struct sensor TEPLIK = { 2, "teplik" };
struct sensor FAN = { 3, "fan" };
// struct sensor DHT_22 = { 8, "DHT22" };
// struct sensor DHT_1 = { 9, "DHT_1" };
// struct sensor DHT_2 = { 10, "DHT_2" };
// struct sensor DS = { 11, "DS" };

// struct sensor LM_35 = { 5, "LM35" };

// DHT dht_22(DHT_22.pin, DHT22);
// DHT dht_1(DHT_1.pin, DHT11);
// DHT dht_2(DHT_2.pin, DHT11);
// LM35 lm_35(LM_35.pin);
// OneWire ds18b20(DS.pin);
// DallasTemperature sensors(&ds18b20);

void setup() {
  pinMode(FAN.pin, OUTPUT);
  pinMode(TEPLIK.pin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // pinMode(RED.pin, OUTPUT);

  // pinMode(DHT_22.pin, INPUT);
  // pinMode(DHT_1.pin, INPUT);
  // pinMode(DHT_2.pin, INPUT);

  digitalWrite(FAN.pin, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(TEPLIK.pin, LOW);

  // sensors.begin();
  // dht_22.begin();
  // dht_1.begin();
  // dht_2.begin();

  // Serial.begin(9600);
}

void loop() {}
