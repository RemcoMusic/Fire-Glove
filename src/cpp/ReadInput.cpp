#include "h/ReadInput.h"

void ReadInput::start()
{
    pinMode(button, INPUT_PULLUP);
}

bool ReadInput::readButton()    
{
  int value = digitalRead(button);
  if(value == 0) //Button is pressed
  { 
    pressCounter++;
    if(pressCounter > sensitivity) //Added counter to reduce bounceback
    {
        Serial.println("Button triggered");
        pressCounter = 0;
        return true;
    }
  }
  else //Button is not pressed
  {
    return false;
  }
}

float ReadInput::mapFloat(long x, long in_min, long in_max, long out_min, long out_max)
{
 return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

float ReadInput::readVoltage()    
{
  float adcValue= analogRead(VoltagePin);
  adcValue = mapFloat(adcValue, 0, 4095, 0, 13.2);
  return adcValue;
}

