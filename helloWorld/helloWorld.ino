/* Kjell.com - Hur funkar Arduino?, Sida 37 */

void setup(){
	//�ppna anslutning till datorn, 9600 bd - 1 baud �r 1bit/s
	Serial.begin(9600);
}

void loop(){
	//println = Print Line, skriver ut och avslutar med radbrytning
	Serial.println("Hellow Earth!");
	delay(1000);
}
