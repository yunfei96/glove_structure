static void motor_control(void* arg) 
{
  while (1) 
  {
    struct encoder e={0,0,0,0,0,0};
    xQueueReceive(encoder_Queue, &e, portMAX_DELAY);
    Serial.println(e.p);
  }
}
