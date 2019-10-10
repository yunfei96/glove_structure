#ifndef Q
#define Q
#include <FreeRTOS_ARM.h>

struct encoder
{
    short tt;
    short te; 
    short i;
    short m;
    short r;
    short p;
};

struct sensor
{
    struct encoder enc;
    short tt_pot; 
    short te_pot; 
    short i_pot; 
    short m_pot; 
    short r_pot; 
    short p_pot; 
};

//queues 
QueueHandle_t sensor_Queue;
QueueHandle_t encoder_Queue;

#endif
