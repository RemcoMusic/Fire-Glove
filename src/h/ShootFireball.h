#pragma once
#include <Arduino.h>
#include "h/Settings.h"

class ShootFireball
{
    public:
        void setup();
        void shootFireball(int amount);
    private:
        void setValve(int state);
        void setIgnition(int state);
        int solenoid = 4; //D4
        int ignition = 17; //TX2
};