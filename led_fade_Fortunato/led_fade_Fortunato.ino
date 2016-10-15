int val = LOW;
int old_val = LOW;
int i = 0;
int led_state = LOW;

const int led = 11;
const int button = 7;

void setup()
{
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  val = digitalRead(button);
  if (val == HIGH && old_val = LOW)
    {
       if (led_state == LOW)
       {
        for (i = 0; i < 255; i++)
            {
              analogWrite(led, i);
              delay(30);
            }
       }  
     else if (led_state == HIGH)
       {
        for (i = 255; i > 0; i--)
          {
            analogWrite(led, i);
            delay(30);
          }
        }
    if (led_state == LOW)
    {
      led_state = HIGH;  
    }
    if (led_state == HIGH)
   {
       led_state = LOW;
    }
  }
   val = digitalRead(button); 
}

