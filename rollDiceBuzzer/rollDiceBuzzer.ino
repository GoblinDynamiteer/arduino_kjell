/* Kjell.com - Hur funkar Arduino?, Sida 158

Sl� en "t�rning" med en knapp
T�rningen �r en servomotor som s�tts till randomiserad
position 1-6

Buzzer ska ange vilket v�rde t�rningen angav
*/

#include <Button.h>
#include <Servo.h>

void upDown();
void setDice(int num, bool buzz);
const byte buzzerPin = 10;

//Button-objekt p� pin 13
Button knapp(13);

//Servo-motorobjekt
Servo servomotor;

void setup(){
	Serial.begin(9600);
	pinMode(buzzerPin, OUTPUT);
	//Starta knapp
	knapp.begin();
	//S�tter servomotor till pin 9
	servomotor.attach(9);
	//Seed f�r randomfunktionen
	randomSeed(analogRead(0));
	//Servo till position 0
	servomotor.write(0);
	//Flyttar servo till t�rningspositioner f�r kalibrering
	for(int i=1;i<7;i++){
		setDice(i, false);
		delay(1000);
	}
}

void loop(){
	//Rulla t�rning
	if(knapp.released()){
		upDown();
		//Sista argumentet avg�r om buzzer ska ge feedback
		setDice(random(1,7), 1);
		}
}

/* void upDown()
S�tter servo (t�rning) till position 6 -> 1
beh�vs f�r att indikera att nytt slag gjorts
annars kommer t�rningen stanna p� samma position om det blir
samma randomiserade v�rde tv� eller flera g�nger i rad */
void upDown(){
	setDice(6, 0);
	delay(600);
	setDice(1, 0);
	delay(600);
};

void setDice(int num, bool buzz){
	Serial.print("Slag: ");
	Serial.println(num);
	//Mappa t�rningsv�rden 1-6 med servopositioner
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
