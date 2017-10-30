#define SPEAKERPIN 4
#define LEDPIN 3
/*int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   */

int numTones = 2;
int tones[] = {100, 500};
const int blinkDelay = 150;
const int toneDelay = 500;
long lastBlink = 0;
long lastTone = 0;
bool lastLEDState = LOW;
int toneCount = 0;
long effectLength = 5000;
long startEffect = 0;
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
  
}

void loop() {
  
  while ((unsigned long)(millis() - startEffect) < effectLength) {
    if ((unsigned long)(millis() - lastBlink) > blinkDelay) {
      digitalWrite(LEDPIN, !lastLEDState);
      lastLEDState = !lastLEDState;
      lastBlink = millis();
    }
  
    if ((unsigned long)(millis() - lastTone) > toneDelay) {
      tone(SPEAKERPIN, tones[toneCount % numTones]);
      toneCount++;
      lastTone = millis();
    }
  }
  digitalWrite(LEDPIN, LOW);
  noTone(SPEAKERPIN);
  

}
