int sensorValue = 0;        // value read from the LDR
int output = 0;        // value output to the PWM

const int analogInPin = A0;  // Analog input for reading LDR value
const int analogOutPin = 5; // Analog output pin for LED

void setup() {
  Serial.begin(9600);
}

void loop() {

  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  
  // map it to the range of the analog out:
  output = map(sensorValue, 0, 1023, 1023, 0);
  
  // change the analog out value:
  analogWrite(analogOutPin, output);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(output);

  delay(5);
}
