#include <DHT.h>
#include <DHT_U.h>

#define pinDHT 3

DHT dht(pinDHT, DHT11);

int temp, humd;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  temp = dht.readTemperature();
  humd = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" °C");
  Serial.println();
  Serial.print("Humedad: ");
  Serial.print(humd);
  Serial.print(" %");
  Serial.println();
}
