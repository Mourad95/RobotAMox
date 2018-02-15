#include <Servo.h>


//variable detecteur ultrason
const int ECHO = 12;  //definition de la pin echo de l'ultrason
const int TRIG = 11;     //definition de la pin trig de l'ultrason

int Distance = 0;
int val = 0;

//variable servomoteur
Servo myservo;  // création de l'objet myservo
const int S1 = 9;    // Pin sur lequel est branché le servo
int pos = 0;             // variable permettant de conserver la position du servo
int angle_initial = 0;   //angle initial
int angle_final = 179;   //angle final
int increment = 1;       //incrément entre chaque position
bool angle_actuel = false;//Envoi sur le port série la position courante du servomoteur

//methode de detection ultrason
int Distance_test()         // Measure the distance 
{
  digitalWrite(TRIG, LOW);   // set trig pin low 2μs
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);  // set trig pin 10μs , at last 10us 
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);    // set trig pin low
  float Fdistance = pulseIn(ECHO, HIGH);  // Read echo pin high level time(us)
  Fdistance= Fdistance/58;       //Y m=（X s*344）/2
  // X s=（ 2*Y m）/344 ==》X s=0.0058*Y m ==》cm = us /58       
  return (int)Fdistance;
} 

// initialisation des pins

void setup()
{//ultrason
  Serial.begin(115200);  
  pinMode(ECHO, INPUT);    // Define the ultrasonic echo input pin
  pinMode(TRIG, OUTPUT);   // Define the ultrasonic trigger input pin  
  pinMode(S1,OUTPUT);
  //servomoteur                     
  while(!Serial){;} 
  myservo.attach(S1);  // attache le servo au pin spécifié sur l'objet myservo
  
}

void loop()
{
  Distance = Distance_test();                 //display distance 
  if((2 < Distance) && (Distance < 400))      //Ultrasonic range ranging 2cm to 400cm
  {
    Serial.print("Distance = ");            //print distance
    Serial.print(Distance);       
    Serial.println("cm");       
  }
  else
  {
    Serial.println("!!! Out of range");      
  }
  delay(250);
  for (pos = angle_initial; pos <= angle_final; pos += increment) { // Déplace le servo de 0 à 180 degréespar pas de 1 degrée 
    myservo.write(pos);              // Demande au servo de se déplacer à cette position angulaire
    delay(20);                       // Attend 30ms entre chaque changement de position
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
  }
  for (pos = angle_final; pos >= angle_initial; pos -= increment) { // Fait le chemin inverse
    myservo.write(pos);              
    delay(20);   
    if (angle_actuel) {
        Serial.println(myservo.read());
    }
    
  }
  
  
  
  
}

