#include <ESP8266WiFi.h>

const char* ssid     = "MH_Badiei";
const char* password = "ab2281377";

const char* host = "192.168.43.105";

String permission = "0";
 
void setup() {

  Serial.begin(115200);
  delay(10);
  pinMode(A0, INPUT);
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
 String url = "/tagdata";

 Serial.print("Requesting URL: ");
 Serial.println(url);
//String data = "temperature=" + String(temperature);
//Serial.print(permission);
  //if (permission ==  "{\"101.00\":\"\"}" ){
   // Serial.print("***************************************************");
    
   client.println("POST /resdata HTTP/1.1");
   client.println("Host: server_name");
   client.println("Accept: */resdata*");
   client.println("Content-Type: application/x-www-form-urlencoded");
   client.print("Content-Length: ");
   client.println(permission.length());
   client.println();
   client.print(permission);
  //}


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
  String tagcard = line;
 //  Serial.println(tagcard);
 Serial.println();
// Serial.print("***********************************");
 // Serial.print(tagcard);
// Serial.println("***********************************"); 
  //Serial.println(strcmp(tagcard.c_str(),"\n{\" EC 85 2B 62\":\"\"}"));
 //Serial.println(strlen("\f\n{\" EC 85 2B 62\":\"\"}"));
  //Serial.print("***********************************");
// Serial.println("\n{\" EC 85 2B 62\":\"\"}");
 //Serial.println(tagcard);
//Serial.println(strlen(tagcard.c_str()));
 if( String(tagcard.c_str()) == String("\n{\" EC 85 2B 62\":\"\"}")) {
 permission = "INVALID";
 // Serial.print("IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII");
  }
 if (String(tagcard.c_str()) == String("\n{\" EC 85 1C 12\":\"\"}")) {
  permission = "VALID";
  //Serial.print("ssssssssssssssssssssssssssssssssssssssssssssssssssssssss");
 }
  }

 Serial.println();
 Serial.println("closing connection");


}
