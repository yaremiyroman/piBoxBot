#include <stdio.h>

const int PAUSE = 1000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(PAUSE);
  delay(PAUSE);
}
