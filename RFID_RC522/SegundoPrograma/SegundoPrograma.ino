#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_PIN          10         // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte LecturaUID[4];
byte Usuario1[4] = {0x6C, 0xF2, 0xDD, 0x2B};  //Tarjeta

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  Serial.println("Esta listo para apollar la targeta");
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
    return;
  

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
    return;
  
  Serial.print("UID:");
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    
    if(mfrc522.uid.uidByte[i] < 0x10) Serial.print(" 0");  
    else Serial.print(" ");
    
    Serial.print(mfrc522.uid.uidByte[i], HEX); //HEX, mostramos de manera Exadecimal
    LecturaUID[i] = mfrc522.uid.uidByte[i];
  }
  Serial.print("\t");

  if( comparaUID(LecturaUID, Usuario1))
    Serial.println("Bienvenido Usuario 1");
  else
    Serial.println("No te Conozco");
  
  mfrc522.PICC_HaltA();
}

boolean comparaUID( byte lectura[], byte usuario[]){
  for (byte i=0 ; i < mfrc522.uid.size; i++) 
    if(lectura[i] != usuario[i]) return(false);
  
  return(true);
}
