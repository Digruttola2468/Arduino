int sensorPin = A0;

//Cuando esta totalmente seco 1023
//Cuando esta totalmente morado 0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int humedad = analogRead(sensorPin);
  Serial.println(humedad);
  delay(1000);
}
