
#include <Servo.h>
 
Servo myservo;  // création de l'objet myservo 
 
const int S1 = 9;    // Pin sur lequel est branché le servo
int pos = 0;             // variable permettant de conserver la position du servo

bool angle_actuel = true;//Envoi sur le port série la position courante du servomoteur
 
void setup() {
  pinMode(S1,OUTPUT);
  Serial.begin(9600);                       
  while(!Serial){;} 
  myservo.attach(S1);  // attache le servo au pin spécifié sur l'objet myservo
  
}
 
void loop() {
  
  for (pos = 0; pos <= 179; pos = pos + 1) { // Déplace le servo de 0 à 180 degréespar pas de 1 degrée 
    myservo.write(pos);              // Demande au servo de se déplacer à cette position angulaire
    delay(10);                       // Attend 30ms entre chaque changement de position
    
  }
  if (angle_actuel) {
        Serial.println(myservo.read());
    }
  for (pos = 179; pos >= 0; pos = pos - 1) { // Fait le chemin inverse
    myservo.write(pos);              
    delay(10);   
    
  }
   if (angle_actuel) {
        Serial.println(myservo.read());
    }
    
     for (pos = 0; pos <= 90; pos = pos + 1) { // Fait le chemin inverse
    myservo.write(pos);              
    delay(10);   
  }
  
  delay(3000);
  
   if (angle_actuel) {
        Serial.println(myservo.read());
    } 
         for (pos = 90; pos >= 0; pos = pos - 1) { // Fait le chemin inverse
    myservo.write(pos);              
    delay(10);   
  }
    
  
}
