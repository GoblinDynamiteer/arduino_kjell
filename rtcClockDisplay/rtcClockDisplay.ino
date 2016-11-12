/* 
Kjell.com - Hur funkar Arduino?, Sida 186

Visa tid på OLED-display, från RTC-modul

*/


//https://github.com/Makuna/Rtc
//Arduino Library for RTC, Ds1307 & Ds3231 with deep support.
#include <RtcDS3231.h>

//https://github.com/olikraus/u8glib
#include <U8glib.h>

//Skapar display-objekt
U8GLIB_SSD1306_128X64 display(U8G_I2C_OPT_NONE);

//Skapar RTC-objekt
RtcDS3231 rtcModule;

//Variabler för hållande av tid
byte tim;
byte min;
byte sek;

//Funktion för att rita ut grafik på displayen
void draw();

//Funktion för att hämta tid från RTC-modul
void updateTime();

void setup(){
	Serial.begin(9600);
}

void loop(){
	updateTime();
	display.firstPage(); //Start på bild-loop
	do{
		draw();
	//nexPage() returnerar 1 när bild är färdigskriven?
	}while(display.nextPage()); 
	delay(20);

}

void draw(){
	display.setFont(u8g_font_helvB24);
	
	//Skriv variabler till textsträng
	char tid[10];
	// %u unsigned int
	sprintf(tid, "%02u:%02u:%02u", tim, min, sek);
	//https://github.com/olikraus/u8glib/wiki/userreference#setprintpos
	//Description: Assignes the (x,y) position for the next call of the print procedure.
	display.setPrintPos(0,45);
	//print skriver text till position satt i setPrintPos
	display.print(tid);
	Serial.println(tid);
}

void updateTime(){
	RtcDateTime now = rtcModule.GetDateTime();
	tim = now.Hour();
	min = now.Minute();
	sek = now.Second();
}