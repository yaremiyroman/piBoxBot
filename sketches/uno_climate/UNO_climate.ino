#include <stdio.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <OneWire.h>

// PINS
#define DS18B20 3
#define DHT11_1 4
#define DHT11_2 5
#define DHT11_3 6
#define DHT11_4 7
#define DHT22_1 8

// INIT
OneWire ds(DS18B20);
DHT dht11_1(DHT11_1, DHT11);
DHT dht11_2(DHT11_2, DHT11);
DHT dht11_3(DHT11_3, DHT11);
DHT dht11_4(DHT11_4, DHT11);
DHT dht22_1(DHT22_1, DHT22);

// VARS
int pause = 500;
int interval = 2500;
int rest = 5000;

/////////////////////////////////////
/////////////////////////////////////
/////////////////////////////////////

void setup() {
  dht11_1.begin();
  dht11_2.begin();
  dht11_3.begin();
  dht11_4.begin();
  dht22_1.begin();

  Serial.begin(9600);
}

float getTemp() {
  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
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
  ds.write(0x44, 1);

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

void loop() {
  delay(interval);

  ////////////////////////////////////
  // DS18B20
  ////////////////////////////////////
  
  float ds18b20 = getTemp();

  if (!isnan(ds18b20) && (ds18b20 > 0)) {
    Serial.print("ds18b20=");
    Serial.print(ds18b20);
    Serial.print(">>>");
  }
  
  delay(pause);
  
  ////////////////////////////////////
  // DHT11
  ////////////////////////////////////

  float dht11_1_h = dht11_1.readHumidity();
  float dht11_1_temp = dht11_1.readTemperature();

  if (!isnan(dht11_1_h) && !isnan(dht11_1_temp)) {
    Serial.print("dht11_1=");
    Serial.print(dht11_1_temp);
    Serial.print("=");
    Serial.print(dht11_1_h);
    Serial.print(">>>");
  }
    
  delay(pause);
  
  ////////////////////////////////////
  
  float dht11_2_h = dht11_2.readHumidity();
  float dht11_2_temp = dht11_2.readTemperature();

  if (!isnan(dht11_2_h) && !isnan(dht11_2_temp)) {
    Serial.print("dht11_2=");
    Serial.print(dht11_2_temp);
    Serial.print("=");
    Serial.print(dht11_2_h);
    Serial.print(">>>");
  }
    
  delay(pause);
  
  ////////////////////////////////////

  float dht11_3_h = dht11_3.readHumidity();
  float dht11_3_temp = dht11_3.readTemperature();

  if (!isnan(dht11_3_h) && !isnan(dht11_3_temp)) {
    Serial.print("dht11_3=");
    Serial.print(dht11_3_temp);
    Serial.print("=");
    Serial.print(dht11_3_h);
    Serial.print(">>>");
  }
    
  delay(pause);
  
  ////////////////////////////////////

  float dht11_4_h = dht11_4.readHumidity();
  float dht11_4_temp = dht11_4.readTemperature();

  if (!isnan(dht11_4_h) && !isnan(dht11_4_temp)) {
    Serial.print("dht11_4=");
    Serial.print(dht11_4_temp);
    Serial.print("=");
    Serial.print(dht11_4_h);
    Serial.print(">>>");
  }
    
  delay(pause);
  
  ////////////////////////////////////

  ////////////////////////////////////
  // DHT 22
  ////////////////////////////////////

  float dht22_1_h = dht22_1.readHumidity();
  float dht22_1_temp = dht22_1.readTemperature();

  if (!isnan(dht22_1_h) && !isnan(dht22_1_temp)) {
    Serial.print("dht22_1=");
    Serial.print(dht22_1_temp);
    Serial.print("=");
    Serial.print(dht22_1_h);
    Serial.print(">>>");
  }
    
  delay(pause);
  
  ////////////////////////////////////
  ////////////////////////////////////
  ////////////////////////////////////

  Serial.println();
  delay(rest);
}

//  // STEAM SENSOR
//
//  int steamSensor = analogRead(0);
//  float steamVoltage = steamSensor * (5.0 / 1023.0);
//Serial.println("---- Analog Ambient Light Sensor ----");
//int steamSensor;
//steamSensor = analogRead(0);   //connect Steam sensors to Analog 0
//Serial.println("Analog value >>> "); //print the value to serial
//Serial.println(steamSensor); //print the value to serial
//float voltage = steamSensor * (5.0 / 1023.0);
//Serial.println("Voltage >>>"); //print the value to serial
//Serial.println(voltage); //print the value to serial

//  // ANALOG AMBIENT LIGHT SENSOR
//
//  int lightSensor = analogRead(1);
//  float lightVoltage = lightSensor * (5.0 / 1023.0);
//
//  Serial.print("\033[1;36mLight\033[0m = ");
//  Serial.print(lightSensor);
//  Serial.print("\033[1;32m @ \033[0m");
//  Serial.print(lightVoltage);
//  Serial.println("V");
//
//  delay(300);
