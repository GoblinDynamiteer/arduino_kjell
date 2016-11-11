/* 
Kjell.com - Hur funkar Arduino?, Sida 144 

Dimmrar 4 RGB LED av och på
Använder analogWrite (till skillnad mot digitalWrite) med pulsbreddsmodulering.
PWM - Pulse Width Modulation, spänning slås på av av snabbt. Genom att ändra
tiden då spänningen är tillslagen kan man simulera en analog signal.

analogWrite(x)
	x mellan 0-255 (0-100% av påslagen tid)

*/

//Array för pin-nummer
const byte leds = 3;
const byte ledPins[leds] = {9,10,11};

void setup(){
	for(int i=0;i<leds;i++){
		//Sätter pins i array att användas för output
		pinMode(ledPins[i], OUTPUT);
	}
}

void loop(){
	//Dimmra upp röd
	for(int i=0;i<=255;i++){
		analogWrite(ledPins[0],i);
		delay(5);
	}
	//Dimmra ned röd, upp grön
	for(int i=0;i<=255;i++){
		analogWrite(ledPins[0],255-i);
		analogWrite(ledPins[1],i);
		delay(5);
	}
	//Dimmra ned grön, upp blå
	for(int i=0;i<=255;i++){
		analogWrite(ledPins[1],255-i);
		analogWrite(ledPins[2],i);
		delay(5);
	}
	//dimmra ned blå
	int i = 255;
	while(i){
		analogWrite(ledPins[2],i--);
		delay(5);
	}
}