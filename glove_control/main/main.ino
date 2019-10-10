
#include "pinout.h" //contain the pinout for encoder, pwm, and pot
#include <FreeRTOS_ARM.h>
#include "queue.h"

IntervalTimer myTimer;

void setup() 
{
  setup_motor_encoder();
  setup_interrupt();
  setup_multi_threading();
  
}

// loop must never block
void loop() 
{
  // No code should be in this loop.
}
