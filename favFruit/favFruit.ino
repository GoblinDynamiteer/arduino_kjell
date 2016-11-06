/* Kjell.com - Hur funkar Arduino?, Sida 82

if-villkor och/eller */

//Deklaration och initiering av globala variabler:
const boolean likeApples = true;
const boolean likeBananas = true;
const boolean likeRaisins = true;

void setup(){
	//Öppna dataanslutning med 9600 bd
	Serial.begin(9600);
}

void loop(){
	if(likeApples && !likeBananas){
		Serial.println("Have an apple!");
	}
	else if(!likeApples && likeBananas){
		Serial.println("Have a banana!");
	}
	else if(likeApples && likeBananas){
		//Kolla om man gillar russin! isåfall fruktsallad med russin, annars utan!
		if(likeRaisins){
			Serial.println("Have som fruit salad with raisins!");
		}
		else{
			Serial.println("Have som fruit salad without raisins!");
		}
	}
	else{
		Serial.println("You don't like fruits, right?!");
	}
	//Delay 1000 ms
	delay(1000);
}
