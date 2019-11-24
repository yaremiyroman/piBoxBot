#include <stdio.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

struct sensor PIRAHNIA = { 2, "led" };
struct sensor FIRE = { 3, "fire" };

void setup() {
  Serial.begin(9600);
  
  pinMode(PIRAHNIA.pin, OUTPUT);
  
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

  digitalWrite(PIRAHNIA.pin, LOW);
  
  d_out(FIRE.label, digitalRead(FIRE.pin));

  loop_end();
}
