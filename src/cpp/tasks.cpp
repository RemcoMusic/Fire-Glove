#include <Arduino.h>
#include "h/tasks.h"

bool buttonState = false;
bool previousButtonState = false;
const unsigned long eventInterval = 10000;
unsigned long previousTime = 0;
bool shooting = false;
int startupDelay = 2500;

ReadInput ReadInputs;
ShootFireball Ignition;

    Tasks::Tasks()
    {
        xTaskCreate(
            ReadInputTask,
            "ReadInputs",
            10000,
            NULL,
            1,
            NULL);

        xTaskCreate(
            ShootFireballTask,
            "Fire",
            10000,
            NULL,
            1,
            NULL);
    }

    void Tasks::ReadInputTask(void * parameter)
    {
        delay(startupDelay);
        Serial.println("Input started");
        ReadInputs.start();
        for(;;)
        {
            //If statement does nothing? buttonState allready true            
            if(ReadInputs.readButton())
            {
                buttonState = true;
            }
            else
            {
                buttonState = false;
            }
            vTaskDelay(10/portTICK_PERIOD_MS);
        }
    }

    void Tasks::ShootFireballTask(void * parameter)
    {
        Ignition.setup();
        for(;;)
        {
            if(buttonState && (buttonState != previousButtonState))
            {
                if(fireData.currentMode == fireData.single)
                {
                    previousButtonState = buttonState;  
                    Serial.println("Fireball");
                    shooting = true;
                    Ignition.shootFireball(1);
                }
                else if(fireData.currentMode == fireData.burst)
                {
                    previousButtonState = buttonState;  
                    Serial.println("Burst");
                    shooting = true;
                    Ignition.shootFireball(2); 
                }
            }
            else if(!buttonState && (buttonState != previousButtonState)) //Unnecessary since it should always be off
            {
                Serial.println("Idle");
                previousButtonState = buttonState;
                Ignition.idle();
            }
            vTaskDelay(10/portTICK_PERIOD_MS);
        }
    }