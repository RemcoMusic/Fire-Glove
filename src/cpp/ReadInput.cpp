#include "h/ReadInput.h"

void ReadInput::start()
{
    pinMode(button, INPUT_PULLUP);
}

bool ReadInput::readButton()    
{
  int value = digitalRead(button);
  if(value == 0 || fireData.fire) //pressed
  { 
    pressCounter++;
    if(((pressCounter > sensitivity) && value == buttonState) || fireData.fire) //added counter to reduce bounceback
    {
        fireData.fire = false;
        buttonState = true;
        Serial.println("Button triggered");
        pressCounter = 0;
    }
  }
  else //not pressed
  {
    pressCounter = 0;
    releaseCounter++;
    if((releaseCounter > sensitivity) && value == buttonState) //added counter to reduce bounceback
    { 
      buttonState = false;
      Serial.println("Button released");
      releaseCounter = 0;
    }
  }
  return buttonState;
}

//TODO Use map function from Arduino? Or get rid of function.
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

