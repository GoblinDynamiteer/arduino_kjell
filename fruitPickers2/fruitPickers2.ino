/* Kjell.com - Hur funkar Arduino?, Sida 75

Variabler
Verion 2:
	- Ändrat till const int för korgstorlekar
	- Ändrat till unsigned int för lagring av totalt antal plockade äpplen.

Programmet beräknar hur många äpplen två personer har plockat.
Alice & Bob.

Små äppelkorgar rymmer 25 äpplen, stora 40.

Bob har plockat 17 stora, och 17 små korgar.
Alice har plockat 20 stora, och 15 små korgar.
 */

//Deklaration och initiering av globala variabler:

//Unsigned int kan hålla värden 0-65535
//Signed (standard) -32768-32767
//Totalt antal äpplen:
unsigned int fruitsAlice;
unsigned int fruitsBob;
 
//Antal äpplen per full korg:
//const-variabler lagras i Arduinons flash-minne (32kb för UNO)
//icke-const lagras i RAM (2kb för UNO)
const int littleBasketSize = 25;
const int bigBasketSize = 40;
 
//Antal korgar plockade per person
int littleBasketAlice = 20;
int bigBasketAlice = 15;
int bigBasketBob = 17;
int littleBasketBob = 17;

//charvariabel för tp av frukt
char fruit[] = " apples!";
//String fruit[] = " apples";

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
	Serial.println(fruit);
	Serial.print("Bob has picked: ");
	Serial.print(fruitsBob);
	Serial.println(fruit);
	
	//Delay 500 ms
	delay(5000);
}
