/* 
Kjell.com - Hur funkar Arduino?, Sida 139 

*/

//Array för pin-nummer
const byte leds = 4;
const byte ledPins[leds] = {6,9,10,11};

void setup(){
	for(int i=0;i<leds;i++){
		//Sätter pins i array att användas för output
		pinMode(ledPins[i], OUTPUT);
	}
}

void loop(){
	//Tänd LED-dioder (skicka 1 från pins i array)
	for(int i=0;i<leds;i++){
		digitalWrite(ledPins[i], 1);
		delay(250);
	}
	//Släck LED-dioder (skicka 0 från pins i array)
	for(int i=0;i<leds;i++){
		digitalWrite(ledPins[i], 0);
		delay(250);
	}
}