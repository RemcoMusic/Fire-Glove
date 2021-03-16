#pragma once
#include <Arduino.h>
#include "h/Settings.h"

class ReadInput
{
    public:
        void start();
        float readVoltage();
        bool readButton();
    private:
        float mapFloat(long x, long in_min, long in_max, long out_min, long out_max);
        bool inputDetected = false;
        bool buttonState = false;
        int button = 13; 
        int VoltagePin = 34; //D34
        int pressCounter = 0;
        int releaseCounter = 0;
        int sensitivity = 5;
        float currentVoltage = 12.6;
};