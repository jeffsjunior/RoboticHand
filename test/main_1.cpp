#include <Arduino.h>
#include "Servo.h"

Servo servo0 = Servo(0, 100, 440);
Servo servo1 = Servo(1, 90, 460);
Servo servo2 = Servo(2, 110, 440);
Servo servo3 = Servo(5, 100, 430);
Servo servo4 = Servo(7, 100, 430);

const uint16_t minidelay = 100; 
unsigned int counter = 0;
void setup(void)
{
  servo0.start();
  Serial.begin(9600);
}


void loop(void)
{
    if(counter < 3){
        servo0.write(0, 15, 1);
        delay(minidelay);
        servo1.write(0, 15, 1);
        delay(minidelay);
        servo2.write(0, 15);
        delay(minidelay);
        servo3.write(0, 15);
        delay(minidelay);
        servo4.write(0, 15);
        delay(1000);
        
        servo4.write(1000, 15, 1);
        delay(minidelay);
        servo3.write(1000, 15, 1);
        delay(minidelay);
        servo2.write(1000, 15);
        delay(minidelay);
        servo1.write(1000, 15);
        delay(minidelay);
        servo0.write(1000, 15);
        delay(1000);
    }


    counter++;
    delay(100);
}



