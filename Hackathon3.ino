
/*HACKATHON 3
 * Gruppe 3
 * Hanh Nhi, NGUYEN - 6106188
 * Douaa, BOUHAOUEL - 6105247
 * Wenhao, DOU - 6152590
 * 24/05/22
 */


char block[3][3]={{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}}; // This one is only one extra Board for locating the Field
char Spielblock[3][3];  // ein Array mit 3 Reihen und 3 Spalten - The main Board
char first_step1='0',first_step2='0',first_step3='0',first_step4='0',first_step5='0'; // 1st Player 
char second_step1='0',second_step2='0',second_step3='0',second_step4='0'; // 2nd Player
int a,b;
int check;
                                
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(3000);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.println ("***TicTacToe***.");
}

void loop() {
  //Beginning
  if(Serial.available()){
    Serial.print("1: Spieler 1: Wähle ein Kätschen:"); 
    delay(3000);
    first_step1=Serial.read(); //Read the value from Monitor 
    Serial.println(first_step1);
    spielfeld(); // Function to fill the board - Player 1
    
    Serial.print("1: Spieler 2: Wähle ein Kätschen: :");
    delay(3000);
    second_step1=Serial.read();  
    Serial.println(second_step1);
    spielfeld2(); // Function to fill the board - Player 2
   

    Serial.print("2: Spieler 1: Wähle ein Kätschen:");
    delay(3000);
    first_step2=Serial.read();
    Serial.println(first_step2);
    spielfeld(); // Function to fill the board - Player 1
    
    Serial.print("2: Spieler 2: Wähle ein Kätschen:");
    delay(3000);
    second_step2=Serial.read();
    Serial.println(second_step2);
    spielfeld2(); // Function to fill the board - Player 2
    

    Serial.print("3: Spieler 1: Wähle ein Kätschen:");
    delay(3000);
    first_step3=Serial.read();
    Serial.println(first_step3);
    spielfeld(); // Function to fill the board - Player 1

    //ERGEBNIS
    check=checkwin();
    switch(check){
      case 1 :  // 1st Player wins - red LED ON
       Serial.println("1.win");
       digitalWrite(13,HIGH); 
       break;
      case 2 : //2nd Player wins - yellow LED ON
       Serial.println("2.win"); 
       digitalWrite(12,HIGH);
       break;
    }
    
    Serial.print("3: Spieler 2: Wähle ein Kätschen:");
    delay(3000);
    second_step3=Serial.read();
    Serial.println(second_step3);
    spielfeld();
    check=checkwin();
    switch(check){
      case 1 :
       Serial.println("1.win");
       digitalWrite(13,HIGH);
       break;
      case 2 :
       Serial.println("2.win");
       digitalWrite(12,HIGH);
       break;
    }
    
    Serial.print("4: Spieler 1: Wähle ein Kätschen:");
    delay(3000);
    first_step4=Serial.read();
    Serial.println(first_step4);
    spielfeld();
    check=checkwin();
    switch(check){
      case 1 :
       Serial.println("1.win");
       digitalWrite(13,HIGH);
       break;
      case 2 :
       Serial.println("2.win");
       digitalWrite(12,HIGH);
       break;
    } 
    
    Serial.print("4: Spieler 1: Wähle ein Kätschen:");
    delay(3000);
    second_step4=Serial.read();
    Serial.println(second_step4);
    spielfeld();


    //ERGEBNIS
    check=checkwin();
    switch(check){
      case 1 : // 1st Player wins - red LED ON
       Serial.println("1.win");
       digitalWrite(13,HIGH);
       break;
      case 2 : //2nd Player wins - yellow LED ON
       Serial.println("2.win");
       digitalWrite(12,HIGH);
       break;
    }
    
    Serial.print("5: Spieler 1: Wähle ein Kätschen:");
    delay(3000);
    first_step5=Serial.read();
    Serial.println(first_step5);
    spielfeld();
    check=checkwin();
    switch(check){
      case 1 :
       Serial.println("1.win");
       digitalWrite(13,HIGH);
       break;
      case 2 :
       Serial.println("2.win");
       digitalWrite(12,HIGH);
       break;
      default: //DRAW - Unentschieden
       Serial.println("Unentschieden"); 
    }
  }
  delay(5000);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
}

// Function to fill the board - Player 1
void spielfeld(){
  for(a=0;a<3;a++){
    for(b=0;b<3;b++){
      if(block[a][b]=='1' || block[a][b]=='2' || block[a][b]=='3' || block[a][b]=='4' || block[a][b]=='5' || block[a][b]=='6' || block[a][b]=='7' || block[a][b]=='8' || block[a][b]=='9'){
        if(block[a][b]==first_step1 ||block[a][b]==first_step2 || block[a][b]==first_step3 || block[a][b]==first_step4 || block[a][b]==first_step5){
          Spielblock[a][b]='X';
        }      else{
           Spielblock[a][b]=' ';
        }
        }
      }
    }
 Serial.print(Spielblock[0][0]);
 Serial.print("|");
 Serial.print(Spielblock[0][1]);
 Serial.print("|");
 Serial.println(Spielblock[0][2]);
 Serial.print(Spielblock[1][0]);
 Serial.print("|");
 Serial.print(Spielblock[1][1]);
 Serial.print("|");
 Serial.println(Spielblock[1][2]);
 Serial.print(Spielblock[2][0]);
 Serial.print("|");
 Serial.print(Spielblock[2][1]);
 Serial.print("|");
 Serial.println(Spielblock[2][2]);

} 


//Function to fill the board - Player 2
void spielfeld2(){
  for(a=0;a<3;a++){
    for(b=0;b<3;b++){
      if(block[a][b]=='1' || block[a][b]=='2' || block[a][b]=='3' || block[a][b]=='4' || block[a][b]=='5' || block[a][b]=='6' || block[a][b]=='7' || block[a][b]=='8' || block[a][b]=='9'){

        if(block[a][b]==second_step1 ||block[a][b]==second_step2 || block[a][b]==second_step3 || block[a][b]==second_step4){
          Spielblock[a][b]='O';
        }
        else{
           Spielblock[a][b]=' ';
        } 
      }
   }
  }
 Serial.print(Spielblock[0][0]);
 Serial.print("|");
 Serial.print(Spielblock[0][1]);
 Serial.print("|");
 Serial.println(Spielblock[0][2]);
 Serial.print(Spielblock[1][0]);
 Serial.print("|");
 Serial.print(Spielblock[1][1]);
 Serial.print("|");
 Serial.println(Spielblock[1][2]);
 Serial.print(Spielblock[2][0]);
 Serial.print("|");
 Serial.print(Spielblock[2][1]);
 Serial.print("|");
 Serial.println(Spielblock[2][2]);

} 

 
// Check which Player wins
int checkwin(){
  if(Spielblock[0][0]==Spielblock[0][1] && Spielblock[0][1]==Spielblock[0][2] && Spielblock[0][0]=="X"){
    return 1;
  }else
  if(Spielblock[1][0]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[1][2] && Spielblock[1][0]=="X"){
    return 1;
  }else
  if(Spielblock[2][0]==Spielblock[2][1] && Spielblock[2][1]==Spielblock[2][2] && Spielblock[2][0]=="X"){
    return 1;
  }else
  if(Spielblock[0][0]==Spielblock[1][0] && Spielblock[1][0]==Spielblock[2][0] && Spielblock[0][0]=="X"){
    return 1;
  }else
  if(Spielblock[0][1]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[2][1] && Spielblock[0][1]=="X"){
    return 1;
  }else
  if(Spielblock[0][2]==Spielblock[1][2] && Spielblock[1][2]==Spielblock[2][2] && Spielblock[0][2]=="X"){
    return 1;
  }else
  if(Spielblock[0][0]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[2][2] && Spielblock[0][0]=="X"){
    return 1;
  }else
  if(Spielblock[0][2]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[2][0] && Spielblock[0][2]=="X"){
    return 1;
  }else
  if(Spielblock[0][0]==Spielblock[0][1] && Spielblock[0][1]==Spielblock[0][2] && Spielblock[0][0]=="O"){
    return 2;
  }else
  if(Spielblock[1][0]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[1][2] && Spielblock[1][0]=="O"){
    return 2;
  }else
  if(Spielblock[2][0]==Spielblock[2][1] && Spielblock[2][1]==Spielblock[2][2] && Spielblock[2][0]=="O"){
    return 2;
  }else
  if(Spielblock[0][0]==Spielblock[1][0] && Spielblock[1][0]==Spielblock[2][0] && Spielblock[0][0]=="O"){
    return 2;
  }else
  if(Spielblock[0][1]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[2][1] && Spielblock[0][1]=="O"){
    return 2;
  }else
  if(Spielblock[0][2]==Spielblock[1][2] && Spielblock[1][2]==Spielblock[2][2] && Spielblock[0][2]=="O"){
    return 2;
  }else
  if(Spielblock[0][0]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[2][2] && Spielblock[0][0]=="O"){
    return 2;
  }else
  if(Spielblock[0][2]==Spielblock[1][1] && Spielblock[1][1]==Spielblock[2][0] && Spielblock[0][2]=="O"){
    return 2;
  }else{
    return 0;
  } 
}
