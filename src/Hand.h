/*
 * Hand.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Jefferson Jr
 */

#ifndef HAND_H_
#define HAND_H_

#include "Finger.h"
#include <inttypes.h>

//Define the Servo Limits

const int THUMB_LOWER_LIMIT  = 180;
const int THUMB_UPPER_LIMIT  = 440;
const int THUMB_MIDDLE_LIMIT = (THUMB_LOWER_LIMIT + THUMB_UPPER_LIMIT)/2;

const int INDEX_LOWER_LIMIT  = 100;
const int INDEX_UPPER_LIMIT  = 440;
const int INDEX_MIDDLE_LIMIT = (INDEX_LOWER_LIMIT + INDEX_UPPER_LIMIT)/2;

const int MIDDLE_LOWER_LIMIT = 190;
const int MIDDLE_UPPER_LIMIT = 440;
const int MIDDLE_MIDDLE_LIMIT = (MIDDLE_LOWER_LIMIT + MIDDLE_UPPER_LIMIT)/2;

const int RING_LOWER_LIMIT   = 200;
const int RING_UPPER_LIMIT   = 440;
const int RING_MIDDLE_LIMIT = (RING_LOWER_LIMIT + RING_UPPER_LIMIT)/2;

const int PINKY_LOWER_LIMIT  = 200;
const int PINKY_UPPER_LIMIT  = 440;
const int PINKY_MIDDLE_LIMIT = (PINKY_LOWER_LIMIT + PINKY_UPPER_LIMIT)/2;

const int WRIST_LOWER_LIMIT  = 96;
const int WRIST_UPPER_LIMIT  = 440;
const int WRIST_MIDDLE_LIMIT = (WRIST_LOWER_LIMIT + WRIST_UPPER_LIMIT)/2;

const int FINGER_LOWER_LIMITS[] = {THUMB_LOWER_LIMIT,INDEX_LOWER_LIMIT,
                                  MIDDLE_LOWER_LIMIT,RING_LOWER_LIMIT,
                                  PINKY_LOWER_LIMIT,WRIST_LOWER_LIMIT};

const int FINGER_MIDDLE_LIMITS[] = {THUMB_MIDDLE_LIMIT,INDEX_MIDDLE_LIMIT,
                                    MIDDLE_MIDDLE_LIMIT,RING_MIDDLE_LIMIT,
                                    PINKY_MIDDLE_LIMIT,WRIST_MIDDLE_LIMIT};

const int FINGER_UPPER_LIMITS[] = {THUMB_UPPER_LIMIT,INDEX_UPPER_LIMIT,
                                  MIDDLE_UPPER_LIMIT,RING_UPPER_LIMIT,
                                  PINKY_UPPER_LIMIT,WRIST_UPPER_LIMIT};



class Hand {

    


public:
    static const uint8_t VERY_FAST = 55;
    static const uint8_t FAST = 35;
    static const uint8_t MEDIUM = 25;
	static const uint8_t SLOW = 10;
    static const uint8_t VERY_SLOW = 5;
    
	const bool WAIT = true;

	enum fingerName {
	  thumb = 0,
	  index,
	  middle,
	  ring,
	  pinky,
	  wrist
	};



private:

    typedef void (Hand::*gestureFun)(uint8_t);
    
    typedef struct{
        const char* nameStr;
        gestureFun fun;
        uint8_t speed;
    } gesture_t;

	Finger m_fingers[6];

    static const uint8_t numberOfGestures = 6;
    gesture_t gestures[numberOfGestures] = {
                                            {"OpenHand", &Hand::openHand, FAST},
                                            {"CloseHand", &Hand::closeHand, FAST},
                                            {"Count", &Hand::countGest, FAST},
                                            {"Peace", &Hand::peaceGest, FAST},
                                            {"Rock", &Hand::rockGest, FAST},
                                            {"ShakaWrist", &Hand::shakaWristGest, FAST}

                                            //shakarockGest
                                            //OKGest
                                            //middleFingerGest
                                            //lazyGest
                                            //halfLazyGest
                                            };

public:

	Hand();
    Hand(uint8_t idT, uint8_t idI, uint8_t idM, uint8_t idR, uint8_t idP, uint8_t idW);
    void start(void);
    void stop(void);
    void setFinger(fingerName finger, uint16_t pos);
    void setFinger(fingerName finger, uint16_t pos, uint8_t vel);
    void setFinger(fingerName finger, uint16_t pos, uint8_t vel, bool wait);
	void runGesture(int gest);

	String menu();

	//Finger Gestures
    void openFinger(fingerName finger,uint8_t speed);
	void openFinger(fingerName finger,uint8_t speed, bool wait);
	void closeFinger(fingerName finger,uint8_t speed);
	void closeFinger(fingerName finger,uint8_t speed, bool wait);

    void thumbGest(uint8_t speed);
    void indexGest(uint8_t speed);
    void middleGest(uint8_t speed);
    void ringGest(uint8_t speed);
    void pinkyGest(uint8_t speed);

    //Hand Gestures
    //typedef enum {sOK, sPeace, sShaka, 
//              sLoose, sClosed, sOpen,
//              sMiddleFinger, sRock, sRockShaka,
//              nBehavior} tBehavior;


    void closeHand(uint8_t speed);
	void openHand(uint8_t speed);

    void countGest(uint8_t speed);
	void peaceGest(uint8_t speed);
	void rockGest(uint8_t speed);
	void shakaWristGest(uint8_t speed);

};

#endif /* HAND_H_ */


