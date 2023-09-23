void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}


int ledPin = 5; // set GPIO5 as a ledPin

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogRead(A0);   // read the input on analog pin A0

  float output = sensorValue * (100.0 / 1023.0);   // Convert the analog reading (which goes from 0 - 1023) to a scale of (0 - 100)

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(output);   // print out the value


  pinMode(ledPin , OUTPUT);  //set GPIO5 as an output

  if (output < 50)
    digitalWrite(ledPin,HIGH); // check output : if it's less than 50, turn on the led
  else
    digitalWrite(ledPin,LOW); // check output : if it's more than 50, turn off the led
}
