const int PAUSE = 1000;
const int REST = 250;

void setup() {
  Serial.begin(9600);
  Serial.println();
}

void loop() {
  delay(REST);
  Serial.print("|-- Serial Output --|");
  Serial.println();
  delay(PAUSE);
}
