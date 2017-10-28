#include "IRLibAll.h"

//Create a receiver object to listen on pin 2
IRrecvPCI myReceiver(1);

//Create a decoder object 
IRdecode myDecoder;   

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
          break;
        case 0xFD8877:  //2
          Serial.println("2");
          break;
        case 0xFD48B7:  //3
          Serial.println("3");
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
