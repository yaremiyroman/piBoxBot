#include <stdio.h>

void setup() {
  Serial.begin(9600);
}
void loop() {
  delay(10);
  Serial.println("PrintLn");
  delay(10);
}
