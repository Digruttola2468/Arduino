//Programa: Ejemplos/MFRC522/DumpInfo

//Incluir la libreria  "MFRC522 by GithubCommunity"
#include <SPI.h>
#include <MFRC522.h>

//Obtenemos la informacion de la targeta

/*Conexion
SDA(SS) -> Pin Digital 10
SCK     -> Pin Digital 13
MOSI    -> Pin Digital 11
MISO    -> Pin Digital 12
IRQ     -> -
RST     -> Pin Digital 9
VCC     -> 3.3v
*/

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
