/* Kjell.com - Hur funkar Arduino?, Sida 190 

Sekundvisare med 24 led neopixel-ring
*/

#include <Adafruit_NeoPixel.h>

const byte neoPin = 10;
const byte neoPixels = 24;

/* Rekommenderad max styrka är 100 för breadboard-psu
Styrka kan ligga mellan 0-100
Max drar enskild LED 60mA
60*24 = 1440mA = 1,4A
PSUn har ~700mA max output (sant?)
*/
byte neoBright = 100;  

//LED-ring objekt
Adafruit_NeoPixel ledRing = Adafruit_NeoPixel(neoPixels, neoPin, NEO_GRB);


void setup(){
	ledRing.begin();
	ledRing.setBrightness(neoBright);
	ledRing.show();
}

void loop(){
	//Tänder LEDs
	for(int i=0; i<neoPixels;i++){
		ledRing.setPixelColor(i, ledRing.Color(0,118,189));
		ledRing.show();
		delay(42);
	}
	//Släcker LEDs
	for(int i=0; i<neoPixels;i++){
		ledRing.setPixelColor(i, ledRing.Color(0,0,0));
		ledRing.show();
		delay(42);
	}
}