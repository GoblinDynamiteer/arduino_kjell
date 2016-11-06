/* Kjell.com - Hur funkar Arduino?, Sida 30 */

void setup(){
	//Sätter pin 13 som OUTPUT
	pinMode(13, OUTPUT);
}

void loop(){
	//Tänd LED, vänta 1000 ms
	digitalWrite(13, HIGH);
	delay(600);
	//Släck LED, vänta 1000 ms
	digitalWrite(13, LOW);
	delay(600);
}
