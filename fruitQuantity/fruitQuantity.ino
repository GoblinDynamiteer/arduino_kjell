/* Kjell.com - Hur funkar Arduino?, Sida 79

if-villkor */

//Deklaration och initiering av globala variabler:
const int quantityApples = 1500;
const int quantityBananas = 300;

void setup(){
	//Öppna dataanslutning med 9600 bd
	Serial.begin(9600);
}

void loop(){
	//if-villkor som trigger beroende på hur många frukter som finns
	if(quantityApples>quantityBananas){
		Serial.println("We've got more apples than bananas!");
	}
	else if(quantityApples<quantityBananas){
		Serial.println("We've got more bananas than apples!");
	}
	else{
		Serial.println("We've got the same amount of apples and bananas!");
	}
	//Delay 1000 ms
	delay(1000);
}
