#include <DHT.h>
#include <Adafruit_Sensor.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 50;
const int LED_OFFSET = 150;
const int REST = 1000;

const int LED_BUILTIN = 13;

struct sensor DHT_22_1 = { 2, "DHT_22_1" };
struct sensor DHT_22_2 = { 3, "DHT_22_2" };
struct sensor DHT_11_1 = { 3, "DHT_11_1" };
struct sensor DHT_11_2 = { 4, "DHT_11_2" };
struct sensor DHT_11_3 = { 5, "DHT_11_3" };
struct sensor DHT_11_4 = { 6, "DHT_11_4" };

DHT dht_22_1(DHT_22_1.pin, DHT22);
DHT dht_22_2(DHT_22_2.pin, DHT22);
DHT dht_11_1(DHT_11_1.pin, DHT11);
DHT dht_11_2(DHT_11_2.pin, DHT11);
DHT dht_11_3(DHT_11_3.pin, DHT11);
DHT dht_11_4(DHT_11_4.pin, DHT11);

void setup() {
  pinMode(DHT_22_1.pin, INPUT);
  pinMode(DHT_22_2.pin, INPUT);
  pinMode(DHT_11_1.pin, INPUT);
  pinMode(DHT_11_2.pin, INPUT);
  pinMode(DHT_11_3.pin, INPUT);
  pinMode(DHT_11_4.pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  dht_22_1.begin();
  dht_22_2.begin();
  dht_11_1.begin();
  dht_11_2.begin();
  dht_11_3.begin();
  dht_11_4.begin();
  digitalWrite(LED_BUILTIN, LOW);  

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
    Serial.println();
    delay(REST);
  }
}

void loop() {
  delay(PAUSE);
  Serial.print("************************");
  Serial.println();

  digitalWrite(LED_BUILTIN, HIGH);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, LOW);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, LOW);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, LOW);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, LOW);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(LED_OFFSET);
  digitalWrite(LED_BUILTIN, LOW);
  delay(LED_OFFSET);

  dht_out(DHT_22_1.label, dht_22_1.readTemperature(), dht_22_1.readHumidity());
  dht_out(DHT_22_2.label, dht_22_2.readTemperature(), dht_22_2.readHumidity());
  dht_out(DHT_11_1.label, dht_11_1.readTemperature(), dht_11_1.readHumidity());
  dht_out(DHT_11_2.label, dht_11_2.readTemperature(), dht_11_2.readHumidity());
  dht_out(DHT_11_3.label, dht_11_3.readTemperature(), dht_11_3.readHumidity());
  dht_out(DHT_11_4.label, dht_11_4.readTemperature(), dht_11_4.readHumidity());

  Serial.println();
  delay(REST);
}


