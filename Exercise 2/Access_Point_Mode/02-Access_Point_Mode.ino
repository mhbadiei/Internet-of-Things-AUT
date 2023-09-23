// author : Badiei

#include <ESP8266WiFi.h>

IPAddress local_IP(192,168,10,10);
IPAddress gateway(192,168,10,1);
IPAddress subnet(255,255,255,0);

const char *ssid = "Badiei";
const char *password = "ab2281377";

void setup()
{
  Serial.begin(115200);
  WiFi.disconnect();

  Serial.print("The name of Access Point is ");
  Serial.println(ssid);
  Serial.println();
    
  Serial.println("settings of Access Point ... ");

  if(WiFi.softAP(ssid,password)){
  Serial.println("COMPLETED.");
  }else{
    Serial.println("Failed!!!");
  }
  
  delay(250);
  
  Serial.println();
  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());
  Serial.println("***************");
  Serial.println();
    
  WiFi.softAP(ssid, password);
 
  Serial.println("Configuration of Access Point with Selected IP address ... ");
  
  if(WiFi.softAPConfig(local_IP, gateway, subnet)){
  Serial.println("Configuration with selected IP address COMPLETED.");
  }
  else{
    Serial.println("settings of Access Point ... ");
  }
   delay(250);

  Serial.println();
  Serial.println("settings of Access Point ... ");

  if(WiFi.softAP(ssid,password)){
  Serial.println("COMPLETED.");
  }
  else{
    Serial.println("Failed!!!");
  }

  Serial.println();
  Serial.print("IP address = ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
}
