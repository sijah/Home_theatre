#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <TDA7439.h>
ESP8266WebServer server(80);
TDA7439 audio = TDA7439();
const char *ssid ="";
const char *pass="";
void setup() {
  audio.setInput(1);
}

void loop() {
  // put your main code here, to run repeatedly:
}