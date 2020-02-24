#include <Arduino.h>
#include "Finger.h"
#include "Hand.h"

//Define the fingers pins
#define  THUMB_ID   0
#define  INDEX_ID   1
#define  MIDDLE_ID  2
#define  RING_ID    5
#define  PINKY_ID   7
#define  WRIST_ID   8

Hand myHand = Hand(THUMB_ID, INDEX_ID, MIDDLE_ID, RING_ID, PINKY_ID, WRIST_ID);


uint8_t gest;
void setup(void)
{
  myHand.start();
  Serial.begin(9600);
}

void loop(void)
{
	Serial.println(myHand.menu());
	while(Serial.available() == 0){};
	gest = Serial.parseInt();
	myHand.runGestures(gest);
}



