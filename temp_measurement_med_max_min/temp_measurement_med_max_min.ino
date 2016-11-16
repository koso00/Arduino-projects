const int B = 3000;
const int Ro = 1000;
const int Tnom = 25;
const int Tcomp = 20; //temperatura di comparazione
int comp_c = 0;
int c = 0;
float max_val = 0;
float min_val = 300;
float med_val = 0;
float sum = 0;
float tmp = 0;
int nc = 12; //cambiare questo numero comporta un cambiamento nelle iterazioni
float temp_buff = 0;
float array[12];
int first_boot = false;
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
if (first_boot == false)
    {
    
Serial.println("88  dP  dP'Yb  .dP'Y8  dP'Yb   dP'Yb   dP'Yb");
Serial.println("88odP  dP   Yb `Ybo.  dP   Yb dP  /Yb dP  /Yb" );
Serial.println("88'Yb  Yb   dP o.`Y8b Yb   dP Yb / dP Yb / dP ");
Serial.println("88  Yb  YbodP  8bodP'  YbodP   YbodP   YbodP  ");

    first_boot = true;
    }
Serial.println("**********************************");
Serial.println("Loading");
    digitalWrite(led,HIGH);
    for (c= 0; c < nc ; c++)
      {
        //qualsiasi sia il suo nome, lo addressiamo in una variabile per evitare 
        //di ripetere troppo codice 
        temp_buff = misTemp(); 
        //assegnamento del valore massimo
        if (temp_buff > max_val) {max_val = temp_buff; }
        //assegnamento del valore minimo
        if (temp_buff < min_val) {min_val = temp_buff;}
        //somma per la media
        sum += temp_buff;
        array[c] = temp_buff;
Serial.println("...");
        delay(1000);
      }
      Serial.print("la temperatura piu' alta e' :");Serial.println(max_val);
      Serial.print("la temperatura piu' bassa e' :");Serial.println(min_val);
      Serial.print("la temperatura media e':"); Serial.println((sum/nc));
      Serial.println("lista temperature rilevate (le temperature superiori alla nominale avranno due asterischi a sinistra)");
for(c=0;c<nc;c++)
      {
      if (array[c] > Tcomp) {comp_c ++; Serial.print(" ** ");}
      Serial.print(array[c]);
      Serial.print(" ,");
      }
Serial.println("");
Serial.print("la temperatura nominale è stata superata "); Serial.print(comp_c) ; Serial.println(" volte");
Serial.println("**********************************");
digitalWrite(led,LOW);
      loop_flag = LOW;

  }

  if ((digitalRead(button)==HIGH) && (loop_flag == LOW))
    {
        max_val = 0;
        min_val = 300;
        med_val = 0;
        sum = 0;
        c = 0;
        comp_c = 0;
        temp_buff = 0;
        loop_flag = HIGH;
    }
  }

float misTemp()
{
tmp = analogRead(A0);
tmp = Ro/((1023/tmp)-1);
tmp = tmp/Ro;
tmp = log(tmp);
tmp = tmp/B;
tmp = tmp +1.0/(Tnom + 273.15);
tmp = 1.0/tmp;
tmp = tmp - 273.1;
}

