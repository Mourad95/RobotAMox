//import de la librairie TimerOne
#include <TimerOne.h>

//variables pour les interrupeurs moteurs
const byte PinMoteur1 = 2; //interrupteur du moteur1 correspondant à la PIN 2 --> PIN-0 arduiono
const byte PinMoteur2 = 3; //interrupteur du moteur1 correspondant à la PIN 2 --> PIN-1 arduino

//variables pour le compteur d'implusion
unsigned int compteur1 = 0;
unsigned int compteur2 = 0;

//float pour le nombre de slots dans le disque du codeur
float  diskSlots = 20.00; //Nombre de trous dans le disque relié à la roue

//Interrupt Service Routines

//Motor 1 pulse count ISR
void ISR_compteur1()
{
  compteur1++; //incrementation des valeurs du compteur du moteur 1
}

void ISR_compteur2()
{
  compteur2++; //incrementation des valeurs du compteur du moteur 1
}


//TimerOne ISR
void ISR_timerone()
{
  Timer1.detachInterrupt(); // arrete le timer
  Serial.print("Vitesse du moteur 1: ");
  float rotation1 = (compteur1/diskSlots) * 60.00;// calcul du nombre de tour/min moteur1
  Serial.print(rotation1);
  Serial.print("tr/min: ");
  compteur1 = 0; //remise à zero du compteur1
  Serial.print("Vitesse du moteur 2: ");
  float rotation2 = (compteur2/diskSlots) * 60.00;// calcul du nombre de tour/min moteur1
  Serial.print(rotation2);
  Serial.print("tr/min: ");
  compteur2 = 0; //remise à zero du compteur2
  Timer1.attachInterrupt(ISR_timerone); // arrete le timer
}

void setup()
{
  Serial.begin(9600);
  Timer1.initialize(1000000);//reglage du timer à 1sec
  attachInterrupt(PinMoteur1, ISR_compteur1, RISING); //augmente le compteur1 lorsque le detecteur s'active
  attachInterrupt(PinMoteur2, ISR_compteur2, RISING); //augmente le compteur2 lorsque le detecteur s'active
  Timer1.attachInterrupt(ISR_timerone); //active le timer
  Serial.print("tr/min: ");
}
void loop()
{
  //aps necessaire
  
}

