   //variable init
  int val = LOW;
  int old_val = LOW;
 
  int led_state = LOW;
  int i = 0;
  
  const int button = 12; 
  const int led = 13; //defining the led position to the 13th pin
  //starting setup routine
  void setup() {
  
  pinMode(button, INPUT);
 
  pinMode(led,OUTPUT);
  }
  
  // starting loop routine
  void loop()
  {
  //gathering buttons values
  val = digitalRead(button);
 
  
  if (val == HIGH && old_val == LOW)
    {
    if (led_state == HIGH)
      {
      for (i = 255; i > 0 ; i--)
        {
          analogWrite(led,i);
          delay(10);
        }
      }
    else if (led_state == LOW)
      {
        for (i = 0; i < 255; i++ )
        {
          analogWrite(led,i);
          delay(10);
        }
      }
   if (led_state == HIGH)
     {
      led_state = LOW;
     }
   else if (led_state == LOW)
     {
      led_state = HIGH;
     }
  }
  
  old_val = digitalRead(button);
  

  delay(30); // delay for stability
  }
