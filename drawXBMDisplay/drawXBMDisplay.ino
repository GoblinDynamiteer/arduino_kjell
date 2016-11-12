/* Kjell.com - Hur funkar Arduino?, Sida 178

Skriv ut exporterad x-bitmap till OLED-display
Kittets medföljande display har upplösningen 128x64px
och är baserad på SSD1306-kontrollern

*/


#include <U8glib.h>
//https://github.com/olikraus/u8glib

//Skapar display-objekt
U8GLIB_SSD1306_128X64 display(U8G_I2C_OPT_NONE);

const byte img_width = 128;
const byte img_height = 64;

//Exporterad xbm
static unsigned char img_bits[] U8G_PROGMEM = {
   0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0xc0, 0xff,
   0xff, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0x0f, 0xf8,
   0xff, 0x1f, 0x00, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xf1, 0xff,
   0xff, 0xff, 0x81, 0xff, 0xff, 0x1f, 0x00, 0xfc, 0xff, 0xff, 0xf8, 0xff,
   0xff, 0xff, 0xf1, 0xff, 0xff, 0x7f, 0xe0, 0xff, 0xff, 0x1f, 0x00, 0xf0,
   0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0x1f, 0xf8, 0xff,
   0xff, 0x3f, 0x00, 0xc0, 0xff, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf1, 0xff,
   0xff, 0x0f, 0xfe, 0xff, 0xff, 0x3f, 0x0c, 0x80, 0xff, 0xff, 0xf8, 0xff,
   0xff, 0xff, 0xf1, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0x3f, 0xfe, 0x00,
   0xfe, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf1, 0xff, 0x7f, 0xc0, 0xff, 0xff,
   0xff, 0x3f, 0xfe, 0x03, 0xf8, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xf8, 0xff,
   0x0f, 0xf0, 0xff, 0xff, 0xff, 0x3f, 0xfe, 0x0f, 0xe0, 0xff, 0xf8, 0xff,
   0xff, 0xff, 0xf8, 0x7f, 0x00, 0xf0, 0xff, 0xff, 0xff, 0x3f, 0xfe, 0x3f,
   0x80, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xc0, 0xf0, 0xff, 0xff,
   0xff, 0x1f, 0xfe, 0x7f, 0x00, 0x7e, 0xc0, 0xff, 0xff, 0xff, 0x18, 0x00,
   0xf0, 0xf1, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0x7f, 0x00, 0x08, 0x00, 0xff,
   0xff, 0xff, 0x00, 0x00, 0xf0, 0xf3, 0xff, 0xff, 0xff, 0x1f, 0xfe, 0xff,
   0x00, 0x80, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x7e, 0xf8, 0xe3, 0xff, 0xff,
   0xff, 0x1f, 0xff, 0xff, 0x00, 0xf0, 0x1f, 0xfe, 0xff, 0x1f, 0xc0, 0x7f,
   0xf8, 0xe3, 0xff, 0xff, 0xff, 0x1f, 0xff, 0xff, 0x00, 0xf8, 0x3f, 0xfe,
   0xff, 0x0f, 0xfc, 0x7f, 0xf8, 0xe7, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff,
   0x00, 0x3c, 0x70, 0xfc, 0xff, 0x03, 0xff, 0xff, 0xf8, 0xc7, 0xff, 0xff,
   0xff, 0xc1, 0xff, 0xff, 0x00, 0x1c, 0x60, 0xfc, 0xff, 0xc1, 0xff, 0xff,
   0xf8, 0xcf, 0xff, 0xff, 0x3f, 0xf0, 0xff, 0xff, 0x00, 0x9c, 0x63, 0xfc,
   0xff, 0xf0, 0xff, 0x7f, 0xfc, 0x8f, 0xff, 0xff, 0x0f, 0xfc, 0xff, 0xff,
   0x00, 0xce, 0x47, 0xfc, 0x7f, 0xf8, 0xff, 0x3f, 0xfe, 0x1f, 0xff, 0xff,
   0x80, 0xff, 0xff, 0xff, 0x00, 0xee, 0x8f, 0xf8, 0x7f, 0xfc, 0xff, 0x1f,
   0xfe, 0x1f, 0xff, 0x0f, 0xe0, 0xff, 0xff, 0xff, 0x00, 0xee, 0x8f, 0xf8,
   0x7f, 0xfc, 0xff, 0x8f, 0xff, 0x3f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff,
   0x00, 0xee, 0x8f, 0xf8, 0x7f, 0xfc, 0xff, 0x87, 0xff, 0x3f, 0x00, 0xc0,
   0xff, 0xff, 0xff, 0xff, 0x00, 0xe7, 0x9f, 0xf8, 0x7f, 0xfc, 0xff, 0xe3,
   0xff, 0xff, 0x00, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x00, 0xe7, 0x9f, 0xf8,
   0xff, 0xfc, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x00, 0xc7, 0x9f, 0xf8, 0xff, 0xfc, 0xff, 0xf8, 0xff, 0xff, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x00, 0xc7, 0x9f, 0xf8, 0xff, 0xf8, 0x7f, 0xfc,
   0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x87, 0xdf, 0xf8,
   0xff, 0xf9, 0x3f, 0xfe, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x01, 0x83, 0xff, 0xf8, 0xff, 0xf9, 0x1f, 0xff, 0xff, 0xf3, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0x83, 0xff, 0xf8, 0xff, 0xf3, 0x1f, 0xff,
   0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0x83, 0xff, 0xf8,
   0xff, 0xf3, 0x8f, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x01, 0xc2, 0xff, 0xf8, 0xff, 0x03, 0x80, 0xff, 0xff, 0x1f, 0xff, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0xc2, 0x7f, 0xf8, 0xff, 0x07, 0x80, 0xff,
   0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xe2, 0xff, 0xf8,
   0xff, 0x0f, 0x80, 0xff, 0xff, 0x7f, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x01, 0xe0, 0x7f, 0xfc, 0xff, 0xff, 0x83, 0xff, 0xff, 0xff, 0xfc, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0xf0, 0x7f, 0xfc, 0xff, 0xff, 0x83, 0xff,
   0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xf0, 0x7f, 0xfc,
   0xff, 0xff, 0x87, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x01, 0xf8, 0x3f, 0xfe, 0xff, 0xff, 0x07, 0xff, 0x07, 0xff, 0xe3, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0x3f, 0xfe, 0xff, 0xff, 0x0f, 0xfe,
   0x03, 0xfc, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0x1f, 0xfe,
   0xff, 0xff, 0x07, 0xfc, 0x03, 0xf0, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x01, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0x07, 0xf8, 0xff, 0xc7, 0xe3, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0x8f, 0xff, 0xff, 0xff, 0x87, 0xf1,
   0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 0xfe, 0x87, 0xff,
   0xff, 0xff, 0xc7, 0xe3, 0xff, 0xff, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff,
   0x00, 0xfe, 0xc7, 0xff, 0xff, 0xff, 0xc7, 0x07, 0x00, 0x00, 0xf8, 0xff,
   0xff, 0xff, 0xff, 0xff, 0x00, 0xfe, 0xe3, 0xff, 0xff, 0xff, 0xc7, 0x0f,
   0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x00, 0xfe, 0xe1, 0xff,
   0xff, 0xff, 0xc7, 0x7f, 0x00, 0x00, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x3f,
   0x00, 0xfc, 0xf1, 0xff, 0xff, 0xff, 0xc7, 0x1f, 0x00, 0x00, 0x80, 0xff,
   0xff, 0xff, 0xff, 0x3f, 0x00, 0x70, 0xf0, 0xff, 0xff, 0xff, 0xc7, 0x03,
   0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0x1f, 0x00, 0x00, 0xf8, 0xff,
   0xff, 0xff, 0xc7, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0xff, 0x0f,
   0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0x47, 0x00, 0x00, 0x00, 0x00, 0xe0,
   0xff, 0xff, 0xff, 0x07, 0x00, 0x04, 0xff, 0xff, 0xff, 0xff, 0x07, 0x00,
   0x00, 0x00, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x07, 0x00, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0x07, 0x00, 0xf0, 0x01, 0x00, 0x80, 0xff, 0xff, 0xff, 0x03,
   0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x07, 0xc0, 0xff, 0x1f, 0x00, 0x00,
   0xff, 0xff, 0xff, 0x01, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf0,
   0xff, 0xff, 0x03, 0x00, 0xfe, 0xff, 0xff, 0x00, 0x00, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0x03, 0xfc, 0x1f, 0xc0, 0x0f, 0x00, 0xfe, 0xff, 0x7f, 0x00,
   0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0x7c, 0x00, 0x00, 0x3c, 0x00,
   0xfc, 0xff, 0x3f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0x0c,
   0xf8, 0x3f, 0x70, 0x00, 0xf8, 0xff, 0x1f, 0x00, 0x00, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0x03, 0xc0, 0xff, 0xff, 0x47, 0x00, 0xf8, 0xff, 0x0f, 0x00,
   0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf0, 0xff, 0xff, 0x1f, 0x01,
   0xf8, 0xff, 0x03, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x03, 0xf8,
   0xff, 0xff, 0x7f, 0x01, 0xf0, 0xff, 0x01, 0x00, 0x00, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0x07, 0xfc, 0x07, 0xff, 0xff, 0x03, 0xf0, 0x7f, 0x00, 0x00,
   0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x07, 0xfc, 0x07, 0xfe, 0xff, 0x03,
   0xe0, 0x3f, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf8,
   0x07, 0xfe, 0xff, 0x07, 0xe0, 0x0f, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff,
   0xff, 0xff, 0x07, 0xf8, 0x07, 0xfe, 0xff, 0x07, 0xe0, 0x03, 0x00, 0x00,
   0x00, 0xfe, 0xff, 0xff };


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
	delay(500);
}

void draw(){
	//Ritar ut xbm-datan
	display.drawXBMP(0, 0, img_width, img_height, img_bits);
}


