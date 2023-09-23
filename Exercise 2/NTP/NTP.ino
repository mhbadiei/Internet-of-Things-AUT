//author : Badiei

#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// کد پایین از لینکی گرفته شده که در صورت سوال ذکر کرده و ما با توجه به موقعیت جغرافیایی ایران نسبت به مدار گرینویچ زمان را به وقت محلی تغییر دادیم.
// Replace with your network credentials
const char *ssid     = "Matrix";
const char *password = "60428721";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

//Week Days
String weekDays[7]={"یکشنبه", "دوشنبه", "سه شنبه", "چهارشنبه", "پنجشنبه", "جمعه","شنبه"};

//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

// Initialize a NTPClient to get time
  timeClient.begin();
  timeClient.setTimeOffset(+3.5 * 3600 - 10.2);
}

void loop() {
  timeClient.update();
  unsigned long epochTime = timeClient.getEpochTime();
  
  String formattedTime = timeClient.getFormattedTime();
  Serial.print(formattedTime);  
  Serial.println(": ساعت به وقت محلی");
  
  int currentHour = timeClient.getHours();
  int currentMinute = timeClient.getMinutes();
  int currentSecond = timeClient.getSeconds();

  String weekDay = weekDays[timeClient.getDay()];
  Serial.print(" روزِ هفته : ");
  Serial.println(weekDay);    
  
  struct tm *ptm = gmtime ((time_t *)&epochTime); 
  int monthDay = ptm->tm_mday;
  int currentMonth = ptm->tm_mon+1;
  String currentMonthName = months[currentMonth-1];

  int currentYear = ptm->tm_year+1900;
  
  //Print complete date:
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
  Serial.print(currentDate);
  Serial.println(": تاریخ کنونی به میلادی ");

  Serial.println("");

  delay(2000);
}
