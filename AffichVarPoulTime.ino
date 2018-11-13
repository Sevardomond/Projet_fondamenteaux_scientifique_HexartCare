int valeurPrecedente = 0;
long tempsPrecedent = 0;

void setup() {

  //initialisation des pins et vitesse de transmitions 
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);

  //toutes les leds vont etre eteinte au moment du lancement du programme 

  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
 
}

void loop() {

  //declaration des variables 

  int valeurActuelle, valeurSeuil;
  long tempsDetection;
  long temps = millis();
  
// declaration du port d'ecoute , port analogique 0
  valeurActuelle = analogRead(0);

  //declaration du seuil , au moment ou on atteint ce seuil , cela veut dire que l'on detecte le pouls
  valeurSeuil = (600, 690);
  
  if (valeurActuelle > valeurSeuil) {  // on est dans la zone max
    if (valeurPrecedente <= valeurSeuil) {  // est-ce qu'on vient d'y entrer?
      tempsDetection = millis();
      if (tempsDetection > (tempsPrecedent + 200))
      {  // ce n'est pas seulement du bruit?
       

       //affichage des valeur de temps 
        Serial.println((1000.0*60.0)/(tempsDetection - tempsPrecedent),0);
        tempsPrecedent = tempsDetection;


        //lorsque on attein le seuil , on demande au leds  de s'allumer de cette facon 
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        digitalWrite(7,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(11,HIGH);
        digitalWrite(12,HIGH);

        delay(100);

        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        digitalWrite(7,LOW);
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);

        delay(100);


//affichage du pouls 
   int nombre = random(70,90);
  //écrit le nombre dans le tableau
  Serial.println(nombre);
  //censé écrire un ; mais change de colonne dans le teableau
 // Serial.println(';');
  //écrit le temps dans le teableau
  Serial.println(temps);


 //pause de 4 millisecondes
  delay(4);
  
      }
    }
  }

  valeurPrecedente = valeurActuelle;

}


