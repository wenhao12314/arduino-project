/*HACKATHON 4
 * 
 * Gruppe 3
 * Hanh Nhi, NGUYEN - 6106188
 * Douaa, BOUHAOUEL - 6105247
 * Wenhao, DOU - 6152590
 * 07/06/22
 * 
 * KOMMENTAR: 
 * Es gibt ein kleines Problem mit dem Positionwechseln der Kunden. Die Ausgabe ist komplett. Die Versbesserung Teil ist in Funktion pop1 und pop2.
 * 
 */

//
int button1=10; // Button 1 mit Karte bezahlen
int button2=11; // Button 2 mit Bargeld bezahlen

int led1=12; // Kasse 1 LED gelb
int led2=13; // Kasse 2 LED grün

int queue1[4]; //Kasse 1 maximal 4 Kunden
int queue2[4]; //Kasse 2 maximal 4 Kunden

int head; //Kopf
int tail; //Ende

bool queue1_empty = true;//Kasse 1 ist leer
bool queue1_full = false;//Kasse 1 ist voll
bool queue2_empty = true;//Kasse 2 ist leer
bool queue2_full = false;//Kasse 2 ist voll

int x=4; // Position von die neue Kunde
int buffer1[4]; // neuer Platz für neue Kunde für Kasse 1
int buffer2[4]; // neuer Platz für neue Kunde für Kasse 2
int j = 1; //Kundennummer
//
void setup() {
  
  pinMode(led1,OUTPUT); //Kasse 1 LED 
  pinMode(led2,OUTPUT); //Kasse 2 LED 
  pinMode(button1,INPUT_PULLUP); //Button 1 mit Karte bezahlen
  pinMode(button2,INPUT_PULLUP); //Button 2 mit Bargeld bezahlen
  Serial.begin(9600);
}

void loop() {
  
  //
  digitalWrite(led1,HIGH); // Anfang LED1 Kasse 1 HIGH
  digitalWrite(led2,LOW); 
  for(int a=0;a<=4;a++){
    
    push1(a); // Überprüfen ob Kasse 1 leer oder voll ist
    Serial.print("Die Wartezeit für Kasse 1 ist: ");
    Serial.print(a*10);
    Serial.println(" Sekunde. ");  
      
    bezahlen(); // Bezahlungsart auswählen
    
    Serial.print("Kundennummer: "); //Kundennummer ausgeben
    Serial.print(j);
    Serial.println();
    j++;
    Serial.print("Vorderen: "); //Position des Vorderen ausgeben
    Serial.print(head);
    Serial.println();
    Serial.print("Hinteren: "); //Position des Hinteren ausgeben
    if(head==0){
      Serial.print(0);
    } else{
    
    Serial.print(head - 1);
    }
  Serial.println();
  delay(2000);
  }
  
  for(int b=0;b<=4;b++){
    
    push2(b); // Überprüfen ob Kasse 2 leer oder voll ist
    Serial.print("Die Wartezeit für Kasse 2 ist: ");
    Serial.print(b*10);
    Serial.println(" Sekunde. ");
    
    bezahlen(); // Bezahlungsart auswählen
    
    Serial.print("Kundennummer: "); //Kundennummer ausgeben
    Serial.print(j);
    Serial.println();
    j++;
    Serial.print("Vorderen: "); //Position des Vorderen ausgeben
    Serial.print(head);
    Serial.println();
    Serial.print("Hinteren: "); //Position des Hinteren ausgeben
    if(head==0){
      Serial.print(0);
    } else{
    
    Serial.print(head - 1);
    }
    
    Serial.println();
    delay(2000);
  }
}
 
  //Bezahlen Funktion - nach Bezahlungsart fragen
  void bezahlen(){
  Serial.println("Wie wollen Sie bezahlen?  Linke Taste :mit Karte , rechte Taste: mit Bargeld , ");
    if((( digitalRead(10) == LOW)||( digitalRead(11) == LOW))&&(queue1_empty==true)) // Kunde bezahlen fertig, neue Kunden kommt - Kasse 1
         {
          push3(x);
         }
     
    else if(( digitalRead(10) == LOW)||( digitalRead(11) == LOW)&&(queue2_empty==true)) // Kunde bezahlen fertig, neue Kunden kommt - Kasse 2
         {
          push4(x);
                      
         }
    else if((queue1_empty==false)&&(queue2_empty==false)) // Beiden Kassen sind voll
         {
          Serial.print("Die beide Kassen sind voll, warten sie bitte bis die nächste Kasse frei ist." );
         }     
                                                
  delay(10000); //Jeder Kunden braucht 10s zu bazahlen
}


//speicher Funktion : neue Schlange machen um die Warteschlange ordentlich zu machen
void push3(int pos){
  
  int index=0;
   
      for(int i=0;i<3;i++)
      {
      buffer1[index]=queue1[i];
      index++;
      
    }
   buffer1[4]=pos;

}

void push4(int pos){
  
  int index=0;

      for(int i=0;i<3;i++)
      {
      buffer2[index]=queue2[i];
      index++;
      
    }
   buffer2[4]=pos;

}


// Überprüfen ob Kasse 1 leer oder voll ist

void push1(int val1){
  
  if(queue1_full == false){ //Kasse 1 hat noch freie Plätze
    queue1[head]=val1;
    Serial.print("Kasse 1 gibt schon: ");
    Serial.println(head);
    head++;
    
    if(head >= 4){
      head = 0;
    }
    queue1_empty = false;
    if(head == tail) {
      queue1_full = true; 
    }
  }else{
    Serial.println("Kasse 1 ist voll!"); // Kasse 1 leer
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
  }
}

//Verbesserung: Problem mit Positionwechseln der Kunden zu lösen - Kasse 1
int pop1(){ 
  if(queue1_empty == false){
    int val1 = queue1[tail];
    tail++;
    if(tail >= 4){
      tail = 0;
    }
    queue1_full = false;
    if(tail==head){
      queue1_empty = true;
    }
    return val1;
  }
  else{
    
  }
}


// Überprüfen ob Kasse 2 leer oder voll ist
void push2(int val2){
  if(queue2_full == false){ //Kasse 2 hat noch freie Plätze
    queue2[head]=val2;
    Serial.print("Kasse 2 gibt schon: ");
    Serial.println(head);
    head++;
    if(head >= 4){
      head = 0;
    }
    queue2_empty = false;
    if(head == tail) {
      queue2_full = true;
    }
  }else{
    Serial.println("Kasse 2 ist voll!"); //Kasse 2 voll
    digitalWrite(led2,LOW);
    Serial.println("Warten Sie bitte kürzen Moment.");
  }
}

// Verbesserung: Problem mit Positionwechseln der Kunden zu lösen - Kasse 2
int pop2(){
  if(queue2_empty == false){
    int val2 = queue2[tail];
    tail++;
    if(tail >= 4){
      tail = 0;
    }
    queue2_full = false;
    if(tail==head){
      queue2_empty = true;
    }
    return val2;
  }
  else{
    
  }
}
