
void setup() 
{
  Serial.begin(9600);// open serial port, set the baud rate to 9600 bps
}

void loop() 
{
  Serial.println("---=========================================---");

  Serial.println("---- Analog Ambient Light Sensor ----");
  int steamSensor;
  steamSensor = analogRead(0);   //connect Steam sensors to Analog 0 
  Serial.println("Analog value >>> "); //print the value to serial  
  Serial.println(steamSensor); //print the value to serial  
  float voltage = steamSensor * (5.0 / 1023.0);
  Serial.println("Voltage >>>"); //print the value to serial  
  Serial.println(voltage); //print the value to serial  


  
  delay(5000);      
}
