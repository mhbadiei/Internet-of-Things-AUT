/*Author : Badiei
 * RST/Reset   RST          D1 (GPIO5)        
 * SPI SS      SDA(SS)      D2 (GPIO4)       
 * SPI MOSI    MOSI         D7 (GPIO13)
 * SPI MISO    MISO         D6 (GPIO12)
 * SPI SCK     SCK          D5 (GPIO14)
 * 3.3V        3.3V         3.3V
 * GND         GND          GND
 */
 
#include <ESP8266WiFi.h>
#include <SPI.h>
#include "MFRC522.h"

#define RST_PIN  5
#define SS_PIN  4 

MFRC522 mfrc522(SS_PIN, RST_PIN);  

void setup() {

  Serial.begin(115200);  
  delay(250);

  SPI.begin();           

  mfrc522.PCD_Init();    
  
  Serial.println(F("Scan for Card and print UID:"));
}



void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    delay(100);
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    delay(100);
    return;
  }

  // UID of tag
  Serial.print(F("UID of tag :"));

  DisplayUIDHEX(mfrc522.uid.uidByte, mfrc522.uid.size);

  Serial.println();

  delay(1000);
}


void DisplayUIDHEX(byte *buffer, byte bufferSize) {

  for (int i = bufferSize - 1; i >= 0; i--) {

    Serial.print(buffer[i] < 0x10 ? " 0" : " ");

    Serial.print(buffer[i], HEX);

  }

}
