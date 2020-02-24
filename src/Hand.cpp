/*
 * Hand.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: Jefferson Jr
 */

#include "Hand.h"

Hand::Hand()
{
	for(int i = thumb; i <= wrist ; i++)
	{
		m_fingers[i] = Finger(i,FINGER_LOWER_LIMITS[i],FINGER_UPPER_LIMITS[i]);
	}

}

Hand::Hand(uint8_t idT, uint8_t idI, uint8_t idM, uint8_t idR, uint8_t idP, uint8_t idW)
{
	m_fingers[thumb]    = Finger(idT,FINGER_LOWER_LIMITS[thumb],FINGER_UPPER_LIMITS[thumb]);
	m_fingers[index]    = Finger(idI,FINGER_LOWER_LIMITS[index],FINGER_UPPER_LIMITS[index]);
	m_fingers[middle]   = Finger(idM,FINGER_LOWER_LIMITS[middle],FINGER_UPPER_LIMITS[middle]);
	m_fingers[ring]     = Finger(idR,FINGER_LOWER_LIMITS[ring],FINGER_UPPER_LIMITS[ring]);
	m_fingers[pinky]    = Finger(idP,FINGER_LOWER_LIMITS[pinky],FINGER_UPPER_LIMITS[pinky]);
	m_fingers[wrist]    = Finger(idW,FINGER_LOWER_LIMITS[wrist],FINGER_UPPER_LIMITS[wrist]);

}

void Hand::start(void){
    m_fingers[0].start();
}

void Hand::stop(void){
     m_fingers[0].stop();
}

void Hand::setFinger(uint8_t finger, uint16_t pos)
{
	m_fingers[finger].setPos(pos);
}
void Hand::setFinger(uint8_t finger, uint16_t pos, uint8_t vel)
{
	m_fingers[finger].setPos(pos,vel);
}

void Hand::setFinger(uint8_t finger, uint16_t pos, uint8_t vel, bool wait)
{
	m_fingers[finger].setPos(pos,vel,wait);
}

const char* Hand::menu()
{
	const char* s  = "Gestures: \n"
			"\t 1 - Count \n"
			"\t 2 - Peace \n"
			"\t 3 - Rock \n"
			"\t 4 - Open \n"
			"\t 5 - Close \n";

	return s;
}


void Hand::closeHand(uint8_t speed) {
	for (int i = thumb; i <= pinky; i++) {
		m_fingers[i].closeFinger(speed);
	}
}

void Hand::openHand(uint8_t speed) {
	for (int i = thumb; i <= pinky; i++) {
		m_fingers[i].openFinger(speed);
	}
}

void Hand::openFinger(hand_enum finger, uint8_t speed)
{
	m_fingers[finger].openFinger(speed);
}

void Hand::openFinger(hand_enum finger, uint8_t speed, bool wait)
{
	m_fingers[finger].openFinger(speed, wait);
}


void Hand::closeFinger(hand_enum finger,uint8_t speed)
{
	m_fingers[finger].closeFinger(speed);
}

void Hand::closeFinger(hand_enum finger,uint8_t speed, bool wait)
{
	m_fingers[finger].closeFinger(speed, wait);
}

void Hand::runGestures(int gest)
{
	switch(gest)
	{
        case count: countGest(); break;
        case peace: peaceGest(); break;
        case rock: rockGest(); break;
        case openH: openHand(SLOW); break;
        case closeH: closeHand(SLOW); break;
        case tranquilo: tranquilo_favoravel(); break;
	}
}

//Gestures definition
void Hand::countGest()
{
	closeHand(FAST);
	delay(200);
	openFinger(index,SLOW,WAIT);
	delay(200);
	openFinger(middle,SLOW,WAIT);
	delay(200);
	openFinger(ring,SLOW,WAIT);
	delay(200);
	openFinger(pinky,SLOW,WAIT);
	delay(200);
	openFinger(thumb,SLOW,WAIT);
	delay(200);
	closeFinger(index,FAST);
	closeFinger(middle,FAST);
	closeFinger(ring,FAST);
	closeFinger(pinky,FAST);
	delay(200);
	openFinger(index,SLOW,WAIT);
	delay(200);
	openFinger(middle,SLOW,WAIT);
	delay(200);
	openFinger(ring,SLOW,WAIT);
	delay(200);
	openFinger(pinky,SLOW,WAIT);

}

void Hand::peaceGest()
{
	closeFinger(thumb,SLOW);
	openFinger(index,SLOW);
	openFinger(middle,SLOW);
	closeFinger(ring,SLOW);
	closeFinger(pinky,SLOW);
}

void Hand::rockGest()
{
	closeFinger(thumb,SLOW);
	openFinger(index,SLOW);
	closeFinger(middle,SLOW);
	closeFinger(ring,SLOW);
	openFinger(pinky,SLOW);
}

void Hand::tranquilo_favoravel()
{
	openFinger(thumb,SLOW);
	closeFinger(index,SLOW);
	closeFinger(middle,SLOW);
	closeFinger(ring,SLOW);
	openFinger(pinky,SLOW);
	for(int i = 0; i < 4; i++)
	{
		openFinger(wrist,SLOW,WAIT);
		delay(300);
		closeFinger(wrist,SLOW,WAIT);
		delay(300);
	}
	m_fingers[wrist].setPos(90,SLOW,false);
}

Hand::~Hand() {
	// TODO Auto-generated destructor stub
}

