#define SPEAKERPIN 4
int numTones = 10;
int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < numTones; i++) {
    tone(SPEAKERPIN, tones[i]);
    delay(500);
  }
  noTone(SPEAKERPIN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
