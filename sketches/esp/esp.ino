// /*
//  * Шаг №1 
//  * WI-FI подключение
//  */
// #include <ESP8266WiFi.h>        //Содержится в пакете
// IPAddress apIP(192, 168, 4, 1);

// // Определяем переменные
// String _ssid     = "mi"; // Для хранения SSID
// String _password = "rxrxrxrx"; // Для хранения пароля сети
// String _ssidAP = "unoPower";   // SSID AP точки доступа
// String _passwordAP = ""; // пароль точки доступа

// void setup() {
//   Serial.begin(115200);
//   Serial.println("");
//   Serial.println("Start 1-WIFI");
//   //Запускаем WIFI
//   WIFIinit();
// }

// void loop() {
//   delay(1000);
//   Serial.println("loop");
// }

void WIFIinit() {
  // Попытка подключения к точке доступа
  WiFi.mode(WIFI_STA);
  byte tries = 11;
  WiFi.begin(_ssid.c_str(), _password.c_str());
  while (--tries && WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    // Если не удалось подключиться запускаем в режиме AP
    Serial.println("");
    Serial.println("WiFi up AP");
    StartAPMode();
  }
  else {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  }
}

bool StartAPMode()
{
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(_ssidAP.c_str(), _passwordAP.c_str());
  return true;
}
