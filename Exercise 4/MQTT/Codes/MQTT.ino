    //Badiei
    #include <ESP8266WiFi.h>
    #include <PubSubClient.h>
    #include <SPI.h>
    #include "MFRC522.h"

    #define RST_PIN  5
    #define SS_PIN  4 
    #define LED_PIN 2
    #define LED_RED_PIN 10

    MFRC522 mfrc522(SS_PIN, RST_PIN);  
    
    // Connection info.
    const char* ssid = "Matrix";
    const char* password =  "60428721";
    const char* mqttServer = "192.168.1.7";
    const int mqttPort = 1883;
    const char* clientID = "";
    const char* channelName = "testTopic1";
    WiFiClient MQTTclient;
    
    PubSubClient client(MQTTclient);
    void callback(char* topic, byte* payload, unsigned int length) {
      String payload_buff;
      for (int i=0;i<length;i++) {
        payload_buff = payload_buff+String((char)payload[i]);
      }
      Serial.println(payload_buff); // Print out messages.
      if(payload_buff)
        LedHandler(payload_buff);
    }
    long lastReconnectAttempt = 0;
    boolean reconnect() {
      if (client.connect(clientID)) {
        client.subscribe(channelName); // Subscribe.
      }
      return client.connected();
    }
    void setup() {
      Serial.begin(9600);
      
      delay(250);
      pinMode(LED_PIN, OUTPUT);
      pinMode(LED_RED_PIN, OUTPUT);
      SPI.begin();        
      mfrc522.PCD_Init(); 
      
      Serial.println("Attempting to connect...");
      WiFi.begin(ssid, password); // Connect to WiFi.
       while (WiFi.status() != WL_CONNECTED) {
       delay(1000);
      Serial.print(".");
      }
      Serial.println();
      Serial.println("Connected to the WiFi network");
      client.setServer(mqttServer, mqttPort); // Connect to PubNub.
      client.setCallback(callback);
      lastReconnectAttempt = 0;
      Serial.println(F("Scan for Card and print UID:"));
    }
    void loop() {
      if (!client.connected()) {
        long now = millis();
        if (now - lastReconnectAttempt > 1000) { // Try to reconnect.
          lastReconnectAttempt = now;
          if (reconnect()) { // Attempt to reconnect.
            lastReconnectAttempt = 0;
          }
        }
      } else { // Connected.
        client.loop();
        client.subscribe(channelName);
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
      
        //DisplayUIDHEX(mfrc522.uid.uidByte, mfrc522.uid.size,client);

        String str= "";
        for (int i = mfrc522.uid.size - 1; i >= 0; i--) {
          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
          Serial.print(mfrc522.uid.uidByte[i], HEX);
          str.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
          str.concat(String(mfrc522.uid.uidByte[i], HEX));
        }
        str.toUpperCase();
        
        client.publish("testTopic",str.c_str()); // Publish message.
        delay(1200);
      
        Serial.println();

      }
    }


    void LedHandler(String payload_buff) {
      
      if (payload_buff == "VALID")
      {
        Serial.println(" You have permission ");
        digitalWrite(LED_PIN,HIGH); //turn led on
        digitalWrite(LED_RED_PIN,LOW); //turn led on
        delay(1000);
        Serial.println(" LED GREEN is ON ");
      }
      
      else   {
        Serial.println(" You don't have permission ");
        digitalWrite(LED_PIN,LOW); //turn led on
        digitalWrite(LED_RED_PIN,HIGH);
        delay(1000);
        Serial.println(" LED RED is ON ");  }
    
    }
