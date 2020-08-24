#include <DHT.h>
#include <Adafruit_Sensor.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 250;
const int REST = 5000;

struct sensor DHT11a = { 4, "dht11.a" };
struct sensor DHT11b = { 5, "dht11.b" };
struct sensor DHT11c = { 6, "dht11.c" };
struct sensor DHT11d = { 7, "dht11.d" };

struct sensor DHT22a = { 8, "dht22.a" };
struct sensor DHT22b = { 9, "dht22.b" };

struct sensor DHT11e = { 4, "dht11.a" };
struct sensor DHT11f = { 5, "dht11.b" };
struct sensor DHT11g = { 6, "dht11.c" };
struct sensor DHT11h = { 7, "dht11.d" };

DHT dht11a(DHT11a.pin, DHT11);
DHT dht11b(DHT11b.pin, DHT11);
DHT dht11c(DHT11c.pin, DHT11);
DHT dht11d(DHT11d.pin, DHT11);

DHT dht22a(DHT22a.pin, DHT22);
DHT dht22b(DHT22b.pin, DHT22);

DHT dht11e(DHT11e.pin, DHT11);
DHT dht11f(DHT11f.pin, DHT11);
DHT dht11g(DHT11g.pin, DHT11);
DHT dht11h(DHT11h.pin, DHT11);

void setup() {
  Serial.begin(9600);

  pinMode(DHT11a.pin, INPUT);
  pinMode(DHT11b.pin, INPUT);
  pinMode(DHT11c.pin, INPUT);
  pinMode(DHT11d.pin, INPUT);

  pinMode(DHT11e.pin, INPUT);
  pinMode(DHT11f.pin, INPUT);
  pinMode(DHT11g.pin, INPUT);
  pinMode(DHT11h.pin, INPUT);

  pinMode(DHT22a.pin, INPUT);
  pinMode(DHT22b.pin, INPUT);

  dht11a.begin();
  dht11b.begin();
  dht11c.begin();
  dht11d.begin();

  dht11e.begin();
  dht11f.begin();
  dht11g.begin();
  dht11h.begin();

  dht22a.begin();
  dht22b.begin();

  Serial.println();
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print(" >  ");
    Serial.print(temp);
    // Serial.print("℃  ");
    Serial.print("*C  ");
    Serial.print(humidity);
    Serial.print("%");
    Serial.println();
    delay(REST);
  } else {
    Serial.print(label);
    Serial.print(" >  error");
    Serial.println();
  }
}

void loop() {
  Serial.print("**************************************************************************");
  delay(REST);
  Serial.println();
  Serial.print("*** CLIMATE **********************************************************");
  Serial.println();
  Serial.println();
  
  dht_out(DHT11a.label, dht11a.readTemperature(), dht11a.readHumidity());
  dht_out(DHT11b.label, dht11b.readTemperature(), dht11b.readHumidity());
  dht_out(DHT11c.label, dht11c.readTemperature(), dht11c.readHumidity());
  dht_out(DHT11d.label, dht11d.readTemperature(), dht11d.readHumidity());
  Serial.println();

  dht_out(DHT11e.label, dht11e.readTemperature(), dht11e.readHumidity());
  dht_out(DHT11f.label, dht11f.readTemperature(), dht11f.readHumidity());
  dht_out(DHT11g.label, dht11g.readTemperature(), dht11g.readHumidity());
  dht_out(DHT11h.label, dht11h.readTemperature(), dht11h.readHumidity());
  Serial.println();

  dht_out(DHT22a.label, dht22a.readTemperature(), dht22a.readHumidity());
  dht_out(DHT22b.label, dht22b.readTemperature(), dht22b.readHumidity());
  Serial.println();

  Serial.println();
  Serial.println();
  delay(PAUSE);
}
