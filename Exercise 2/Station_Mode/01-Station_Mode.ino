// author : MH.Badiei
// The student of ECE at Tehran Uni and CE at Amirkabir Uni.
// Master : Dr.Rasti
// HW3-01-Station Mode

#include "ESP8266WiFi.h"

const char *ssid =  "MH_Badiei";
const char *pass =  "ab2281377";

void setup()
{
  Serial.begin(115200);
  delay(250);

  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(250);

  Serial.print(F("Scaning ... "));
  int n = WiFi.scanNetworks();
  Serial.print(n);
  Serial.println(" available networks");
  for (int i = 0; i < n; i++)
  {
    Serial.println(WiFi.SSID(i));
  }
  Serial.println();
  
  WiFi.begin(ssid, pass);
  Serial.print("Connecting ..");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(F("wifi connected"));
    Serial.println();
    Serial.print("MAC: ");
    Serial.println(WiFi.macAddress());
  }

  
}

void loop()
{

}
