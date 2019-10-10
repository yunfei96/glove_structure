static void highlevel(void* arg) 
{
  while (1) 
  {
    if (Serial.available() > 0) 
    {
      //read the incoming byte:
      char incomingByte = Serial.read();

      // say what you got:
      Serial.print("I received: ");
      Serial.println(incomingByte);
    }
  }
}
