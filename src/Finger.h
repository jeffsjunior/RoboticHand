/*
 * Finger.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Jefferson Jr
 */

#ifndef FINGER_H_
#define FINGER_H_

#include "Servo.h"
#include <inttypes.h>
class Finger {


private:

	uint16_t m_lowerLimit;
	uint16_t m_upperLimit;
	Servo m_servo;

public:
    Finger();
    Finger(uint8_t id, uint16_t lowerLimit, uint16_t upperLimit);

	void openFinger(uint8_t speed);
	void openFinger(uint8_t speed,bool wait);
	void closeFinger(uint8_t speed);
	void closeFinger(uint8_t speed, bool wait);
    void setPos(uint16_t pos);
    void setPos(uint16_t pos, uint8_t speed);
	void setPos(uint16_t pos, uint8_t speed, bool wait);
    void start(void);
    void stop(void);
	virtual ~Finger();
};

#endif /* FINGER_H_ */
