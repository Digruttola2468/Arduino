//HC-05

#include <SoftwareSerial.h>

/*Conecction
 * VCC --> 5v
 * GND --> GND
 * TXD --> 10
 * RXD --> 11
*/

SoftwareSerial miBT(11,10);   

char DATO = '0';

void setup() {
  Serial.begin(9600);
  Serial.println("Listo");

  miBT.begin(38400);
}

void loop() {
  if (miBT.available()){
    DATO = miBT.read();
    
    Serial.println(miBT.read());
    
    if(DATO == '1'){
      Serial.println("ELEGANTE PUTO");
    }
  }

  
}
