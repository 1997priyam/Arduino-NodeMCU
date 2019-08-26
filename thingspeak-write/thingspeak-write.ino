#include <dht.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
 
 
const char* ssid     = "Priyam";
const char* password = "priyam123456";

unsigned long myChannelNumber = 506752;
const char * myWriteAPIKey = "QNAB5GGIUSYYU69D";
 
WiFiClient WiFiclient;
dht DHT;

 

 
void setup() {
 Serial.begin(115200);
 delay(10);
 Serial.println();
 Serial.println();
 Serial.print("Connecting to ");
 Serial.println(ssid);
 
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }
 
 Serial.println("");
 Serial.println("WiFi connected");  
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
 delay(2000);
 
 ThingSpeak.begin(WiFiclient);
}
 
void loop() {
 DHT.read11(13);
 String temp = (String)DHT.temperature;
 String humidity = (String)DHT.humidity; 
 ThingSpeak.setField(1, temp);
 ThingSpeak.setField(2, humidity);
 ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
 delay(17000);

}

