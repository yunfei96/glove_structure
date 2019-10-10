void sensorTimer() 
{
  Serial.println("enter timer");
  //send queue from IRS
  BaseType_t xHigherPriorityTaskWoken_eq = pdFALSE;
  encoder encoder_data = {1,2,3,4,5,6};
  xQueueSendFromISR( encoder_Queue, &encoder_data, &xHigherPriorityTaskWoken_eq);
  //set up second queue
  BaseType_t xHigherPriorityTaskWoken_sq = pdFALSE;
  sensor sensor_data = {encoder_data, 1,2,3,4,5,1};
  xQueueSendFromISR( sensor_Queue, &sensor_data, &xHigherPriorityTaskWoken_sq);
}

void tt_enc_ISR()
{
  
}

void te_enc_ISR()
{
}

void i_enc_ISR()
{
}

void m_enc_ISR()
{
}

void r_enc_ISR()
{
}

void p_enc_ISR()
{
}
