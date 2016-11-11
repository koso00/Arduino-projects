
int c = 0;
float max_val = 0;
float min_val = 0;
float med_val = 0;
float sum = 0;
int nc = 12; //cambiare questo numero comporta un cambiamento nelle iterazioni
float temp_buff = 0;
/**********************************
  PARTE NON NELLA TRACCIA 
  **********************************/
 //inserzione di un pulsante per resettare
const int button = 12;
const int led = 13; //led di notifica che si sta misurando qualcosa
int loop_flag=HIGH;


void setup()
{
 Serial.begin(9600);
 pinMode(button,INPUT);
 pinMode(led,OUTPUT);
 }

void loop() 
{
 if(loop_flag==HIGH) 
  {
    digitalWrite(led,HIGH);
    for (c= 0; c < nc ; c++)
      {
        //qualsiasi sia il suo nome, lo addressiamo in una variabile per evitare 
        //di ripetere troppo codice 
        temp_buff = mis_temp(); 
        //assegnamento del valore massimo
        if (temp_buff > max_val) {max_val = temp_buff; }
        //assegnamento del valore minimo
        if (temp_buff < min_val) {min_val = temp_buff;}
        //somma per la media
        sum += temp_buff;
        delay(1000);
      }
      Serial.println("********************************");
      Serial.println("la temperatura più alta è :");Serial.print(max_val);
      Serial.println("la temperatura più bassa è :");Serial.print(min_val);
      Serial.println("la temperatura media é :"); Serial.print((sum/nc));
      Serial.println("********************************");
      digitalWrite(led,LOW);
      loop_flag = LOW;
  }

  if ((digitalRead(button)==HIGH) && (loop_flag == LOW))
    {
        max_val = 0;
        min_val = 0;
        med_val = 0;
        sum = 0;
        c = 0;
        temp_buff = 0;
        loop_flag = HIGH;
    }
  }

