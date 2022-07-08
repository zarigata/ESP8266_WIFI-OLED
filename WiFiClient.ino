#include <ESP8266WiFi.h>
#ifndef STASSID
#define STASSID "REDACTED"
#define STAPSK  "REDACTED"
#endif
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
String newHostname = "TEST8266";
const char* ssid     = STASSID;
const char* password = STAPSK;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
  pinMode(2,OUTPUT);
  Serial.printf("Default hostname: %s\n", WiFi.hostname().c_str());
  WiFi.hostname(newHostname.c_str());
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  // Display static text
  display.println("CONNECTED TO");
  display.display();
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 20);
  // Display static text
  display.println(WiFi.localIP());
  display.display();
}

void loop() {
  digitalWrite(2,HIGH);
  delay (500);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 20);
  // Display static text
  display.println(WiFi.localIP());
  display.display();

}
