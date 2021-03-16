#include <Arduino.h>
#include <WiFi.h>
#include "h/tasks.h"

void setup() 
{
  Serial.begin(115200);
  //Powersaving mode
  btStop();
  WiFi.mode(WIFI_OFF);
  
  Tasks initTasks; 
  Serial.println("Setup done!");
}

void loop()
{
  //do nothing
}