#include <ArduinoRobot.h>


const int PWMA = 6;           //Left Motor Speed pin (ENA)
const char AIN2 = A0;          //Motor-L forward (IN2).
const char AIN1 = A1;          //Motor-L backward (IN1)
const int PWMB = 5;           //Right Motor Speed pin (ENB)
const char BIN1 = A2;          //Motor-R forward (IN3)
const char BIN2 = A3;          //Motor-R backward (IN4)
  
void setup() {
  // put your setup code here, to run once:
  pinMode(PWMA,OUTPUT);                     
  pinMode(AIN2,OUTPUT);      
  pinMode(AIN1,OUTPUT);
  pinMode(PWMB,OUTPUT);       
  pinMode(AIN1,OUTPUT);     
  pinMode(AIN2,OUTPUT);  
  
}

void loop() {
  analogWrite(PWMA,150);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  analogWrite(PWMB,150);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);
  
}

