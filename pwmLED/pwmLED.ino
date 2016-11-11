/* 
Kjell.com - Hur funkar Arduino?, Sida 140 

Dimmrar 4 LED av och p�
Anv�nder analogWrite (till skillnad mot digitalWrite) med pulsbreddsmodulering.
PWM - Pulse Width Modulation, sp�nning sl�s p� av av snabbt. Genom att �ndra
tiden d� sp�nningen �r tillslagen kan man simulera en analog signal.

analogWrite(x)
	x mellan 0-255 (0-100% av p�slagen tid)

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
	//Dimmrar p� LED-dioder (tar 255 ms)
	for(int i=0;i<leds;i++){
		//loopen b�rjar p� 0 och r�knar upp till 255
		for(int styrka=0;styrka<255;styrka++){
			analogWrite(ledPins[i], styrka);
			delay(1);
		}
	}
	//Dimmrar av LED-dioder (tar 255 ms)
	for(int i=0;i<leds;i++){
		//loopen b�rjar p� 255 och r�knar ned till 0
		for(int styrka=255;styrka!=0;styrka--){
			analogWrite(ledPins[i], styrka);
			delay(1);
		}
	}
}