#include <dht11.h> // librairie dht11

dht11 monDHT;// création de l'objet monDHT
const int DHT11_PIN = 4; //pin d'affectation 
int mesureHum ; //variable prise mesure humidité
int mesureTemp;//variable prise mesure température
int retourCapteur; //Retour des donnés du capteur
int tabMesures[60]; //taille tableau

void setup() {
    retourCapteur = monDHT.read(DHT11_PIN);
    mesureHum = monDHT.humidity,1;
    mesureTemp = monDHT.temperature,1;
    Serial.begin(9600);
    Serial.println("Humidity (%),\tTemperature C");
}

void loop() {

  //Serial.print(mesureHum);
  //Serial.print(",        \t");
  //Serial.println(mesureTemp);
  for (int i =1; i<=60; i++){
   tabMesures[0] = mesureHum;
   //tabMesures[1] = tabMesures[i++];
   Serial.println(tabMesures[0]);
  delay(1000);
  }
  
}
