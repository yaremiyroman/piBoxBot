#include <stdio.h>

void setup() {
  pinMode(13, OUTPUT);
}


void blink_pirahnia(int pin = 2, int count = 10, int interval = 100) {
  for (int i = 0; i <= count; i++) {
    digitalWrite(pin, HIGH);
    delay(interval);
    digitalWrite(pin, LOW);
    delay(interval);
  }
}


void loop() {
  digitalWrite(13, LOW);   
}
