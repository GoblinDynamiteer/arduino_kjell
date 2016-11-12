/* 
Kjell.com - Hur funkar Arduino?, Sida 185

Sätt datum och klockslag på RTC-modul

*/


//https://github.com/Makuna/Rtc
//Arduino Library for RTC, Ds1307 & Ds3231 with deep support.
#include <RtcDS3231.h>

//https://www.arduino.cc/en/Reference/Wire
//This library allows you to communicate with I2C / TWI devices.
#include <Wire.h>


//Skapar RTC-objekt
RtcDS3231 rtcModule;

void setup(){
	//Startar I2C kommunikation
	Wire.begin();
	
	/*Sätter datum och klockslag till kompilerings-tid
	__DATE__  __TIME__ är variabler för kompilatorn
	Om RTC-modulen inte är ansluten vid kompilering så kommer tiden inte att stämma */
	RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
	rtcModule.SetDateTime(compiled);
}

void loop(){

}