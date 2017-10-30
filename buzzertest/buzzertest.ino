#define BUZZPIN 2

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(BUZZPIN, HIGH); 
  delay(5000);
  digitalWrite(BUZZPIN, LOW); 
  delay(1000);

}
