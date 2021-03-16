#include "h/ReadInput.h"
#include "h/ShootFireball.h"

class Tasks
{
    public:
        Tasks();
        static void ReadInputTask(void * parameter);
        static void ShootFireballTask(void * parameter);
};