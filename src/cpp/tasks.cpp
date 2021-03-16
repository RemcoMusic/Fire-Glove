#include <Arduino.h>
#include "h/tasks.h"

ReadInput ReadInputs;
ShootFireball Ignition;

TaskHandle_t TaskHandle_Inputs;
bool buttonState = false;

Tasks::Tasks()
{
    xTaskCreate(
        ReadInputTask,
        "ReadInputs",
        10000,
        NULL,
        1,
        &TaskHandle_Inputs);

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
    int startupDelay = 2500;
    delay(startupDelay);

    Serial.println("Reading inputs");
    ReadInputs.start();

    for(;;)
    {         
        buttonState = ReadInputs.readButton();
            
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
}

void Tasks::ShootFireballTask(void * parameter)
{
    Ignition.setup();
    for(;;)
    {
        if(buttonState)
        {
            vTaskSuspend(TaskHandle_Inputs);
            if(fireData.currentMode == fireData.single)
            {
                Serial.println("Fireball");
                Ignition.shootFireball(1);
            }
            else if(fireData.currentMode == fireData.burst)
            {
                Serial.println("Burst");
                Ignition.shootFireball(2); 
            }
            vTaskResume(TaskHandle_Inputs);
        }
        vTaskDelay(10/portTICK_PERIOD_MS);
    }
}