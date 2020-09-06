#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <TDA7439.h>
#include <ESP8266mDNS.h>
#include <LittleFS.h>
ESP8266WebServer server(80);
TDA7439 audio = TDA7439();
const char *ssid = "";
const char *pass = "";

uint8_t power = D3; 
//uint8_t sda = D2;
//uint8_t scl = D1;
uint8_t ir = D4;
 

 void handle_root(){

File p = LittleFS.open("/index.html","r");
server.streamFile(p,"text/html");
 }

 void handle_input(){
String input = server.arg("i");
int inputt = input.toInt();
switch (inputt)
{
case 1:
  digitalWrite(power,HIGH);
  break;
  case 2:
  digitalWrite(power,LOW);
  break;

default:
  break;
}

 }

 void handle_tune(){
String ipv = server.arg("v");
String ipb = server.arg ("b");
String ipt = server.arg ("t");
int iipv =ipv.toInt();
int iipb =ipb.toInt();
int iipt =ipt.toInt();

audio.setVolume(iipv);
audio.setSnd(1,iipb);
audio.setSnd(3,iipt);
 }


void setup()
{
  Wire.begin(SDA,SCL);
  Serial.begin(115200);
  delay(100);

  if (LittleFS.begin())
  {
    Serial.print("littlefson");
  }
  else
  {
    Serial.print("littlefs no working");
  }
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.print(ssid);
  Serial.print("connected ip");
  Serial.println(WiFi.localIP());
  if (!MDNS.begin("esp8266"))
  {
    Serial.println("Error setting up MDNS responder!");
    while (1)
    {
      delay(1000);
    }
  }
  server.on("/",handle_root);
  server.on("/input",handle_input);
  server.on("/tune",handle_tune);
 server.begin();




}

void loop()
{
  MDNS.update();
  server.handleClient();
}