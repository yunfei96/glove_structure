#include "motor.h"
static void motor_control(void* arg) 
{
  while (1) 
  {
    struct encoder e={0,0,0,0,0,0};
    xQueueReceive(encoder_Queue, &e, portMAX_DELAY);
    //Serial.println(e.tt);
    tt_pid(e.tt);
    //Serial.println(tpwm);
    //--------------------------
    //tt_pid(e.tt);
    i_pid(e.i);
    m_pid(e.m);
    r_pid(e.r);
    p_pid(e.p);
    Serial.println(mpwm);
    
    
    //send the command to the motor
    digitalWrite(thumbTip_dirPin,tdir);
    analogWrite(thumbTip_pwmPin, regulatePWM(tpwm));

    digitalWrite(thumbEnd_dirPin,tedir);
    analogWrite(thumbEnd_pwmPin, regulatePWM(tepwm));

    digitalWrite(index_dirPin,idir);
    analogWrite(index_pwmPin, regulatePWM(ipwm));

    digitalWrite(middle_dirPin,mdir);
    analogWrite(middle_pwmPin, regulatePWM(mpwm));

    digitalWrite(ring_dirPin,rdir);
    analogWrite(ring_pwmPin, regulatePWM(rpwm));

    digitalWrite(pinky_dirPin,pdir);
    analogWrite(pinky_pwmPin, regulatePWM(ppwm));
  }
}

int regulatePWM(int pid_pwm)
{
  if(pid_pwm >255){return 255;}
  if(pid_pwm < 0){return 0;}
  return pid_pwm;
}

//-------------------------------------PID calculation----------------------
void tt_pid(short curr)
{
  //-------------tt pid------------------
    short error = tspeed - curr;
    tt_integral = tt_integral + error;
    short derivative = error - tt_pre_error;
    tpwm = Kp*error + Ki* tt_integral + Kd * derivative;
    tt_pre_error = error;
}

void te_pid(short curr)
{
  //-------------te pid------------------
    short error = tespeed - curr;
    te_integral = te_integral + error;
    short derivative = error - te_pre_error;
    tepwm = Kp*error + Ki* te_integral + Kd * derivative;
    te_pre_error = error;
}

void i_pid(short curr)
{
  //-------------r pid------------------
    short error = ispeed - curr;
    i_integral = i_integral + error;
    short derivative = error - i_pre_error;
    ipwm = Kp*error + Ki* i_integral + Kd * derivative;
    r_pre_error = error;
}

void m_pid(short curr)
{
  //-------------m pid------------------
    short error = mspeed - curr;
    m_integral = m_integral + error;
    short derivative = error - m_pre_error;
    mpwm = Kp*error + Ki* m_integral + Kd * derivative;
    m_pre_error = error;
}

void r_pid (short curr)
{
  //-------------r pid------------------
    short error = rspeed - curr;
    r_integral = r_integral + error;
    short derivative = error - r_pre_error;
    rpwm = Kp*error + Ki*r_integral + Kd*derivative;
    r_pre_error = error;
}

void p_pid(short curr)
{
  //-------------p pid------------------
    short error = pspeed - curr;
    p_integral = p_integral + error;
    short derivative = error - p_pre_error;
    ppwm = Kp*error + Ki* p_integral + Kd * derivative;
    p_pre_error = error;
}

//-------------------------------------------------set speed api-------------------------------------
void set_thumb_speed(boolean dir, int s)
{
  tspeed = s;
  tdir = dir;
}

void set_thumb_end_speed(boolean dir, int s)
{
  tespeed = s;
  tedir = dir;
}

void set_index_speed(boolean dir, int s)
{
  ispeed = s;
  idir = dir;
}

void set_middle_speed(boolean dir, int s)
{
  mspeed = s;
  mdir = dir;
}

void set_ring_speed(boolean dir, int s)
{
  rspeed = s;
  rdir = dir;
}

void set_pinky_speed(boolean dir, int s)
{
  pspeed = s;
  pdir = dir;
}
