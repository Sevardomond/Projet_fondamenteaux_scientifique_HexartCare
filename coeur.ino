#include "param.h"

String incomingByte = ""; 

//initialisation des LED's
void setup() {

  // Initialisation
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode (10,OUTPUT);
  randomSeed(analogRead(0));
  
  
  
}
//parametrage du mode d'allumage des LED's
// Boucle sans fin
void loop() {
  int mode = parametre();

  switch (mode)

  {


        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite (10, LOW);
        
    case 0: // Allumer une LED au choix
         choix();
         break;
        
    case 1: // Allumer toutes les LEDs
        allled();
        break;
        
    case 2:// Allumer les LEDs en mode chenille
        chenilleune();
        break;
        
    case 3:// Allumer 1 LED sur 2
        unesurdeux();
        break;
      
    case 4:// Allumer 1 LED sur 3
        unesurtrois();
        break;

        
    case 5:// Allumer 1 LED sur 9
        unesurneuf();
        break;


    case 6: // Mode Escargot
        escargot();
        break; 

     
    case 7: // Mode spirale
        spirale();
        break;

    case 8: // Mode barre de chargement
        chargement();
        break; 
 

   case 9: // Random
        hasard();
        break;

        
    default :// Erreur
      break;

  }
}
    


    void choix() {
        if (Serial.available()) 
       {
        
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite (10,LOW);
        incomingByte = Serial.readString();
        int valeur = incomingByte.toInt();
        Serial.println((String)valeur);       

          if (valeur > 1 && valeur <= 10) {
            digitalWrite(valeur, HIGH);
          }

          else if (valeur==1){
            digitalWrite(2, HIGH);
          }

          else {
            Serial.println("Mauvaise combinaison");
          }
       }
    }

 
    void allled() {
       /* int value = analogRead(0);
        if(value > 300){
    
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite (10, HIGH);
        }else{
    
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10,LOW);
        }*/

        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(9, HIGH);
        digitalWrite (10, HIGH);
        
      delay(1000);
    
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10,LOW);
      delay (1000);
    }

    void chenilleune (){
      
       
        digitalWrite(2, HIGH);
        delay(500);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(500);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(500);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(500);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(500);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        delay(500);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(500);
        digitalWrite(9, LOW);
         digitalWrite(10, HIGH);
        delay(500);
         digitalWrite(10, LOW);
      
      
        
        
        
        }

    void unesurdeux() {    
    
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        delay(100);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        
      
    }

    void unesurtrois() {
      
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10,LOW);
        delay(500);
        
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10,HIGH);

        
    }

 



    void unesurneuf() {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10,LOW);
        delay (100);
         digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10,LOW);
    }

 
    void escargot() { 
      
        digitalWrite(2, HIGH); 
        delay(100);
        digitalWrite(3, HIGH); 
        delay(100);
        digitalWrite(4, HIGH); 
        delay(100);
        digitalWrite(5, HIGH); 
        delay(100);
        digitalWrite(6, HIGH); 
        delay(100);
        digitalWrite(7, HIGH); 
        delay(100);
        digitalWrite(8, HIGH); 
        delay(100);
        digitalWrite(9, HIGH); 
        delay(100);
        digitalWrite(10, HIGH); 
        delay(100);
     
        
        digitalWrite(9, LOW);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(7, LOW);
        delay(100);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(5, LOW);
        delay(100);
        digitalWrite(4, LOW);
        delay(100);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(2, LOW);
        delay(100);
        digitalWrite(10, LOW); 
        delay(100);
      
     }

   

     void spirale() {
       
        digitalWrite(7, HIGH);
        digitalWrite(2, HIGH);
        delay(100);
        digitalWrite(8, HIGH);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(9, HIGH);
        digitalWrite(4, HIGH);
        delay(100);
        digitalWrite (10,HIGH);
        digitalWrite(6, HIGH);
        delay(100);

        
     
        digitalWrite (10,LOW);
        digitalWrite(6, LOW);
        delay(100);
        digitalWrite(9, LOW);
        digitalWrite(4, LOW);
        delay(100);
        digitalWrite(8, LOW);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(7, LOW);
        digitalWrite(2, LOW);
        delay(100);
     
    }

    void chargement() {
    
        digitalWrite(2, HIGH); 
        delay(100);
        digitalWrite(3, HIGH); 
        delay(100);
        digitalWrite(4, HIGH); 
        delay(00);
        digitalWrite(5, HIGH); 
        delay(100);
        digitalWrite(6, HIGH); 
        delay(100);
        digitalWrite(7, HIGH); 
        delay(100);
        digitalWrite(8, HIGH); 
        delay(100);
        digitalWrite(9, HIGH); 
        delay(100);
        digitalWrite(10, HIGH); 
        delay(100);
   
   
        
   
        digitalWrite(9, LOW);
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        digitalWrite(2, LOW);
        digitalWrite(10, LOW); 
   
   
       
    }

   
    void hasard() {
        int randNumber;
        randNumber = random(2,10);
        digitalWrite(randNumber, HIGH);
        delay(100);
        digitalWrite(randNumber, LOW);
   }
