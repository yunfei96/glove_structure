static void highlevel(void* arg) 
{
  while (1) 
  {
    if (Serial.available() > 0) 
    {
      //read the incoming byte:
      char in = Serial.read();
      //-----------------if command is release------------
      if(in == 'r')
      {
        start_replase();
        Serial.print("Release");
      }
      //-----------------if command is grasp--------------
      if(in == 'g')
      {
        start_grasp();
        Serial.print("Grasp");
      }
    }
  }
}
