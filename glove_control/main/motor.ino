#include "motor.h"
static void motor_control(void* arg) 
{
  while (1) 
  {
    struct encoder e={0,0,0,0,0,0};
    xQueueReceive(encoder_Queue, &e, portMAX_DELAY);
    Serial.println(e.tt);
    tt_pid(e.tt);
    Serial.println(tpwm);
    //--------------------------
//    tepwm = pid_control(tespeed, e.te);
//    ipwm = pid_control(ispeed, e.i);
//    mpwm = pid_control(mspeed, e.m);
//    rpwm = pid_control(rspeed, e.r);
//    ppwm = pid_control(pspeed, e.p);
    
    digitalWrite(thumbTip_dirPin,tdir);
    analogWrite(thumbTip_pwmPin, tpwm);

    digitalWrite(thumbEnd_dirPin,tedir);
    analogWrite(thumbEnd_pwmPin, tepwm);

    digitalWrite(index_dirPin,idir);
    analogWrite(index_pwmPin, ipwm);

    digitalWrite(middle_dirPin,mdir);
    analogWrite(middle_pwmPin, mpwm);

    digitalWrite(ring_dirPin,rdir);
    analogWrite(ring_pwmPin, rpwm);

    digitalWrite(pinky_dirPin,pdir);
    analogWrite(pinky_pwmPin, ppwm);
  }
}

void tt_pid(short curr)
{
  //-------------tt pid------------------
    short error = tspeed - curr;
    tt_integral = tt_integral + error;
    short derivative = error - tt_pre_error;
    tpwm = Kp*error + Ki* tt_integral + Kd * derivative;
    tt_pre_error = error;
}

void set_thumb_pwm(boolean dir, int PWM)
{
  tpwm = PWM;
  tdir = dir;
}

void set_thumb_end_pwm(boolean dir, int PWM)
{
  tepwm = PWM;
  tedir = dir;
}

void set_index_pwm(boolean dir, int PWM)
{
  ipwm = PWM;
  idir = dir;
}

void set_middle_pwm(boolean dir, int PWM)
{
  mpwm = PWM;
  mdir = dir;
}

void set_ring_pwm(boolean dir, int PWM)
{
  rpwm = PWM;
  rdir = dir;
}

void set_pinky_pwm(boolean dir, int PWM)
{
  ppwm = PWM;
  pdir = dir;
}
