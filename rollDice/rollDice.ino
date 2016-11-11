/* Kjell.com - Hur funkar Arduino?, Sida 154

Sl� en "t�rning" med en knapp
T�rningen �r en servomotor som s�tts till randomiserad
position 1-6


*/

#include <Button.h>
#include <Servo.h>

void upDown();

//Button-objekt p� pin 13
Button knapp(13);

//Servo-motorobjekt
Servo servomotor;

void setup(){
	//Starta knapp
	knapp.begin();
	//S�tter servomotor till pin 9
	servomotor.attach(9);
	//Seed f�r randomfunktionen
	randomSeed(analogRead(0));
	//Servo till position 0
	servomotor.write(0);
	//Flyttar servo till t�rningspositioner f�r kalibrering
	for(int i=0;i<7;i++){
		setDice(i);
		delay(1000);
	}
}

void loop(){
	//Rulla t�rning
	if(knapp.released()){
		upDown();
		setDice(random(1,7));
		}
}

/* void upDown()
S�tter servo (t�rning) till position 6 -> 1
beh�vs f�r att indikera att nytt slag gjorts
annars kommer t�rningen stanna p� samma position om det blir
samma randomiserade v�rde tv� eller flera g�nger i rad */
void upDown(){
	setDice(6);
	delay(600);
	setDice(1);
	delay(600);
};

void setDice(int num){
	//Mappa t�rningsv�rden 1-6 med servopositioner
	int servoPos = map(num, 1 ,6, 20, 140);
	servomotor.write(servoPos);
}
