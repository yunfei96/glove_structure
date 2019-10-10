static void highlevel(void* arg) 
{
  while (1) 
  {
    if (Serial.available() > 0) 
    {
      //read the incoming byte:
      char in = Serial.read();
      if(in == 'g')
      {
        //do whatever
        Serial.print("I received: g");
      }
    }
  }
}
