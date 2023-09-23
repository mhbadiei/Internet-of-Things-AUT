void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
  Serial.println("Setup COMPLETED");
}

bool flag = false;

void loop() {
  // put your main code here, to run repeatedly:

delay(5000);// Delay 5 second

Serial.println("Hello World!");// << print "Hello World" on the serial >>



// << print "Hello World" just one time >>

//if (flag == false){
//  flag = true;
//  Serial.println("Hello World");
//  }

}
