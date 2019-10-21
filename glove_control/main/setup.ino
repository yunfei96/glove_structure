void setup_motor_encoder()
{
  //thumb tip
  pinMode(thumbTip_pwmPin, OUTPUT);
  pinMode(thumbTip_dirPin, OUTPUT);
  pinMode(thumbTip_encA, INPUT_PULLUP);
  pinMode(thumbTip_encB, INPUT_PULLUP);

  //thumb end
  pinMode(thumbEnd_pwmPin, OUTPUT);
  pinMode(thumbEnd_dirPin, OUTPUT);
  pinMode(thumbEnd_encA, INPUT_PULLUP);
  pinMode(thumbEnd_encB, INPUT_PULLUP);

  //index
  pinMode(index_pwmPin, OUTPUT);
  pinMode(index_dirPin, OUTPUT);
  pinMode(index_encA, INPUT_PULLUP);
  pinMode(index_encB, INPUT_PULLUP);

  //middle
  pinMode(middle_pwmPin, OUTPUT);
  pinMode(middle_dirPin, OUTPUT);
  pinMode(middle_encA, INPUT_PULLUP);
  pinMode(middle_encB, INPUT_PULLUP);

  //ring
  pinMode(ring_pwmPin, OUTPUT);
  pinMode(ring_dirPin, OUTPUT);
  pinMode(ring_encA, INPUT_PULLUP);
  pinMode(ring_encB, INPUT_PULLUP);
  
  //pinky
  pinMode(pinky_pwmPin, OUTPUT);
  pinMode(pinky_dirPin, OUTPUT);
  pinMode(pinky_encA, INPUT_PULLUP);
  pinMode(pinky_encB, INPUT_PULLUP);
}

void setup_interrupt()
{
  //----------------------------encoder external interrupt---------------------------
  //thumb tip encoder
  attachInterrupt(thumbTip_encA, tt_enc_ISR, CHANGE);
  //thumb end encoder
  attachInterrupt(thumbEnd_encA, te_enc_ISR, CHANGE);
  //index encoder
  attachInterrupt(index_encA, i_enc_ISR, CHANGE);
  //middle encoder
  attachInterrupt(middle_encA, m_enc_ISR, CHANGE);
  //ring encoder
  attachInterrupt(ring_encA, r_enc_ISR, CHANGE);
  //ring encoder
  attachInterrupt(pinky_encA, p_enc_ISR, CHANGE);
  
  //-----------------------------set up timer interrupt------------------------------
   myTimer.begin(sensorTimer, 10000);
   
  //-----------------------------set up adc interrupt----------------------------
}

void setup_multi_threading()
{
   //create queue 
  sensor_Queue = xQueueCreate( 5, sizeof( struct sensor) );
  encoder_Queue = xQueueCreate( 5, sizeof( struct encoder) );
  portBASE_TYPE thread1, thread2, thread3;
  Serial.begin(9600);
  // create task at priority 1
  thread1 = xTaskCreate(motor_control, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  thread2 = xTaskCreate(deform, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  thread3 = xTaskCreate(highlevel, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);
  //check for creation errors
  if (thread1 != pdPASS || thread2 != pdPASS ||thread3 != pdPASS) 
  {
    Serial.println(F("Creation problem"));
    while(1);
  }
  // start scheduler
  vTaskStartScheduler();
  Serial.println("Insufficient RAM");
  while(1);
}
