int num;
int led = 12;

// define function sleep
void sleep(int num){
  //keep led on for 5 second
  delay(5000); 
  
  // Deep sleep mode for n seconds, the ESP8266 wakes up by itself when GPIO 16 (D0 in NodeMCU board) is connected to the RESET pin
  Serial.println("I'm awake, but I'm going into deep sleep mode");
  ESP.deepSleep(num*10e5);   
  }
  
void setup() {
  Serial.begin(115200);
  while(!Serial) { }   // Wait for serial to initialize.

  pinMode(led, OUTPUT); // define led
  digitalWrite(led,HIGH); //turn led on
  
  Serial.println("How Many Times Do You Want to make nodeMCU sleep"); //Prompt User for Input
  while (Serial.available() == 0) {
    // Wait for User to Input Data
  }
    num = Serial.parseInt(); //Read the data the user has input
  Serial.print("The user has choosen the number:");
  Serial.println(num);
  
  sleep(num); // call function sleep() for deepsleep mode
}

void loop() {
  // put your main code here, to run repeatedly:
}
