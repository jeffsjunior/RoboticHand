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

void Hand::setFinger(fingerName finger, uint16_t pos)
{
	m_fingers[finger].setPos(pos);
}
void Hand::setFinger(fingerName finger, uint16_t pos, uint8_t vel)
{
	m_fingers[finger].setPos(pos,vel);
}

void Hand::setFinger(fingerName finger, uint16_t pos, uint8_t vel, bool wait)
{
	m_fingers[finger].setPos(pos,vel,wait);
}


String Hand::menu()
{
	
    String strMenu = String("Gestures: \n");
    for(uint8_t i = 0; i < numberOfGestures; i++){
        strMenu += "\t";
        strMenu += String(i);
        strMenu += " - ";
        strMenu += gestures[i].nameStr;
        strMenu += "\n";
    }

	return strMenu;
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

void Hand::openFinger(fingerName finger, uint8_t speed)
{
	m_fingers[finger].openFinger(speed);
}

void Hand::openFinger(fingerName finger, uint8_t speed, bool wait)
{
	m_fingers[finger].openFinger(speed, wait);
}


void Hand::closeFinger(fingerName finger,uint8_t speed)
{
	m_fingers[finger].closeFinger(speed);
}

void Hand::closeFinger(fingerName finger,uint8_t speed, bool wait)
{
	m_fingers[finger].closeFinger(speed, wait);
}

void Hand::runGesture(int gest) 
{
    (this->*gestures[gest].fun)(gestures[gest].speed);
}

//Gestures definition
void Hand::countGest(uint8_t speed)
{
	closeHand(speed);
	delay(200);
	openFinger(index,speed,WAIT);
	delay(200);
	openFinger(middle,speed,WAIT);
	delay(200);
	openFinger(ring,speed,WAIT);
	delay(200);
	openFinger(pinky,speed,WAIT);
	delay(200);
	openFinger(thumb,speed,WAIT);
	delay(200);
	closeFinger(index,speed);
	closeFinger(middle,speed);
	closeFinger(ring,speed);
	closeFinger(pinky,speed);
	delay(200);
	openFinger(index,speed,WAIT);
	delay(200);
	openFinger(middle,speed,WAIT);
	delay(200);
	openFinger(ring,speed,WAIT);
	delay(200);
	openFinger(pinky,speed,WAIT);

}

void Hand::peaceGest(uint8_t speed)
{
	closeFinger(thumb,speed);
	openFinger(index,speed);
	openFinger(middle,speed);
	closeFinger(ring,speed);
	closeFinger(pinky,speed);
}

void Hand::rockGest(uint8_t speed)
{
	closeFinger(thumb,speed);
	openFinger(index,speed);
	closeFinger(middle,speed);
	closeFinger(ring,speed);
	openFinger(pinky,speed);
}

void Hand::tranquilo_favoravel(uint8_t speed)
{
	openFinger(thumb,speed);
	closeFinger(index,speed);
	closeFinger(middle,speed);
	closeFinger(ring,speed);
	openFinger(pinky,speed);
	for(int i = 0; i < 4; i++)
	{
		openFinger(wrist,speed,WAIT);
		delay(300);
		closeFinger(wrist,speed,WAIT);
		delay(300);
	}
	m_fingers[wrist].setPos(90,speed,false);
}

void Hand::thumbGest(uint8_t speed){	
	openFinger(thumb,speed,WAIT);
	delay(200);
	closeFinger(thumb,speed,WAIT);
    delay(200);
}

void Hand::indexGest(uint8_t speed){	
	openFinger(index,speed,WAIT);
	delay(200);
	closeFinger(index,speed,WAIT);
    delay(200);
}

void Hand::middleGest(uint8_t speed){	
	openFinger(middle,speed,WAIT);
	delay(200);
	closeFinger(middle,speed,WAIT);
    delay(200);
}

void Hand::ringGest(uint8_t speed){	
	openFinger(ring,speed,WAIT);
	delay(200);
	closeFinger(ring,speed,WAIT);
    delay(200);
}

void Hand::pinkyGest(uint8_t speed){	
	openFinger(pinky,speed,WAIT);
	delay(200);
	closeFinger(pinky,speed,WAIT);
    delay(200);
}

void Hand::testGestOne(uint8_t speed){
    Serial.println("\ntestGestOne\n");
    Serial.println(speed);
}

void Hand::testGestTwo(uint8_t speed){
    Serial.println("\ntestGestOne\n");
    Serial.println(speed);
}




