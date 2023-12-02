#include "stepper.h"

int main()
{
    PinName pin1;
    PinName pin2;
    PinName pin3;
    PinName pin4;
    Stepper stepper(pin1, pin2, pin3, pin4);
    while (true) {
        stepper.stepForward(500);
        ThisThread::sleep_for(100ms);
        stepper.stepBackward(500);
    }
}
