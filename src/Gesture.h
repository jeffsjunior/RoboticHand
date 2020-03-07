/*
 * Hand.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Jefferson Jr
 */

#ifndef GESTURE_H_
#define GESTURE_H_

#include <inttypes.h>

class Hand;

typedef void (Hand::*gestureFun)(void);

class Gesture{
    public:
        const char* const nameStr;
        gestureFun fun;

        Gesture();
        Gesture(const char* const str, void (Hand::*fun)(void));
        void runGesture(Hand* handObj);
};

#endif


