//import de la librairie TimerOne
#include <TimerOne.h>

//variables pour les interrupeurs moteurs
const byte motor1 = 2; //interrupteur du moteur1 correspondant à la PIN 2 --> PIN-0 arduiono
const byte motor2 = 3; //interrupteur du moteur1 correspondant à la PIN 2 --> PIN-1 arduino

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
  float rotation1 = (compteur1/diskSlots) * 60.00;
  Serial.print(rotation1);
  Serial.print("tr/min: ");
  compteur1 = 0; //remise à zero du compteur1
}


