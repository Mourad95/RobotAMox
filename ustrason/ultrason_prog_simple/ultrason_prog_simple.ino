#define ECHO   2  //definition de la pin echo de l'ultrason
#define TRIG   3 

long duration;
int distance;



void setup()
{
  pinMode (TRIG,OUTPUT);
  pinMode (ECHO, INPUT);
  Serial.begin(9600);
    
}

void loop()
{
 digitalWrite(TRIG,LOW);
 delayMicroseconds(2);
 digitalWrite(ECHO,HIGH);
 delayMicroseconds(10);
 
 digitalWrite(TRIG,LOW);
 
 duration = pulseIn(ECHO,HIGH);
 distance = duration * 0.034/2;
 
 Serial.print("Distance est de : ");
 Serial.println(distance);
 
}

