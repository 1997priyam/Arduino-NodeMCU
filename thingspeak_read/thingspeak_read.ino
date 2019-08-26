
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
 
 
const char* ssid     = "Priyam";
const char* password = "priyam123456";

unsigned long myChannelNumber = 506752;
const char * myReadAPIKey = "L6DF8K7UBZ8IM9UM";

 
WiFiClient WiFiclient;

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
  String temp;
  String humidity;
 temp = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);
 Serial.println("Temperature= "+temp+"*C");
 humidity = ThingSpeak.readFloatField(myChannelNumber, 2, myReadAPIKey);
 Serial.println("Humidity= "+humidity+"%");
 delay(5000);

}

