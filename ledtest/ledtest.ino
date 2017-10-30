#define LEDPIN 3

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  blinky();
  delay(1000);

}

void blinky() {
  for (int i=0; i<20; i++) {
    digitalWrite(LEDPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(150);                       // wait for a second
    digitalWrite(LEDPIN, LOW);    // turn the LED off by making the voltage LOW
    delay(150);                       // wait for a second
  }
  
}
