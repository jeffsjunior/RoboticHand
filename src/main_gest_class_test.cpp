#include <Arduino.h>
#include "Finger.h"
#include "Hand.h"
#include "Gesture.h"


//Define the fingers pins
#define  THUMB_ID   0
#define  INDEX_ID   1
#define  MIDDLE_ID  2
#define  RING_ID    3
#define  PINKY_ID   4
#define  WRIST_ID   5

Hand myHand = Hand(THUMB_ID, INDEX_ID, MIDDLE_ID, RING_ID, PINKY_ID, WRIST_ID);
//Gesture gest[2] = {Gesture("teste",&Hand::testGest),
//                   Gesture("teste2",&Hand::testGest)
//                  };

void setup(void)
{
  Serial.begin(9600);
}

void loop(void)
{
	//Serial.println(gest[0].nameStr);
    myHand.runGesture(0);
   // gest[0].runGesture(myHand);
   // Serial.println(gest[1].nameStr);
    //gest[1].runGesture(myHand);
    delay(1000);
}



