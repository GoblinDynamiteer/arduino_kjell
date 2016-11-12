/* Kjell.com - Hur funkar Arduino?, Sida 210

Anslut till wifi-nätverk med WiFi-modul ESP8266
Sätt upp enkel webserver med sida

*/

#include <SoftwareSerial.h>
#include <WiFiEsp.h>

SoftwareSerial Serial1(6,7);


//http://glassdragon.se/is/arduino/webserver/jk_cartoon_bw.png
//SSID & lösenord för WiFi-modul
char ssid[] = "";
char pw[] = "";

int status = WL_IDLE_STATUS;

//Starta webserver (från WiFiEsp.h)
WiFiEspServer server(80);

void printWiFiStatus();

void setup(){
	//Serial för debug och info
	Serial1.begin(9600);
	Serial.begin(115200);
	
	WiFi.init(&Serial1);
	
	if(WiFi.status() == WL_NO_SHIELD){
		Serial.println("WiFi Shield not present!");
		while(1);
	}
	
	while(status != WL_CONNECTED){
		Serial.print("Connecting to SSID: ");
		Serial.println(ssid);
		
		status = WiFi.begin(ssid, pw);
	}
	
	Serial.println("Connection successful!");
	printWiFiStatus();
	
	//startar webserver
	server.begin();
}

//code from https://github.com/bportaluri/WiFiEsp/blob/master/examples/WebServer/WebServer.ino
//Somewhat edited
void loop(){
// listen for incoming clients
WiFiEspClient client = server.available();
if (client) {
	Serial.println("New client");
	// an http request ends with a blank line
	boolean currentLineIsBlank = true;
	while (client.connected()) {
		if (client.available()) {
			char c = client.read();
			Serial.write(c);
			// if you've gotten to the end of the line (received a newline
			// character) and the line is blank, the http request has ended,
			// so you can send a reply
			if (c == '\n' && currentLineIsBlank) {
				Serial.println("Sending response");
				// send a standard http response header
				// use \r\n instead of many println statements to speedup data send
				client.print(
					"HTTP/1.1 200 OK\r\n"
					"Content-Type: text/html\r\n"
					"Connection: close\r\n"	// the connection will be closed after completion of the response
					"Refresh: 20\r\n"	// refresh the page automatically every 20 sec
					"\r\n");
				client.print("<!DOCTYPE HTML>\r\n");
				client.print("<HTML>\r\n");
				client.print("<BODY>\r\n");
				client.print("<H1>Hello World!</H1>\r\n");
				client.print("</BODY>\r\n");
				client.print("</HTML>\r\n");
				break;
			}
			if (c == '\n') {
			// you're starting a new line
			currentLineIsBlank = true;
			}
			else if (c != '\r') {
			// you've gotten a character on the current line
			currentLineIsBlank = false;
			}
		}
		}
	// give the web browser time to receive the data
	delay(10);

	// close the connection:
	client.stop();
	Serial.println("Client disconnected");
  }
}

void printWiFiStatus(){
		Serial.print("SSID: ");
		Serial.println(WiFi.SSID());
		IPAddress ip = WiFi.localIP();
		Serial.print("Local IP: ");
		Serial.println(ip);
}