/* 
Kjell.com - Hur funkar Arduino?, Sida 144 

Dimmrar 4 RGB LED av och p�
Anv�nder analogWrite (till skillnad mot digitalWrite) med pulsbreddsmodulering.
PWM - Pulse Width Modulation, sp�nning sl�s p� av av snabbt. Genom att �ndra
tiden d� sp�nningen �r tillslagen kan man simulera en analog signal.

analogWrite(x)
	x mellan 0-255 (0-100% av p�slagen tid)

*/

//Array f�r pin-nummer
const byte leds = 3;
const byte ledPins[leds] = {9,10,11};

void setup(){
	for(int i=0;i<leds;i++){
		//S�tter pins i array att anv�ndas f�r output
		pinMode(ledPins[i], OUTPUT);
	}
}

void loop(){
	//Dimmra upp r�d
	for(int i=0;i<=255;i++){
		analogWrite(ledPins[0],i);
		delay(5);
	}
	//Dimmra ned r�d, upp gr�n
	for(int i=0;i<=255;i++){
		analogWrite(ledPins[0],255-i);
		analogWrite(ledPins[1],i);
		delay(5);
	}
	//Dimmra ned gr�n, upp bl�
	for(int i=0;i<=255;i++){
		analogWrite(ledPins[1],255-i);
		analogWrite(ledPins[2],i);
		delay(5);
	}
	//dimmra ned bl�
	int i = 255;
	while(i){
		analogWrite(ledPins[2],i--);
		delay(5);
	}
}