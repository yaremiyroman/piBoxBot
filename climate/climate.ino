#include <DHT.h>
#include <Adafruit_Sensor.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 250;
const int REST = 5000;

struct sensor DHT_11_1 = { 4, "dht11.a" };
struct sensor DHT_11_2 = { 5, "dht11.b" };

struct sensor DHT_22_1 = { 2, "dht22.a" };
struct sensor DHT_22_2 = { 3, "dht22.b" };

DHT dht_11_1(DHT_11_1.pin, DHT11);
DHT dht_11_2(DHT_11_2.pin, DHT11);

DHT dht_22_1(DHT_22_1.pin, DHT22);
DHT dht_22_2(DHT_22_2.pin, DHT22);

void setup() {
  Serial.begin(9600);

  pinMode(DHT_11_1.pin, INPUT);
  pinMode(DHT_11_2.pin, INPUT);

  pinMode(DHT_22_1.pin, INPUT);
  pinMode(DHT_22_2.pin, INPUT);

  dht_11_1.begin();
  dht_11_2.begin();

  dht_22_2.begin();
  dht_22_1.begin();

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
  
  dht_out(DHT_11_1.label, dht_11_1.readTemperature(), dht_11_1.readHumidity());
  dht_out(DHT_11_2.label, dht_11_2.readTemperature(), dht_11_2.readHumidity());
  Serial.println();

  dht_out(DHT_22_1.label, dht_22_1.readTemperature(), dht_22_1.readHumidity());
  dht_out(DHT_22_2.label, dht_22_2.readTemperature(), dht_22_2.readHumidity());
  Serial.println();

  Serial.println();
  Serial.println();
  delay(PAUSE);
}
