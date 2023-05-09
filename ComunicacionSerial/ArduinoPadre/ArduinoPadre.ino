char data[9] = "IVANDIGRU";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(data,9);
  delay(5000);
}
