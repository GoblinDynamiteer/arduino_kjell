/* Kjell.com - Hur funkar Arduino?, Sida 154

Slå en "tärning" med en knapp
Tärningen är en servomotor som sätts till randomiserad
position 1-6


*/

#include <Button.h>
#include <Servo.h>

void upDown();

//Button-objekt på pin 13
Button knapp(13);

//Servo-motorobjekt
Servo servomotor;

void setup(){
	//Starta knapp
	knapp.begin();
	//Sätter servomotor till pin 9
	servomotor.attach(9);
	//Seed för randomfunktionen
	randomSeed(analogRead(0));
	//Servo till position 0
	servomotor.write(0);
	//Flyttar servo till tärningspositioner för kalibrering
	for(int i=0;i<7;i++){
		setDice(i);
		delay(1000);
	}
}

void loop(){
	//Rulla tärning
	if(knapp.released()){
		upDown();
		setDice(random(1,7));
		}
}

/* void upDown()
Sätter servo (tärning) till position 6 -> 1
behövs för att indikera att nytt slag gjorts
annars kommer tärningen stanna på samma position om det blir
samma randomiserade värde två eller flera gånger i rad */
void upDown(){
	setDice(6);
	delay(600);
	setDice(1);
	delay(600);
};

void setDice(int num){
	//Mappa tärningsvärden 1-6 med servopositioner
	int servoPos = map(num, 1 ,6, 20, 140);
	servomotor.write(servoPos);
}
