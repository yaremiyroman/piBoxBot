#include <DHT.h>
#include <Adafruit_Sensor.h>5

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 50;
const int LED_OFFSET = 150;
const int REST = 1000;

//const int LED_BUILTIN = 13;

struct sensor DHT_22_1 = { 
  2, "DHT_22" };
struct sensor DHT_11_1 = { 
  3, "DHT_11" };

DHT dht_22(DHT_22_1.pin, DHT22);
DHT dht_11(DHT_11_1.pin, DHT11);

void setup() {
  pinMode(DHT_22_1.pin, INPUT);
  pinMode(DHT_11_1.pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  dht_22.begin();
  dht_11.begin();
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

  dht_out(DHT_11_1.label, dht_11.readTemperature(), dht_11.readHumidity());
  dht_out(DHT_22_1.label, dht_22.readTemperature(), dht_22.readHumidity());

  Serial.println();
  delay(REST);
}


