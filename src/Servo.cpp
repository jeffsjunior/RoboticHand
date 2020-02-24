#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "Servo.h"

static Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

static volatile servo_t servos[MAX_SERVOS];
static uint8_t numberOfServos = 0;
static bool updateStarted = false;

static volatile uint8_t sIdx = 0;

// TODO: Limitar a quantidade de servos e dar erro se ultrapassar
// TODO: Iniciar os servos em uma posição default
// TODO: Adicionar stop() (parar o servo)
// TODO: Acelerar i2c do driver
Servo::Servo(){
    
}
Servo::Servo(uint8_t id, uint16_t min, uint16_t max)
{
  //if( numberOfServos < MAX_SERVOS) {
    this->servoIndex = numberOfServos++;
	servos[this->servoIndex].pos = DEFAULT_PW;
    servos[this->servoIndex].id = id;
    this->id = id;
    this->min = min;
    this->max = max;
 // }
  //else {
  //  this->servoIndex = INVALID_SERVO ;  // too many servos
  //}
}

void Servo::write(uint16_t value){
    pwm.setPWM(this->id, 0, constrain(value, this->min, this->max)); 
}

void Servo::write(uint16_t value, uint8_t vel){
    servos[this->servoIndex].target = constrain(value, this->min, this->max);
    servos[this->servoIndex].vel = vel;
}

void Servo::write(uint16_t value, uint8_t vel, bool wait){
    this->write(value, vel);
    if(wait){
        while(servos[this->servoIndex].pos !=  servos[this->servoIndex].target){
            delay(1);
        }
    }
}

void Servo::start(void){
    if(!updateStarted){
        updateStarted = true;
        pinMode(LED_BUILTIN, OUTPUT);
        Timer1.initialize(33333/numberOfServos);
        Timer1.attachInterrupt(updateServo); 
        pwm.begin();
        pwm.setOscillatorFrequency(27000000);  // The int.osc. is closer to 27MHz  
        pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
    }
}

void Servo::stop(void){
    if(updateStarted){
        Timer1.stop();
    }
}


void Servo::updateServo(void)
{
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);   // toggle LED pin
    sei();
    if(servos[sIdx].vel){
        if(servos[sIdx].target > servos[sIdx].pos){
            servos[sIdx].pos += servos[sIdx].vel;
            if(servos[sIdx].target <= servos[sIdx].pos){
                servos[sIdx].pos = servos[sIdx].target;
                servos[sIdx].vel = 0;
            }
        }
        else {         
            servos[sIdx].pos -= servos[sIdx].vel;
            if(servos[sIdx].target >= servos[sIdx].pos){
                servos[sIdx].pos = servos[sIdx].target;
                servos[sIdx].vel = 0;
            }
        }
        pwm.setPWM(servos[sIdx].id,0,servos[sIdx].pos); 
    }
    if(++sIdx >= numberOfServos){
        sIdx = 0;
    }
    cli();
}