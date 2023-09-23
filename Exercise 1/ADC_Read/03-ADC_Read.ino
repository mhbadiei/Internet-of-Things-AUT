void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogRead(A0);   // read the input on analog pin A0

  float output = sensorValue * (100.0 / 1023.0);   // Convert the analog reading (which goes from 0 - 1023) to a scale of (0 - 100)

  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(output);   // print out the value

}
