#pragma once
#include <Arduino.h>

struct FireData {
    int ignitionDelay = 100;
    int valveOpenTime = 300;
    int delayAfterValve = 100;
    int delayBetweenShots = 500;
    float currentVoltage = 12.6;
    bool fire = false;
    enum fireMode {
            single = 0,
            burst = 1,
            continues = 2
        };
    uint8_t currentMode = fireMode::single;
    };

    extern FireData fireData;

class Settings
{

};