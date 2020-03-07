#include <Arduino.h>
#include "Hand.h"
#include "HMM.h"


//Define the fingers ID's
#define  THUMB_ID   0
#define  INDEX_ID   1
#define  MIDDLE_ID  2
#define  RING_ID    5
#define  PINKY_ID   7
#define  WRIST_ID   8

Hand myHand = Hand(THUMB_ID, INDEX_ID, MIDDLE_ID, RING_ID, PINKY_ID, WRIST_ID);
sState sCurrent  = statesArray[sHappy];

void setup(void)
{
  myHand.start();
  Serial.begin(9600);
}

void loop(void)
{
    sCurrent = nextState(sCurrent);
    tBehavior selectedBehavior = runBehavior(sCurrent, myHand);
    printData(sCurrent, selectedBehavior);
    delay(5000); //You should remove the delay if testing the probabilities
}



