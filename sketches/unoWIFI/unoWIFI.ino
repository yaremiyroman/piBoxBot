#include <stdio.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;
const int REST = 250;

struct sensor MOI = { 0, "moi" };

void setup() {
  Serial.begin(115200);
  Serial.println();
}

void a_out(String label, int val) {
  //  if (isfinite(val)) {
  Serial.print(label);
  Serial.print("=");
  Serial.print(val);
  Serial.print("||");
  delay(PAUSE);
  //  }
}

void loop() {
  delay(PAUSE);
  Serial.print("||");

  a_out(MOI.label, analogRead(MOI.pin));

  Serial.println();
  delay(PAUSE);
}
