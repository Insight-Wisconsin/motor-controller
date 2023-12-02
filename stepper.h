#ifndef STEPPER_H_
#define STEPPER_H_

#include "mbed.h"

#define wait_step 500 // wait between each step, in μs
#define wait_flip 20 // wait between flipping pin out, in μs

class Stepper {
    public:
        PinName pin1;
        PinName pin2;
        PinName pin3;
        PinName pin4;

        Stepper(PinName pin1, PinName pin2, PinName pin3, PinName pin4);
        void stepForward(int steps);
        void stepBackward(int steps);
    
    private:
        DigitalOut out1;
        DigitalOut out2;
        DigitalOut out3;
        DigitalOut out4;
};

#endif // STEPPER_H_