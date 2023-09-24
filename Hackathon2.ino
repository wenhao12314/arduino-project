/*Hackathon 2
 * 10.05.2022
 * Gruppe 22
 * Hanh Nhi, NGUYEN - 6106188
 * Douaa, BOUHAOUEL - 6105247
 * Wenhao, DOU - 6152590
 */


#include <Servo.h>
//Statt Papieranzeige benutzen wir ein Servo Motor
Servo myservo;

//Variablen definieren
double Zeit; //Die Leuchtzeit von LED
double Potis; // Die Werte von dem Potentiometer
int Grad; //Zeitspanne von 0 bis 30 Sec
int LED=11; 
int brightness=255; // max Helligkeit von LED
int Abnahme; // Fadeschritte von LED


void noaction(){
  
}

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  myservo.attach(9); // für Servo Motor
}

void loop() {
  
  digitalWrite(LED,LOW);
  Potis=analogRead(A0); //Potentiometer Werte auslesen
  
  Zeit=(Potis/1023)*30;
  Abnahme=255/Zeit;

  // Die Werte auf Serial Monitor zeigen, um Fehler zu erkennen
  Serial.println("Potis");
  Serial.println(Potis);
  delay(1);
  Serial.println("Zeit");
  Serial.println(Zeit);
  delay(1);

  // LED Ansteuerung
  for(int i=Zeit;i>=0;i--){
    Grad=i*6; //Jede Sekunde dreht der Servo Motor 180/30 = 6° 
    myservo.write(Grad);
    brightness=brightness-Abnahme; //Die Helligkeit zu variieren    
    analogWrite(LED,brightness); 
    delay(1000);
    
  }
  delay(1);
  
  digitalWrite(LED,LOW);
  delay(1000);
  

}
