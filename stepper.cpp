#include "stepper.h"
using namespace std;

Stepper::Stepper(PinName pin1, PinName pin2, PinName pin3, PinName pin4):
    out1(DigitalOut(pin1)),
    out2(DigitalOut(pin2)),
    out3(DigitalOut(pin3)),
    out4(DigitalOut(pin4)) {
    this->pin1 = pin1;
    this->pin2 = pin2;
    this->pin3 = pin3;
    this->pin4 = pin4;
}

void Stepper::stepForward(int steps) {
    for (int i = 0; i < steps; i++) {    
        out4 = 0;
        out1 = 1;
        wait_us(wait_flip);
        out1 = 0;
        out2 = 1;
        wait_us(wait_flip);
        out2 = 0;
        out3 = 1;
        wait_us(wait_flip);
        out3 = 0;
        out4 = 1;
        wait_us(wait_step);
    }
}

void Stepper::stepBackward(int steps) {
    for (int i = 0; i < steps; i++) {
        out3 = 0;
        out4 = 1;
        wait_us(wait_flip);
        out2 = 0;
        out3 = 1;
        wait_us(wait_flip);
        out1 = 0;
        out2 = 1;
        wait_us(wait_flip);
        out4 = 0;
        out1 = 1;
        wait_us(wait_step);
    }
}