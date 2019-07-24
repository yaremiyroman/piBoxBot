#include <stdio.h>
// #include <DHT.h>
//#include <Adafruit_Sensor.h>
#include <OneWire.h>

#define DS18B20 3

// #define DHt41_1 4
// #define DHt41_2 5
// #define DHt41_3 6
// #define DHt41_4 7

// #define DHt52_1 8

OneWire ds(DS18B20);

// DHT dht411(DHt41_1, DHt41);
// DHT dht412(DHt41_2, DHt41);
// DHT dht413(DHt41_3, DHt41);
// DHT dht414(DHt41_4, DHt41);

// DHT dht521(DHt52_1, DHt52);

int pause = 2500;
int interval = 5000;
int rest = 500;

void setup() {
  pinMode(DS18B20, OUTPUT);

  // pinMode(DHt41_1, OUTPUT);
  // pinMode(DHt41_2, OUTPUT);
  // pinMode(DHt41_3, OUTPUT);
  // pinMode(DHt41_4, OUTPUT);

  // pinMode(DHt52_1, OUTPUT);

  // dht411.begin();
  // dht412.begin();
  // dht413.begin();
  // dht414.begin();

  // dht521.begin();

  Serial.begin(9600);
}


void loop() {
  delay(rest);

  // DS18B20
  float t3 = getTemp();
  delay(pause);// DHt41

  // // DHt41
  // float h7 = dht411.readHumidity();
  // delay(pause);
  // float t4 = dht411.readTemperature();
  // delay(pause);
  // float h5 = dht412.readHumidity();
  // delay(pause);
  // float t5 = dht412.readTemperature();
  // delay(pause);
  // float h6 = dht413.readHumidity();
  // delay(pause);
  // float t6 = dht413.readTemperature();
  // delay(pause);
  // float h7 = dht414.readHumidity();
  // delay(pause);
  // float t4 = dht414.readTemperature();
  // delay(pause);
  // // DHt52
  // float h5 = dht521.readHumidity();
  // delay(pause);
  // float t5 = dht521.readTemperature();
  // delay(pause);

  if (!isnan(t3)) {
    Serial.print("t3=");
    Serial.print(t3);
    Serial.print(">>>");
  }

  // if (!isnan(h5) && !isnan(t5)) {
  //   Serial.print(">>>");
  //   Serial.print("t5=");
  //   Serial.print(t5);

  //   Serial.print(">>>");
  //   Serial.print("h5=");
  //   Serial.print(h5);
  // }

  // if (!isnan(h6) && !isnan(t6)) {
  //   Serial.print(">>>");
  //   Serial.print("t6=");
  //   Serial.print(t6);

  //   Serial.print(">>>");
  //   Serial.print("h6=");
  //   Serial.print(h6);
  // }

  // if (!isnan(h4) && !isnan(t4)) {
  //   Serial.print(">>>");
  //   Serial.print("t7=");
  //   Serial.print(t4);

  //   Serial.print(">>>");
  //   Serial.print("h7=");
  //   Serial.print(h4);
  // }

  // if (!isnan(h5) && !isnan(t5)) {
  //   Serial.print(">>>");
  //   Serial.print("t8=");
  //   Serial.print(t5);

  //   Serial.print(">>>");
  //   Serial.print("h8=");
  //   Serial.print(h5);

  //   // END OF SERIAL OUTPUT
  // }

  // Serial.println("Privet");

  delay(rest);
}

// float getTemp() {
//   byte data[12];
//   byte addr[8];

//   if ( !ds.search(addr)) {
//     ds.reset_search();
//     return -1000;
//   }

//   if ( OneWire::crc8( addr, 7) != addr[7]) {
//     Serial.println("CRC is not valid!");
//     return -1000;
//   }

//   if ( addr[0] != 0x10 && addr[0] != 0x28) {
//     Serial.print("Device is not recognized");
//     return -1000;
//   }

//   ds.reset();
//   ds.select(addr);
//   ds.write(0x44, 1);

//   ds.reset();
//   ds.select(addr);
//   ds.write(0xBE); // Read Scratchpad


//   for (int i = 0; i < 9; i++) { // we need 9 bytes
//     data[i] = ds.read();
//   }

//   ds.reset_search();

//   byte MSB = data[1];
//   byte LSB = data[0];

//   float tempRead = ((MSB << 8) | LSB); //using two's compliment
//   float TemperatureSum = tempRead / 16;

//   return TemperatureSum;
// }


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


//  delay(300);
//
//
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

//  // FIRE SENSOR
//
//  int fireSensor = digitalRead(3);
//  Serial.print("\033[1;36mFIRE SENSOR\033[0m: ");
//
//  if (!fireSensor) {
//    Serial.println("\033[1;31mON FIRE!\033[0m");
//  } else {
//    Serial.println("\033[1;32m CALM :)\033[0m");
//  }
//
//  delay(300);
//
//
//  // LIGHT SENSOR
//
//  //  int lightSensor2 = digitalRead(4);
//  int lightSensor2 = analogRead(4);
//
//  Serial.print("\033[1;36mLIGHT SENSOR\033[0m = ");
//  Serial.println(lightSensor2);
//
//  digitalWrite (4, LOW);
