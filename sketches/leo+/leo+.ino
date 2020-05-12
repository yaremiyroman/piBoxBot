#include <Adafruit_Sensor.h>
#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

struct sensor DHT_22_1 = { 2, "dht_22_1" };

DHT dht_22_1(DHT_22_1.pin, DHT22);

void setup() {
  Serial.begin(9600);
  
  pinMode(DHT_22_1.pin, INPUT);
  dht_22_1.begin();
  
  Serial.println();
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(temp);
    Serial.print("=");
    Serial.print(humidity);
    delay(PAUSE);
    Serial.print("||");
  }
}

void d_out(String label, float val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    Serial.print("||");
  }
}

void a_out(String label, int val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    Serial.print("||");
  }
}

void loop_start() {
  delay(PAUSE);
  Serial.print("||");
}

void loop_end() {
  Serial.println();
  delay(REST);
}

void loop() {
  loop_start();

  dht_out(DHT_22_1.label, dht_22_1.readTemperature(), dht_22_1.readHumidity());

  loop_end();
}
