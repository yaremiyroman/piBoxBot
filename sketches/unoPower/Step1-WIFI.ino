/*
 * Шаг №1 
 * WI-FI подключение
 */
#include <ESP8266WiFi.h>        //Содержится в пакете
IPAddress apIP(192, 168, 4, 1);

// Определяем переменные
String _ssid     = "mi"; // Для хранения SSID
String _password = "rxrxrxrx"; // Для хранения пароля сети
String _ssidAP = "unoPower";   // SSID AP точки доступа
String _passwordAP = ""; // пароль точки доступа

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Start 1-WIFI");
  //Запускаем WIFI
  WIFIinit();
}

void loop() {
  delay(1000);
  Serial.println("loop");
}
