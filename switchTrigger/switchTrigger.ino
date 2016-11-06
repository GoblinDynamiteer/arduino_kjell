/* Kjell.com - Hur funkar Arduino?, Sida 62

Prylar:
1st knapp
kopplingsplatta
1st 1kOhm resistor
4st  kablar

Programmet skriver ut värdet för PIN2, 1 eller 0.
Utskriften kan visas i Serial Monitor.

1: Knapp nedtryckt
0: Knapp ej nedtryckt
 */

void setup(){
	//Använd pin 2 för input (bryts med knapp)
	pinMode(2, INPUT);
	//öppna dataanslutning med 9600 bd
	Serial.begin(9600);
}

void loop(){
	//print = Print Line, skriver ut, utan radbrytning
	//digitalRead(x) returnerar värdet för input 2 (1 eller 0)
	Serial.print(digitalRead(2));
	delay(500);
}
