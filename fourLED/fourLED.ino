/* 
Kjell.com - Hur funkar Arduino?, Sida 139 

*/

//Array f�r pin-nummer
const byte leds = 4;
const byte ledPins[leds] = {6,9,10,11};

void setup(){
	for(int i=0;i<leds;i++){
		//S�tter pins i array att anv�ndas f�r output
		pinMode(ledPins[i], OUTPUT);
	}
}

void loop(){
	//T�nd LED-dioder (skicka 1 fr�n pins i array)
	for(int i=0;i<leds;i++){
		digitalWrite(ledPins[i], 1);
		delay(250);
	}
	//Sl�ck LED-dioder (skicka 0 fr�n pins i array)
	for(int i=0;i<leds;i++){
		digitalWrite(ledPins[i], 0);
		delay(250);
	}
}