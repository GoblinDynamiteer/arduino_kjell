/* 
Kjell.com - Hur funkar Arduino?, Sida 51

Styr en servomotor med en potentiometer.

*/

#include <Servo.h> //Finns som standard - Obs versal S

int servopos(int value);

//Skapar ett servo-object: servomotor
Servo servomotor;

//Pinnar f�r servostyrning och avl�sning av potentiometer
const byte potPin = A0; //Analog 0
const byte servoPin = 9;

//Position f�r servomotor
int pos;

void setup(){
	//Anslut servomotor till pin
	servomotor.attach(servoPin);
	//S�tt pin att l�sa data
	pinMode(potPin, INPUT);
}

void loop(){
	/* Mappa potentiometer-v�rde till servo-vinkel
	map(v, x_min, x_max, y_min, y_max)
		v=v�rde
		x_min - minsta v�rde f�r 'v'
		x_max - h�gsta v�rde f�r 'v'
		y_min - minsta v�rde f�r tilldelad mappning
		y_max - minsta v�rde f�r tilldelad mappning
		
		kommer omvandla 0 till 0, och 1023 till 180, och v�rden d�remellan
		och returnera till variabel pos.
	*/
	pos = map(analogRead(potPin), 0, 1023, 0, 180);
	//pos = servopos(analogRead(potPin));
	//Flytta servomotor till vinkel i pos
	servomotor.write(pos);
	delay(15);
}

/*Egen testfunktion f�r att omvanla pot-v�rde till servo-vinkel
F�r �vningens skull - mer kod!
Alternativ till map() 
Fungerar dock inte lika mjukt som map -- eventuellt felt�nkt
*/
int servopos(int value){
	//om 0
	if(!value){
		return 0;
		}
	float div = 1023 / value;
	return 180 / div;
}