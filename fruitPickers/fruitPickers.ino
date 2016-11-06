/* Kjell.com - Hur funkar Arduino?, Sida 65

Variabler

Programmet beräknar hur många äpplen två personer har plockat.
Alice & Bob.

Små äppelkorgar rymmer 25 äpplen, stora 40.

Bob har plockat 17 stora, och 17 små korgar.
Alice har plockat 20 stora, och 15 små korgar.
 */

//Deklaration och initiering av globala variabler:
//Totalt antal äpplen:
int fruitsAlice;
int fruitsBob;
 
//Antal äpplen per full korg:
int littleBasketSize = 25;
int bigBasketSize = 40;
 
//Antal korgar plockade per person
int littleBasketAlice = 20;
int bigBasketAlice = 15;
int bigBasketBob = 17;
int littleBasketBob = 17;
 
void setup(){
	//Öppna dataanslutning med 9600 bd
	Serial.begin(9600);
}

void loop(){
	//Räkna antal äpplen plockade per person, hade kunnat göras u setup-funktionen
	fruitsAlice = littleBasketSize * littleBasketAlice + bigBasketAlice * bigBasketSize;
	fruitsBob = littleBasketSize * littleBasketBob + bigBasketBob * bigBasketSize;
	
	//Skriv ut resultatet:
	Serial.print("Alice has picked: ");
	Serial.print(fruitsAlice);
	Serial.print(" apples!\n");
	Serial.print("Bob has picked: ");
	Serial.print(fruitsBob);
	Serial.print(" apples!\n");
	
	//Delay 500 ms
	delay(5000);
}
