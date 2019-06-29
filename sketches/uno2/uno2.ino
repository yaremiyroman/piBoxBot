#include <stdio.h>

#define pin_pirania_1 7

void setup()
{
//  Serial.begin(9600);// open serial port, set the baud rate to 9600 bps

  pinMode (pin_pirania_1, OUTPUT);
  digitalWrite (pin_pirania_1, HIGH);
}

void loop()
{
}
