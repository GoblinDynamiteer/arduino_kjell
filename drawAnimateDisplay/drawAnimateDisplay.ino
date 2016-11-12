/* Kjell.com - Hur funkar Arduino?, Sida 176

Skriv ut animerad grafik till OLED-display
Kittets medföljande display har upplösningen 128x64px
och är baserad på SSD1306-kontrollern

*/


#include <U8glib.h>
//https://github.com/olikraus/u8glib

//Skapar display-objekt
U8GLIB_SSD1306_128X64 display(U8G_I2C_OPT_NONE);

//
int n = 0;
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
	
	if(n<30){
		n++;
	}
	else{
		delay(5000);
		n = 0;
	}
}

void draw(){
	//Rita ut enstaka pixlar på displayen
	display.drawPixel(11,44);
	display.drawPixel(13,44);
	
	//Sätter teckensnitt Helvetica 10
	//https://github.com/olikraus/u8glib/wiki/fontgroup
	display.setFont(u8g_font_helvB10);
	display.drawStr(0,10, "My Arduino");
	display.drawStr(0,23, "Knowledge");
	display.drawStr(0,60, "0");
	display.drawStr(0,40, "1");
	
	//Rita ut linjer på displayen
	//https://github.com/olikraus/u8glib/wiki/userreference
	//drawLine Description: Draw a line from (x1, y1) to (x2, y2).
	display.drawLine(12,28,12,60);
	display.drawLine(12,60,128,60);
	display.drawLine(12,60,12 + n * 4, 60-n);
}