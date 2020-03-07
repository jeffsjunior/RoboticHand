/*
 * Hand.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Jefferson Jr
 */

#ifndef HAND_H_
#define HAND_H_

#include "Finger.h"
#include "Gesture.h"
#include <inttypes.h>

//Define the Servo Limits

const int THUMB_LOWER_LIMIT  = 180;
const int THUMB_UPPER_LIMIT  = 440;

const int INDEX_LOWER_LIMIT  = 100;
const int INDEX_UPPER_LIMIT  = 440;

const int MIDDLE_LOWER_LIMIT = 190;
const int MIDDLE_UPPER_LIMIT = 440;

const int RING_LOWER_LIMIT   = 200;
const int RING_UPPER_LIMIT   = 440;

const int PINKY_LOWER_LIMIT  = 200;
const int PINKY_UPPER_LIMIT  = 440;

const int WRIST_LOWER_LIMIT  = 96;
const int WRIST_UPPER_LIMIT  = 440;

const int FINGER_LOWER_LIMITS[] = {THUMB_LOWER_LIMIT,INDEX_LOWER_LIMIT,
                                  MIDDLE_LOWER_LIMIT,RING_LOWER_LIMIT,
                                  PINKY_LOWER_LIMIT,WRIST_LOWER_LIMIT};
const int FINGER_UPPER_LIMITS[] = {THUMB_UPPER_LIMIT,INDEX_UPPER_LIMIT,
                                  MIDDLE_UPPER_LIMIT,RING_UPPER_LIMIT,
                                  PINKY_UPPER_LIMIT,WRIST_UPPER_LIMIT};


class Hand {

private:
	Finger m_fingers[6];
    //Gesture gestObj = Gesture();

    Gesture gestObj[2] = {Gesture("teste", &Hand::testGest),
                          Gesture("teste2",&Hand::testGest)
                         };
public:
    const uint8_t FAST = 55;
    const uint8_t MEDIUM = 25;
	const uint8_t SLOW = 10;
	const bool WAIT = true;

	enum hand_enum {
	  thumb = 0,
	  index,
	  middle,
	  ring,
	  pinky,
	  wrist
	};

	Hand();
    Hand(uint8_t idT, uint8_t idI, uint8_t idM, uint8_t idR, uint8_t idP, uint8_t idW);
    void start(void);
    void stop(void);
    void setFinger(uint8_t finger, uint16_t pos);
    void setFinger(uint8_t finger, uint16_t pos, uint8_t vel);
    void setFinger(uint8_t finger, uint16_t pos, uint8_t vel, bool wait);
	void closeHand(uint8_t speed);
	void openHand(uint8_t speed);
	void openFinger(hand_enum finger,uint8_t speed);
	void openFinger(hand_enum finger,uint8_t speed, bool wait);
	void closeFinger(hand_enum finger,uint8_t speed);
	void closeFinger(hand_enum finger,uint8_t speed, bool wait);

    void thumbGest(void);
    void indexGest(void);
    void middleGest(void);
    void ringGest(void);
    void pinkyGest(void);
    void testGest(void);
	void runGesture(int gest);
	const char* menu();

	//Gestures
	void countGest();
	void peaceGest();
	void rockGest();
	void tranquilo_favoravel();
	virtual ~Hand();
};

#endif /* HAND_H_ */


