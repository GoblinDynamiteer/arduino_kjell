/* Kjell.com - Hur funkar Arduino?, Sida 169 

Skriv ut grafik till OLED-display
Kittets medföljande display har upplösningen 128x64px
och är baserad på SSD1306-kontrollern

*/


#include <U8glib.h>
//https://github.com/olikraus/u8glib

//Skapar display-objekt
U8GLIB_SSD1306_128X64 display(U8G_I2C_OPT_NONE);

//Funktion för att rita ut grafik på displayen
void draw();

void setup(){
}

void loop(){
	display.firstPage(); //Start på bild-loop
	do{
		draw();
	//nexPage() returnerar 1 när bild är färdigskriven?
	}while(display.nextPage()); 
}

void draw(){
	//Rita ut enstaka pixlar på displayen
	display.drawPixel(11,44);
	display.drawPixel(13,44);
	
	//Rita ut linjer på displayen
	display.drawLine(12,28,12,60);
	display.drawLine(12,60,128,60);
	display.drawLine(12,60,128,30);
}