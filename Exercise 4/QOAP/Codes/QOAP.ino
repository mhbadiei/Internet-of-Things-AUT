#include <ESP8266WiFi.h>
#include "coap_client.h"
#include <SPI.h>
#include "MFRC522.h"

#define RST_PIN  5
#define SS_PIN  4 
#define LED_PIN 2
#define LED_RED_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);  

//instance for coapclient
coapClient coap;

int msgid1 =0;

//WiFi connection info
const char* ssid = "MH_Badiei";
const char* password = "ab2281377";

//ip address and default port of coap server in which your interested in
IPAddress ip(192,168,43,105);//take ETH Zurich or coap.me server to run and check client 
int port =5683;

// coap client response callback
void callback_response(coapPacket &packet, IPAddress ip, int port);

// coap client response callback
void callback_response(coapPacket &packet, IPAddress ip, int port) {
    char p[packet.payloadlen + 1];
    memcpy(p, packet.payload, packet.payloadlen);
    p[packet.payloadlen] = NULL;

    //response from coap server
 if(packet.type==3 && packet.code==0){
      Serial.println("ping ok");
    }
    LedHandler(p);
    //Serial.println(p);
}

void setup() {
   
    Serial.begin(115200);
    
    delay(250);
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_RED_PIN, OUTPUT);
    SPI.begin();        
    mfrc522.PCD_Init(); 

    WiFi.begin(ssid, password);
    Serial.println(" ");

    // Connection info to WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    //delay(500);
    yield();
    Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    // Print the IP address of client
    Serial.println(WiFi.localIP());

    // client response callback.
    // this endpoint is single callback.
    coap.response(callback_response);

    // start coap client
    coap.start();
    Serial.println(F("Scan for Card and print UID:"));
}

void loop() {
    bool state;

    if ( ! mfrc522.PICC_IsNewCardPresent()) {
      int msgid = coap.get(ip,port,"resdata");
      state= coap.loop();

      delay(50);
      return;
    }
  
    if ( ! mfrc522.PICC_ReadCardSerial()) {
      int msgid = coap.get(ip,port,"resdata");
      state= coap.loop();

      delay(50);
      return;
    }
    Serial.print(F("UID of tag :"));
  
    String str= "";
    for (int i = mfrc522.uid.size - 1; i >= 0; i--) {
      Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(mfrc522.uid.uidByte[i], HEX);
      str.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
      str.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    str.toUpperCase();

    int msgid1 =coap.put(ip,port,"tagdata",strdup(str.c_str()),strlen(strdup(str.c_str())));
    delay(400);
    Serial.println();
    state= coap.loop();
    
 }

void LedHandler(String payload_buff) {
  
  if (payload_buff == "VALID")
  {
    digitalWrite(LED_PIN,HIGH); //turn led on
    digitalWrite(LED_RED_PIN,LOW); //turn led on
    delay(200);
  }
  
  else if (payload_buff == "INVALID"){
    digitalWrite(LED_PIN,LOW); //turn led on
    digitalWrite(LED_RED_PIN,HIGH);
    delay(200);
    }

}
