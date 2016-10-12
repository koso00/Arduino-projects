//variable init
int val1 = LOW;
int old_val1 = LOW;
int val2 = LOW ;
int old_val2 = LOW;
int led_state = LOW;

const int button1 = 2;   //defining the button's pin position to the correct pin
const int button2 = 3; //the same
const int led = 13; //defining the led position to the 13th pin
//starting setup routine
void setup() {
  // initialize serial communication at 9600 bits per second:
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

  if (val1 == HIGH && old_val1 == LOW)
  {
    if (led_state == HIGH){led_state = LOW;}
    else{led_state = HIGH;}
  }

  /*this second block can be avoided but i had no explanation 
   on how to properly use the "or" expression on arduino*/
   
  if (val2 == HIGH && old_val2 == LOW)
  {
    if (led_state == HIGH){led_state = LOW;}
    else{led_state = HIGH;}
  }
  digitalWrite(led,led_state); //this write the led_state on the led

old_val1 = digitalRead(button1)
old_val2 = digitalRead(button2)

  delay(30);        // delay for stability 
}

