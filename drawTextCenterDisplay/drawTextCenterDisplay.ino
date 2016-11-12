/* Kjell.com - Hur funkar Arduino?, Sida 174

Skriv ut text till OLED-display, mittcentrerad
Kittets medföljande display har upplösningen 128x64px
och är baserad på SSD1306-kontrollern

*/


#include <U8glib.h>
//https://github.com/olikraus/u8glib

//Skapar display-objekt
U8GLIB_SSD1306_128X64 display(U8G_I2C_OPT_NONE);

//Chararrayer för hållande av text
char line1[] = "Do to do,";
char line2[] = "not to try!";

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
	//Sätter teckensnitt Helvetica 10
	//https://github.com/olikraus/u8glib/wiki/fontgroup
	display.setFont(u8g_font_helvB10);

	/* https://github.com/olikraus/u8glib/wiki/userreference
	getFontAscent & getFontDescent anger teckensnittets höjd över och under 
	"linjen" den är skriven på getFontDescent anger negativt värde! */
	
	//använd subtraktion för att addera (getFontDescent returnerar negativt värde)
	int textHojd = display.getFontAscent() - display.getFontDescent(); 
	
	//Beräkna startpositioner (för mittcentrerade textsträngar i line1 och  line2)
	/* https://github.com/olikraus/u8glib/wiki/userreference
	getWidth() anger displayens bredd i pixlar 
	getStrWidth(x) anger textsträngens bredd i pixlar (med aktuellt teckensnitt)
	width - strwidth blir ytan som inte är uppfylld med text, dividera med 2 för att få "lika mycket" plats
	på båda sior om texten. */
	int line1x = (display.getWidth() - display.getStrWidth(line1)) / 2;
	int line2x = (display.getWidth() - display.getStrWidth(line2)) / 2;
	
	//Skriv ut textsträngarna, med beräknade startpositioner,textHojd * 2 / * 3 för y-koordinater
	display.drawStr(line1x, textHojd * 2, line1);
	display.drawStr(line2x, textHojd * 3, line2);
}