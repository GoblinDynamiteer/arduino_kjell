/* Kjell.com - Hur funkar Arduino?, Sida 84

Randomisering, switch-sats

*/

void setup(){
	//Öppna dataanslutning med 9600 bd
	Serial.begin(9600);
}

void loop(){
	//randomiserar värde mellan 0-9
	//byte: variabel som är 1 byte stor (0-255)
	byte value = random(0,9);
	String pickedFruit;
	switch(value){
		case 0:
			pickedFruit = "banana";
			break;
		case 1:
			pickedFruit = "pineapple";
			break;
		case 2:
			pickedFruit = "clementine";
			break;
		case 3:
			pickedFruit = "pear";
			break;
		case 4:
			pickedFruit = "grape";
			break;
		default:
			pickedFruit = "mango";
			break;
	}
	Serial.print("Have a ");
	Serial.println(pickedFruit);
	//Delay 1000 ms
	delay(1000);
}
