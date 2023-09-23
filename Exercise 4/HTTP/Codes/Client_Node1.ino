#include <ESP8266WiFi.h>
#include <SPI.h>
#include "MFRC522.h"

#define RST_PIN  5
#define SS_PIN  4 
#define LED_PIN 2
#define LED_RED_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);  
    
const char* ssid     = "MH_Badiei";
const char* password = "ab2281377";

const char* host = "192.168.43.105";
String tagcard = "0";

void setup() {

  Serial.begin(115200);
  delay(10);
  pinMode(LED_PIN, OUTPUT);
  pinMode(LED_RED_PIN, OUTPUT);
  SPI.begin();        
  mfrc522.PCD_Init(); 
  
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println(F("Scan for Card and print UID:"));
}


void loop() {
 delay(100);


 Serial.print("connecting to ");
 Serial.println(host);

 // Use WiFiClient class to create TCP connections
 WiFiClient client;
 const int httpPort = 8081;
 if (!client.connect(host, httpPort)) {
  Serial.println("connection failed");
  return;
 }

 // We now create a URI for the request
 String url = "/resdata";

 Serial.print("Requesting URL: ");
 Serial.println(url);


   Serial.print("Requesting POST: ");
   // Send request to the server:
   client.println("POST /tagdata HTTP/1.1");
   client.println("Host: server_name");
   client.println("Accept: */tagdata*");
   client.println("Content-Type: application/x-www-form-urlencoded");
   client.print("Content-Length: ");
   client.println(tagcard.length());
   client.println();
   client.print(tagcard);
 // This will send the request to the server
 //this is a get method working
   client.print(String("GET ") + url + " HTTP/1.1\r\n" +
           "Connection: close\r\n\r\n"); 

 unsigned long timeout = millis();
 while (client.available() == 0) {
 if (millis() - timeout > 5000) {
  Serial.println(">>> Client Timeout !");
  client.stop();
  return;
 }
}

 // Read all the lines of the reply from server and print them to Serial
 while(client.available()){
  String line = client.readStringUntil('\r');
  //Serial.println(line);
  String permis = line;
 Serial.println();
 if( String(permis.c_str()) == String("\n{\"VALID\":\"\"}")) {
    digitalWrite(LED_PIN,HIGH); //turn led on
    digitalWrite(LED_RED_PIN,LOW); //turn led on
    delay(200);
}
 if( String(permis.c_str()) == String("\n{\"INVALID\":\"\"}")) {
    digitalWrite(LED_PIN,LOW); //turn led on
    digitalWrite(LED_RED_PIN,HIGH);
    delay(200);
 }
  }

 Serial.println();
 Serial.println("closing connection");

 if ( ! mfrc522.PICC_IsNewCardPresent()) {
    delay(50);
    return;
  }

  if ( ! mfrc522.PICC_ReadCardSerial()) {
    delay(50);
    return;
  }

  // UID of tag
  Serial.print(F("UID of tag :"));

  String str= "";
  for (int i = mfrc522.uid.size - 1; i >= 0; i--) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    str.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    str.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  str.toUpperCase();

  tagcard = str;

}
