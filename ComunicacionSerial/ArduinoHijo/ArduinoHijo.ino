char dataRecibida[10];

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.readBytes(dataRecibida,9);
  Serial.println(dataRecibida);
  delay(10005);
}
