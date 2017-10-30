#define BUZZPIN 2
const int buzzDelay = 200;
bool lastBuzzState = LOW;
long lastBuzz = 0;
long effectLength = 5000;
long startEffect = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZPIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  while ((unsigned long)(millis() - startEffect) < effectLength) {
    if ((unsigned long)(millis() - lastBuzz) > buzzDelay) {
      digitalWrite(BUZZPIN, !lastBuzzState);
      lastBuzzState = !lastBuzzState;
      lastBuzz = millis();
    }

  }
  digitalWrite(BUZZPIN, LOW);
}
