#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     4
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String text;
String textbuffer[4];
int nroflinebreaks;

void SetupOledMonitor() {

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.cp437(true);
  display.clearDisplay();
  display.display();

}


void printoled (String text) {

if (text.length()>80){text="OUTPUT TOO LONG !";}
 
nroflinebreaks=(text.length()/22);   

for (int scrolls=0;scrolls<(nroflinebreaks+1);scrolls++){
  for (int shift = 0 ; shift < 3; shift++) {
    textbuffer[shift ] = textbuffer[shift + 1];
  }
}
  textbuffer[3-nroflinebreaks] = text;

  display.clearDisplay();
  display.setCursor(0, 0);

  for (int line = 0; line < 4; line++) {
    display.println(textbuffer[line]);
  }

  display.display();

}

void clearoled () {
  for (int line = 0; line < 4; line++) {
  textbuffer[line]="";
  }

  display.clearDisplay();
  display.display();

}
