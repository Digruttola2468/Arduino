//Incluir la libreria "RC522 by GithubCommunity"
//Ejemplos/MFRC522/DumpInfo
//Obtenemos la informacion de la targeta

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    return;
  

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
    return;
  
  Serial.print("UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if(mfrc522.uid.uidByte[i] < 0x10) {
      Serial.print(" 0");  
    }
    else {
      Serial.print(" ");
    }
    Serial.print(mfrc522.uid.uidByte[i], HEX); //HEX, mostramos de manera Exadecimal
  }
  Serial.println();

  mfrc522.PICC_HaltA();
}
