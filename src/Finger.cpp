/*
 * Finger.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: Jefferson Jr
 */

#include "Finger.h"

//#include <stdint.h>

Finger::Finger(){

}

Finger::Finger(uint8_t id, uint16_t lowerLimit = 96, uint16_t upperLimit = 440):
	m_lowerLimit(lowerLimit),
	m_upperLimit(upperLimit), 
    m_servo(id, lowerLimit, upperLimit){}


void Finger::openFinger(uint8_t speed)
{
	m_servo.write(m_lowerLimit,speed);
}

void Finger::openFinger(uint8_t speed,bool wait)
{
	m_servo.write(m_lowerLimit,speed,wait);
}

void Finger::closeFinger(uint8_t speed)
{
	m_servo.write(m_upperLimit,speed);
}

void Finger::closeFinger(uint8_t speed, bool wait)
{
	m_servo.write(m_upperLimit,speed, wait);
}

void Finger::setPos(uint16_t pos){
    m_servo.write(pos);
}

void Finger::setPos(uint16_t pos, uint8_t speed){
    m_servo.write(pos,speed);
}

void Finger::setPos(uint16_t pos, uint8_t speed, bool wait)
{
	if (pos > m_upperLimit)
		pos = m_upperLimit;
	else if (pos < m_lowerLimit)
		pos = m_lowerLimit;

	m_servo.write(pos,speed,wait);

}

void Finger::start(void){
    m_servo.start();
}

void Finger::stop(void){
    m_servo.stop();
}

Finger::~Finger() {
	// TODO Auto-generated destructor stub
}

