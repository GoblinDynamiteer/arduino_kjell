/* Kjell.com - Hur funkar Arduino?, Sida 158

Slå en "tärning" med en knapp
Tärningen är en servomotor som sätts till randomiserad
position 1-6

Buzzer ska ange vilket värde tärningen angav
*/

#include <Button.h>
#include <Servo.h>

void upDown();
void setDice(int num, bool buzz);
const byte buzzerPin = 10;

//Button-objekt på pin 13
Button knapp(13);

//Servo-motorobjekt
Servo servomotor;

void setup(){
	Serial.begin(9600);
	pinMode(buzzerPin, OUTPUT);
	//Starta knapp
	knapp.begin();
	//Sätter servomotor till pin 9
	servomotor.attach(9);
	//Seed för randomfunktionen
	randomSeed(analogRead(0));
	//Servo till position 0
	servomotor.write(0);
	//Flyttar servo till tärningspositioner för kalibrering
	for(int i=1;i<7;i++){
		setDice(i, false);
		delay(1000);
	}
}

void loop(){
	//Rulla tärning
	if(knapp.released()){
		upDown();
		//Sista argumentet avgör om buzzer ska ge feedback
		setDice(random(1,7), 1);
		}
}

/* void upDown()
Sätter servo (tärning) till position 6 -> 1
behövs för att indikera att nytt slag gjorts
annars kommer tärningen stanna på samma position om det blir
samma randomiserade värde två eller flera gånger i rad */
void upDown(){
	setDice(6, 0);
	delay(600);
	setDice(1, 0);
	delay(600);
};

void setDice(int num, bool buzz){
	Serial.print("Slag: ");
	Serial.println(num);
	//Mappa tärningsvärden 1-6 med servopositioner
	int servoPos = map(num, 1 ,6, 20, 140);
	servomotor.write(servoPos);
	if(buzz){
		delay(500);
		while(num){
			Serial.println("Buzzer ska trigga!");
			digitalWrite(buzzerPin, 1);
			delay(125);
			digitalWrite(buzzerPin, 0);
			delay(300);
			num--;
			}
	}
}
