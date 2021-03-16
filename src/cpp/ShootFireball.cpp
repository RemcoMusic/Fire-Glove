#include <Arduino.h>
#include "h/ShootFireball.h"

void ShootFireball::setup()
{
    pinMode(solenoid, OUTPUT);
    pinMode(ignition, OUTPUT);
    digitalWrite(solenoid, LOW);
    digitalWrite(ignition,LOW);
}

void ShootFireball::shootFireball(int amount)
{   
    for(int x = 0; x < amount;x++)
    {
      setIgnition(1);
      delay(fireData.ignitionDelay);
      setValve(1);
      delay(fireData.delayAfterValve);
      setIgnition(0);
      delay(fireData.valveOpenTime - fireData.delayAfterValve);
      setValve(0); 
      delay(fireData.delayBetweenShots);
    }
}

void ShootFireball::setValve(int state)
{
  if(state == 1)
  {
    digitalWrite(solenoid, HIGH);
    Serial.println("Valve open");
  }
  else if(state == 0)
  {
    digitalWrite(solenoid, LOW);
    Serial.println("valve closed");
  }
}

void ShootFireball::setIgnition(int state)
{
  if(state == 1)
  {
    digitalWrite(ignition, HIGH);
    Serial.println("Ignition started!");
  }
  else if(state == 0)
  {
    digitalWrite(ignition, LOW);
    Serial.println("Ignition stopped!");
  }
}