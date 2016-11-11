/* 
Kjell.com - Hur funkar Arduino?, Sida 140 

Dimmrar 4 LED av och på
Använder analogWrite (till skillnad mot digitalWrite) med pulsbreddsmodulering.
PWM - Pulse Width Modulation, spänning slås på av av snabbt. Genom att ändra
tiden då spänningen är tillslagen kan man simulera en analog signal.

analogWrite(x)
	x mellan 0-255 (0-100% av påslagen tid)

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
	//Dimmrar på LED-dioder (tar 255 ms)
	for(int i=0;i<leds;i++){
		//loopen börjar på 0 och räknar upp till 255
		for(int styrka=0;styrka<255;styrka++){
			analogWrite(ledPins[i], styrka);
			delay(1);
		}
	}
	//Dimmrar av LED-dioder (tar 255 ms)
	for(int i=0;i<leds;i++){
		//loopen börjar på 255 och räknar ned till 0
		for(int styrka=255;styrka!=0;styrka--){
			analogWrite(ledPins[i], styrka);
			delay(1);
		}
	}
}