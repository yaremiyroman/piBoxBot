#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;

struct sensor DHT_2 = { 2, "dht_2" };
struct sensor DHT_3 = { 3, "dht_3" };
struct sensor btn_blue = { 7, "blue button" };
struct sensor teplik = { 8, "TEPLIK" };

DHT dht_2(DHT_3.pin, DHT11);
DHT dht_3(DHT_2.pin, DHT11);

void setup() {
  dht_2.begin();
  dht_3.begin();

  pinMode(btn_blue.pin, INPUT);
  pinMode(teplik.pin, OUTPUT);

  // Serial.begin(9600);
  // Serial.println();
}

void loop() {
  int btn_blue_status = digitalRead(btn_blue.pin);
  int teplik_status = digitalRead(teplik.pin);

  if (btn_blue_status == HIGH) {
    if (teplik_status == HIGH) {
      digitalWrite(teplik.pin, LOW);
    } else {
      digitalWrite(teplik.pin, HIGH);
    }
  }

  // Serial.print("|| ");

  //  dht_out(DHT_2.label, dht_2.readTemperature(), dht_2.readHumidity());
  //  dht_out(DHT_3.label, dht_3.readTemperature(), dht_3.readHumidity());

  //  Serial.println();
  delay(PAUSE);
}

// void dht_out(String label, float temp, float humidity) {
// if (isfinitef(temp) && isfinitef(humidity)) {
// Serial.print(label);
// Serial.print("=");
// Serial.print(temp);
// Serial.print("=");
// Serial.print(humidity);
// Serial.print(" || ");
// delay(PAUSE);
// }
// }

// void d_out(String label, float val) {
// if (isfinitef(val)) {
// Serial.print(label);
// Serial.print("=");
// Serial.print(val);
// Serial.print(" || ");
// delay(PAUSE);
// }
// }

// void a_out(String label, int val) {
// if (isfinitef(val)) {
// Serial.print(label);
// Serial.print("=");
// Serial.print(val);
// Serial.print(" || ");
// delay(PAUSE);
// }
// }
