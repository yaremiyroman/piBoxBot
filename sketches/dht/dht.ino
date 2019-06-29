

//#define DHTPIN 2 // номер пина, к которому подсоединен датчик
//#define DHTPIN_2 4 // номер пина, к которому подсоединен датчик

// Раскомментируйте в соответствии с используемым датчиком

// Инициируем датчик

//DHT dht(DHTPIN, DHT22);
//DHT dht2(DHTPIN_2, DHT11);

void setup() {

  Serial.begin(9600);

  //  dht.begin();

}

void loop() {
  //  delay(250);

  //  Serial.println("---- DHT-22 ---- DHT-11 ----");
  //  float h = dht.readHumidity();
  //  float t = dht.readTemperature();
  //  float h2 = dht2.readHumidity();
  //  float t2 = dht2.readTemperature();
  //
  //  // Проверка удачно прошло ли считывание.
  //  if (isnan(h) || isnan(t) || isnan(h2) || isnan(t2)) {
  //    Serial.println("Не удается считать показания");
  //    return;
  //  }
  //
  //  Serial.println("Влажность DHT-22 >>> ");
  //  Serial.println(h);
  //  Serial.println("Температура DHT-22  >>> ");
  //  Serial.println(t);
  //  Serial.println("Влажность DHT-11 >>> ");
  //  Serial.println(h2);
  //  Serial.println("Температура DHT-11 >>> ");
  //  Serial.println(t2);
  //
  //  delay(250);

//  int sensorValue;
//  sensorValue = analogRead(0);   //connect Steam sensors to Analog 0
//  Serial.println("---- Analog Ambient Light Sensor ----");
//  Serial.println("Lux >>> ");
//  Serial.println(sensorValue * 6); //print the value to serial
//  
//
//  delay(250);
//
//  int sensorValue1;
//  sensorValue1 = analogRead(1);   //connect Steam sensors to Analog 0
//  Serial.println("---- Steam Sensor ----");
//  Serial.println("Steam amount >>> ");
//  Serial.println(sensorValue1); //print the value to serial
//
//  Serial.write(13);
//  delay(1000);
}
