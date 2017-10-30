/* Product Demo for ENME615.
 *  Model for alert effects for child in car seat reminder keyfob.
 *  Trigger LEDs, tones, and vibration with IR remote.
 *  Liz Corson, October 2017
 *  
 */

#include "IRLibAll.h"


//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(1);

//Create a decoder object 
IRdecode myDecoder;   

//Buzzer
#define SPEAKERPIN 4
#define BUZZPIN 2
#define LEDPIN 3
 
//int numTones = 10;
//int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

int numTones = 2;
int numLoops = 5;
int tones[] = {100, 500};
const int blinkDelay = 150;
const int toneDelay = 500;
long lastBlink = 0;
long lastTone = 0;
bool lastLEDState = LOW;
int toneCount = 0;
long effectLength = 5000;

void setup() {
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo
  myReceiver.enableIRIn(); // Start the receiver
  Serial.println(F("Ready to receive IR signals"));
}

void loop() {
  //Continue looping until you get a complete signal received
  if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    //myDecoder.dumpResults(false);  //Now print results. Use false for less detail
    if (myDecoder.protocolNum == NEC) {
      switch(myDecoder.value) {
        case 0xFD08F7:  //1
          Serial.println("1");
          blinky();
          break;
        case 0xFD8877:  //2
          Serial.println("2");
          buzz();
          break;
        case 0xFD48B7:  //3
          Serial.println("3");
          sounds();
          break;
        case 0xFD28D7:  //4
          ledandsounds();
          Serial.println("4");
          break;
        case 0xFDA857:  //5
          Serial.println("5");
          break;
        case 0xFD6897:  //6
          Serial.println("6");
          break;
        case 0xFD18E7:  //7
          Serial.println("7");
          break;  
        case 0xFD9867:  //8
          Serial.println("8");
          break;   
        case 0xFD58A7:  //9
          Serial.println("9");
          break;             
      }
    }
    myReceiver.enableIRIn();      //Restart receiver
  }
}

void blinky() {
  long startEffect = millis();  
  while ((unsigned long)(millis() - startEffect) < effectLength) {
    if ((unsigned long)(millis() - lastBlink) > blinkDelay) {
      digitalWrite(LEDPIN, !lastLEDState);
      lastLEDState = !lastLEDState;
      lastBlink = millis();
    }
  }
  digitalWrite(LEDPIN, LOW);  
}

void sounds() {
  long startEffect = millis();  
  while ((unsigned long)(millis() - startEffect) < effectLength) {
    if ((unsigned long)(millis() - lastTone) > toneDelay) {
      tone(SPEAKERPIN, tones[toneCount % numTones]);
      toneCount++;
      lastTone = millis();
    }
  }
  noTone(SPEAKERPIN);
}

// Note - circuit for vibration motor not working :(
void buzz() {
  digitalWrite(BUZZPIN, HIGH); 
  delay(5000);
  digitalWrite(BUZZPIN, LOW); 
  /*for (int i=0; i<20; i++) {
    digitalWrite(BUZZPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(150);                       // wait for a second
    digitalWrite(BUZZPIN, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
    delay(150);                       // wait for a second
  }  */
}

void ledandsounds() {
  long startEffect = millis();
  
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

