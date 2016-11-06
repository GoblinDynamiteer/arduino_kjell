/* Kjell.com - Hur funkar Arduino?, Sida 75

Variabler
Verion 2:
	- Ändrat till const int för korgstorlekar
	- Ändrat till unsigned int för lagring av totalt antal plockade äpplen.

Verion 3:
	- Fysiska knappar används för att lägga till antal plockade korgar
	- Inkludering av bibliotek "Button.h"
	
Prylar:
4st knappar
kopplingsplatta
4st  kablar
	
Programmet beräknar hur många äpplen två personer har plockat.
Alice & Bob.

Små äppelkorgar rymmer 25 äpplen, stora 40.

Bob har plockat 17 stora, och 17 små korgar.
Alice har plockat 20 stora, och 15 små korgar.
 */

#include <Button.h>
 
//Knappar (objects) för att öka antal plockade korgar
//Siffran anger I/O-stift
Button btnAddLittleBasketAlice(5);
Button btnAddLittleBasketBob(4);
Button btnAddBigBasketAlice(3);
Button btnAddBigBasketBob(2);
 
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
 
//Antal korgar plockade per person -- behövs ej längre
/* int littleBasketAlice = 20;
int bigBasketAlice = 15;
int bigBasketBob = 17;
int littleBasketBob = 17; */

//charvariabel för tp av frukt
char fruit[] = " apples!";
//String fruit[] = " apples";

void setup(){
	//Öppna dataanslutning med 9600 bd
	Serial.begin(9600);
	
	//Startar knappar
	btnAddLittleBasketAlice.begin();
	btnAddLittleBasketBob.begin();
	btnAddBigBasketAlice.begin();
	btnAddBigBasketBob.begin();
	
}

void loop(){
	//Lägg till littleBasketAlice
	if(btnAddLittleBasketAlice.pressed()){
		fruitsAlice += littleBasketSize;
		Serial.print("Alice has picked: ");
		Serial.print(fruitsAlice);
		Serial.println(fruit);
		Serial.print("Bob has picked: ");
		Serial.print(fruitsBob);
		Serial.println(fruit);
		Serial.println("-----------------------");
	}
		//Lägg till littleBasketBob
	if(btnAddLittleBasketBob.pressed()){
		fruitsBob += littleBasketSize;
		Serial.print("Alice has picked: ");
		Serial.print(fruitsAlice);
		Serial.println(fruit);
		Serial.print("Bob has picked: ");
		Serial.print(fruitsBob);
		Serial.println(fruit);
		Serial.println("-----------------------");
	}
		//Lägg till bigBasketAlice
	if(btnAddBigBasketAlice.pressed()){
		fruitsAlice += bigBasketSize;
		Serial.print("Alice has picked: ");
		Serial.print(fruitsAlice);
		Serial.println(fruit);
		Serial.print("Bob has picked: ");
		Serial.print(fruitsBob);
		Serial.println(fruit);
		Serial.println("-----------------------");
	}
		//Lägg till bigBasketBob
	if(btnAddBigBasketBob.pressed()){
		fruitsBob += bigBasketSize;
		Serial.print("Alice has picked: ");
		Serial.print(fruitsAlice);
		Serial.println(fruit);
		Serial.print("Bob has picked: ");
		Serial.print(fruitsBob);
		Serial.println(fruit);
		Serial.println("-----------------------");
	}
}
