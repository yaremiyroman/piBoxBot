void setup() {
  //Serial.begin(115200); // got errors at this rate
  Serial.begin(57600);
  //Serial.begin(9600);
}

void loop()
{
  // INIT // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

  delay(100);

  bool dataReady;
  String data;

  // ACCEPT DATA FROM THE ARDUINO // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

  if (Serial.available()) { // listen for serial data from the Arduino Atmega328
    data = Serial.readString();
    //  data = Serial.read();
    dataReady = true;
    delay(100);
  }

  if (dataReady) {
    Serial.println();
    Serial.println(data);
    Serial.println();
  }

}
