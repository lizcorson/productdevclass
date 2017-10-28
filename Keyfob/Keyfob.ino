/*#include <IRLib2.h>
#include <IRLibAll.h>
#include <IRLibDecodeBase.h>
#include <IRLibGlobals.h>
#include <IRLibRecvBase.h>
#include <IRLibRecvLoop.h>*/

#include "IRLibAll.h"
//#include "IRLibSAMD21.h"

//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(1);

//Create a decoder object 
IRdecode myDecoder;   

//Buzzer
#define SPEAKERPIN 4
#define BUZZPIN 0
#define LEDPIN 3
 
//int numTones = 10;
//int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
//            mid C  C#   D    D#   E    F    F#   G    G#   A

int numTones = 2;
int numLoops = 5;
int tones[] = {100, 500};

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
  for (int i=0; i<20; i++) {
    digitalWrite(LEDPIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(150);                       // wait for a second
    digitalWrite(LEDPIN, LOW);    // turn the LED off by making the voltage LOW
    delay(150);                       // wait for a second
  }
  
}

void sounds() {
  for (int j=0; j < numLoops; j++) {
    for (int i = 0; i < numTones; i++) {
      tone(SPEAKERPIN, tones[i]);
      delay(500);
    }
    noTone(SPEAKERPIN);
  }
}

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

