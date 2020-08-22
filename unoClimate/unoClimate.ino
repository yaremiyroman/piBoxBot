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

DHT dht11a(DHT11a.pin, DHT11);
DHT dht11b(DHT11b.pin, DHT11);
DHT dht11c(DHT11c.pin, DHT11);
DHT dht11d(DHT11d.pin, DHT11);

DHT dht22a(DHT22a.pin, DHT22);
DHT dht22b(DHT22b.pin, DHT22);

void setup() {
  Serial.begin(9600);

  pinMode(DHT11a.pin, INPUT);
  pinMode(DHT11b.pin, INPUT);
  pinMode(DHT11c.pin, INPUT);
  pinMode(DHT11d.pin, INPUT);

  pinMode(DHT22a.pin, INPUT);
  pinMode(DHT22b.pin, INPUT);

  dht11a.begin();
  dht11b.begin();
  dht11c.begin();
  dht11d.begin();

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

// void a_out(String label, int val) {
//   if (isfinitef(val)) {
//     Serial.print(label);
//     Serial.print("=");
//     Serial.print(val);
//     delay(PAUSE);
//     // Serial.print("||");
//   }
// }

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

  dht_out(DHT22a.label, dht22a.readTemperature(), dht22a.readHumidity());
  dht_out(DHT22b.label, dht22b.readTemperature(), dht22b.readHumidity());
  Serial.println();

  Serial.println();
  Serial.println();
  delay(PAUSE);
}
