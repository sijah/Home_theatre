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
void setup()
{
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
  server.on("/input"handle_input);
  server.on("/tune",handle_tune);
 




}

void loop()
{
  MDNS.update();
  server.handleClient();
}