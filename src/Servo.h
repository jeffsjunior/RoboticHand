#ifndef Servo_h
#define Servo_h
#include <inttypes.h>
#include <TimerOne.h>

#define SERVO_FREQ 50
#define MAX_SERVOS  16
#define INVALID_SERVO 255

#define DEFAULT_PW 200
#define MIN_PW 96
#define MAX_PW 440

typedef struct {
    uint16_t id;
    volatile uint16_t pos;
	volatile uint16_t target;
	volatile uint8_t vel;
} servo_t;


class Servo {
    public:
        Servo();
        Servo(uint8_t id, uint16_t min = MIN_PW, uint16_t max = MAX_PW);

        void write(uint16_t value);
        void write(uint16_t value, uint8_t vel);
        void write(uint16_t value, uint8_t vel, bool wait);
        void start(void);
        void stop(void);

    //private:
    static void updateServo(void);
        uint8_t id;
        uint8_t servoIndex;
        uint16_t min;
        uint16_t max;

};

#endif