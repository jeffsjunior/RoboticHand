#include "Gesture.h"
#include "Hand.h"

Gesture::Gesture(): nameStr{"no gesture"}, fun{nullptr}{}
Gesture::Gesture(const char* const str, void (Hand::*fun)(void)):nameStr{str},fun{fun}{}


void Gesture::runGesture(Hand* handObj){
    (handObj->*fun)();
    return;
}
