// author : Badiei

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);
uint8_t led = 13; 
bool ledMode = LOW;

IPAddress local_IP(192,168,10,10);
IPAddress gateway(192,168,10,1);
IPAddress subnet(255,255,255,0);

const char *ssid = "Badiei";
const char *password = "ab2281377";

void setup()
{
  Serial.begin(115200);
  WiFi.disconnect();

  pinMode(led, OUTPUT);

  Serial.print("The name of Access Point is ");
  Serial.println(ssid);
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
  delay(250);
  
  server.on("/", mainPage);
  server.on("/LEDOn", ledOnRoutes);
  server.on("/LEDOff", ledOffRoutes);
  server.onNotFound(NotFoundRoutes);

  Serial.println();
  server.begin();
  Serial.println("app is running");
}

void loop() {
  
  server.handleClient();
  if(ledMode)
  {
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
  
}

void NotFoundRoutes(){
  server.send(404, "text/plain", "your page does not exist. choose /ledon route or /ledoff");
}

void mainPage() {
  ledMode = LOW;
  Serial.println();
  Serial.println("LED is OFF");
  server.send(200, "text/html", HtmlPage(ledMode)); 
}

void ledOnRoutes() {
  ledMode = HIGH;
  Serial.println();
  Serial.println("LED is ON");
  server.send(200, "text/html", HtmlPage(true)); 
}

void ledOffRoutes() {
  ledMode = LOW;
  Serial.println("LED is OFF");
  server.send(200, "text/html", HtmlPage(false)); 
}

String HtmlPage(uint8_t ledmode){
  String LStr = "<!DOCTYPE html> <html>\n";
  LStr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  LStr +="<title>LED Control</title>\n";
  LStr +="</head>\n";
  LStr +="<body>\n";
  if(ledmode){
   LStr +="<h1>LED turns ON</h1>\n";
  }
  else{
   LStr +="<h1>LED turns OFF</h1>\n";
  }
  LStr +="</body>\n";
  LStr +="</html>\n";
  return LStr;
}
