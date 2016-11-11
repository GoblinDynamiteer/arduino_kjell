/* 
Kjell.com - Hur funkar Arduino?, Sida 51

Styr en servomotor med en potentiometer.

*/

#include <Servo.h> //Finns som standard - Obs versal S

int servopos(int value);

//Skapar ett servo-object: servomotor
Servo servomotor;

//Pinnar för servostyrning och avläsning av potentiometer
const byte potPin = A0; //Analog 0
const byte servoPin = 9;

//Position för servomotor
int pos;

void setup(){
	//Anslut servomotor till pin
	servomotor.attach(servoPin);
	//Sätt pin att läsa data
	pinMode(potPin, INPUT);
}

void loop(){
	/* Mappa potentiometer-värde till servo-vinkel
	map(v, x_min, x_max, y_min, y_max)
		v=värde
		x_min - minsta värde för 'v'
		x_max - högsta värde för 'v'
		y_min - minsta värde för tilldelad mappning
		y_max - minsta värde för tilldelad mappning
		
		kommer omvandla 0 till 0, och 1023 till 180, och värden däremellan
		och returnera till variabel pos.
	*/
	pos = map(analogRead(potPin), 0, 1023, 0, 180);
	//pos = servopos(analogRead(potPin));
	//Flytta servomotor till vinkel i pos
	servomotor.write(pos);
	delay(15);
}

/*Egen testfunktion för att omvanla pot-värde till servo-vinkel
För övningens skull - mer kod!
Alternativ till map() 
Fungerar dock inte lika mjukt som map -- eventuellt feltänkt
*/
int servopos(int value){
	//om 0
	if(!value){
		return 0;
		}
	float div = 1023 / value;
	return 180 / div;
}