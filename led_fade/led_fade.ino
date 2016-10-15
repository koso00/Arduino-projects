   //variable init
  int val1 = LOW;
  int old_val1 = LOW;
  int val2 = LOW ;
  int old_val2 = LOW;
  int led_state = LOW;
  int i = 0;
  
  const int button1 = 2; //defining the button's pin position to the correct pin
  const int button2 = 3; //the same
  const int led = 13; //defining the led position to the 13th pin
  //starting setup routine
  void setup() {
  
  pinMode(button1, INPUT);
  pinMode(button2,INPUT);
  pinMode(led,OUTPUT);
  }
  
  // starting loop routine
  void loop()
  {
  //gathering buttons values
  val1 = digitalRead(button1);
  val2 = digitalRead(button2);
  
  if ((val1 == HIGH && old_val1 == LOW) || (val2 == HIGH && old_val2 == LOW))
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
  
  old_val1 = digitalRead(button1);
  old_val2 = digitalRead(button2);

  delay(30); // delay for stability
  }
