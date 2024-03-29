#include "interrupt.h"
void sensorTimer() 
{
  Serial.println("enter timer");
  //send queue from IRS
  BaseType_t xHigherPriorityTaskWoken_eq = pdFALSE;
  encoder encoder_data = {tt_enc,te_enc,i_enc,m_enc,r_enc,p_enc};
  tt_enc = 0; te_enc = 0; i_enc = 0; m_enc = 0; r_enc = 0; p_enc = 0;
  xQueueSendFromISR( encoder_Queue, &encoder_data, &xHigherPriorityTaskWoken_eq);
  //set up second queue
  BaseType_t xHigherPriorityTaskWoken_sq = pdFALSE;
  //read adc
  read_adc();
  sensor sensor_data = {encoder_data, tt_pot,i_pot,m_pot,r_pot,p_pot};
  xQueueSendFromISR( sensor_Queue, &sensor_data, &xHigherPriorityTaskWoken_sq);
}

//---------**WARNNING **
//blocking ADC read, will take 500us. Works fine for current application
void read_adc()
{
  
  tt_pot = analogRead(thumb_potPin);
  i_pot = analogRead(index_potPin);
  m_pot = analogRead(middle_potPin);
  r_pot = analogRead(ring_potPin);
  p_pot = analogRead(pinky_potPin);
  
}

void tt_enc_ISR()
{
  tt_enc++;
}

void te_enc_ISR()
{
  te_enc++;
}

void i_enc_ISR()
{
  i_enc++;
}

void m_enc_ISR()
{
  m_enc++;
}

void r_enc_ISR()
{
  r_enc++;
}

void p_enc_ISR()
{
  p_enc++;
}
