#include <stdio.h>
#include <OneWire.h>
#include "DHT.h"
#include <Adafruit_Sensor.h>

#define pin_pirania_1 4
#define pin_pirania_2 5
#define pin_pirania_3 6

#define DHT1pin 8
#define DHT3pin 9
#define DHT4pin 10
#define DHT2pin 7

int DS18S20_Pin = 2; //DS18S20 Signal pin on digital 2

//Temperature chip i/o
OneWire ds(DS18S20_Pin);  // on digital pin 2

DHT dht11(DHT1pin, DHT11);
DHT dht11_2(DHT3pin, DHT11);
DHT dht11_3(DHT4pin, DHT11);
DHT dht22(DHT2pin, DHT22);

void setup()
{
  Serial.begin(115200);// open serial port, set the baud rate to 9600 bps

  pinMode (pin_pirania_1, OUTPUT);
  digitalWrite (pin_pirania_1, HIGH);

  pinMode (pin_pirania_2, OUTPUT);
  digitalWrite (pin_pirania_2, HIGH);

  pinMode (pin_pirania_3, OUTPUT);
  digitalWrite (pin_pirania_3, HIGH);
}

void loop()
{
  Serial.println();
  Serial.println("=========================================");
  digitalWrite (4, HIGH); 
  delay(300);


  // STEAM SENSOR

  int steamSensor = analogRead(0);
  float steamVoltage = steamSensor * (5.0 / 1023.0);

  Serial.print("\033[1;36mSteam\033[0m = ");
  Serial.print(steamSensor);
  Serial.print("\033[1;32m @ \033[0m");
  Serial.print(steamVoltage);
  Serial.println("V");

  delay(300);


  // ANALOG AMBIENT LIGHT SENSOR

  int lightSensor = analogRead(1);
  float lightVoltage = lightSensor * (5.0 / 1023.0);

  Serial.print("\033[1;36mLight\033[0m = ");
  Serial.print(lightSensor);
  Serial.print("\033[1;32m @ \033[0m");
  Serial.print(lightVoltage);
  Serial.println("V");

  delay(300);


  // LIQUID LEVEL SENSOR

  int liquidLvlSensor = analogRead(2);
  float liquidLvlVoltage = liquidLvlSensor * (5.0 / 1023.0);

  Serial.print("\033[1;36mLiquid level\033[0m = ");
  Serial.print(liquidLvlSensor);
  Serial.print("\033[1;32m @ \033[0m");
  Serial.print(liquidLvlVoltage);
  Serial.println("V");

  delay(300);


  // TEMPERATURE SENSOR

  float tempSensor = getTemp();

  Serial.print("\033[1;36mTemperature \033[0m = ");
  Serial.print(tempSensor);
  Serial.println("\033[1;32m deg/C \033[0m");

  delay(300);


  // DHT_11 TEMPERATURE AND HUMIDITY

  float h = dht11.readHumidity(false);
  float t = dht11.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.print("\033[1;36mDHT_11 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11 t\033[0m = ");
    Serial.print(t);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(300);

  // DHT_11 TEMPERATURE AND HUMIDITY

  float h3 = dht11_2.readHumidity(false);
  float t3 = dht11_2.readTemperature();

  if (isnan(h3) || isnan(t3)) {
    Serial.print("\033[1;36mDHT_11_2 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_2 t\033[0m = ");
    Serial.print(t3);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h3);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(300);

  // DHT_11 TEMPERATURE AND HUMIDITY

  float h4 = dht11_3.readHumidity(false);
  float t4 = dht11_3.readTemperature();

  if (isnan(h4) || isnan(t4)) {
    Serial.print("\033[1;36mDHT_11_3 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_3 t\033[0m = ");
    Serial.print(t4);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h4);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(300);

  // DHT_22 TEMPERATURE AND HUMIDITY
  
  float h2 = dht22.readHumidity(false);
  float t2 = dht22.readTemperature();

  if (isnan(h2) || isnan(t2)) {
    Serial.print("\033[1;36mDHT_22 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_22 t\033[0m = ");
    Serial.print(t2);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h2);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(300);

  // FIRE SENSOR

  int fireSensor = digitalRead(3);
  Serial.print("\033[1;36mFIRE SENSOR\033[0m: ");

  if (!fireSensor) {
    Serial.println("\033[1;31mON FIRE!\033[0m");
  } else {
    Serial.println("\033[1;32m CALM :)\033[0m");
  }

  delay(300);


  // LIGHT SENSOR

  //  int lightSensor2 = digitalRead(4);
  int lightSensor2 = analogRead(4);

  Serial.print("\033[1;36mLIGHT SENSOR\033[0m = ");
  Serial.println(lightSensor2);

  digitalWrite (4, LOW);
  delay(5000);
}

float getTemp() {
  //returns the temperature from one DS18S20 in DEG Celsius

  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
    //no more sensors on chain, reset search
    ds.reset_search();
    return -1000;
  }

  if ( OneWire::crc8( addr, 7) != addr[7]) {
    Serial.println("CRC is not valid!");
    return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
    Serial.print("Device is not recognized");
    return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1); // start conversion, with parasite power on at the end

  //  byte present = ds.reset();
  ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read Scratchpad


  for (int i = 0; i < 9; i++) { // we need 9 bytes
    data[i] = ds.read();
  }

  ds.reset_search();

  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB); //using two's compliment
  float TemperatureSum = tempRead / 16;

  return TemperatureSum;

}
