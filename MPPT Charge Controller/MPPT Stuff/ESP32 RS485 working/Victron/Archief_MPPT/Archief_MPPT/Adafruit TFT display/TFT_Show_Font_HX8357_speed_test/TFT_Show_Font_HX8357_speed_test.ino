/*
 Show all the fonts.
 
 Uses font sizes 2, 4, 6, 7 and 8 which are implemented in the Adafruit_GFX_AS library.
 
 Colours:
 
 code	color
 0x0000	Black
 0xFFFF	White
 0xBDF7	Light Gray
 0x7BEF	Dark Gray
 0xF800	Red
 0xFFE0	Yellow
 0xFBE0	Orange
 0x79E0	Brown
 0x7E0	Green
 0x7FF	Cyan
 0x1F	     Blue
 0xF81F	Pink
 
 Adapted by rowboteer
 */

#include <Adafruit_GFX_AS.h>    // Core graphics library
#include <Adafruit_HX8357_AS.h> // Hardware-specific library

#define DELAY 1000

Adafruit_HX8357_AS tft = Adafruit_HX8357_AS();       // Invoke custom library

unsigned long targetTime = 0;
byte red = 31;
byte green = 0;
byte blue = 0;
byte state = 0;
unsigned int colour = red << 11;

void setup(void) {
  tft.begin(HX8357B);
  tft.setRotation(1);
}

void loop() {
targetTime = millis();

    tft.setTextSize(1);
    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_GREEN,HX8357_BLACK);

    tft.drawString(" !\"#$%&'()*+,-./0123456",0,0,2);
    tft.drawString("789:;<=>?@ABCDEFGHIJKL",0,16,2);
    tft.drawString("MNOPQRSTUVWXYZ[\\]^_`",0,32,2);
    tft.drawString("abcdefghijklmnopqrstuvw",0,48,2);
    int xpos=0;
    xpos+=tft.drawString("xyz{|}~",0,64,2);
    tft.drawChar(127,xpos,64,2);
    delay(DELAY);
    
    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_GREEN,HX8357_BLACK);

    tft.drawString(" !\"#$%&'()*+,-.",0,0,4);
    tft.drawString("/0123456789:;",0,26,4);
    tft.drawString("<=>?@ABCDE",0,52,4);
    tft.drawString("FGHIJKLMNO",0,78,4);
    tft.drawString("PQRSTUVWX",0,104,4);
    
    delay(DELAY);
    tft.fillScreen(HX8357_BLACK);
    tft.drawString("YZ[\\]^_`abc",0,0,4);
    tft.drawString("defghijklmno",0,26,4);
    tft.drawString("pqrstuvwxyz",0,52,4);
    xpos=0;
    xpos+=tft.drawString("{|}~",0,78,4);
    tft.drawChar(127,xpos,78,4);
    delay(DELAY);
    
    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_BLUE,HX8357_BLACK);

    tft.drawString("012345",0,0,6);
    tft.drawString("6789",0,40,6);
    tft.drawString("apm-:.",0,80,6);
    delay(DELAY);

    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_RED,HX8357_BLACK);

    tft.drawString("0123",0,0,7);
    tft.drawString("4567",0,60,7);
    delay(DELAY);

    tft.fillScreen(HX8357_BLACK);
    tft.drawString("890:.",0,0,7);
    tft.drawString("",0,60,7);
    delay(DELAY);

    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_YELLOW,HX8357_BLACK);

    tft.drawString("0123",0,0,8);
    tft.drawString("4567",0,80,8);
    delay(DELAY);

    tft.fillScreen(HX8357_BLACK);
    tft.drawString("890:.",0,0,8);
    tft.drawString("",0,80,8);
    delay(DELAY);
    
    tft.setTextSize(2);
    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_GREEN);

    tft.drawString(" !\"#$%&'()*+,-./0123456",0,0,2);
    tft.drawString("789:;<=>?@ABCDEFGHIJKL",0,32,2);
    tft.drawString("MNOPQRSTUVWXYZ[\\]^_`",0,64,2);
    tft.drawString("abcdefghijklmnopqrstuvw",0,96,2);
    xpos=0;
    xpos+=tft.drawString("xyz{|}~",0,128,2);
    tft.drawChar(127,xpos,128,2);
    delay(DELAY);
    
    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_GREEN);

    tft.drawString(" !\"#$%&'()*+,-.",0,0,4);
    tft.drawString("/0123456789:;",0,52,4);
    tft.drawString("<=>?@ABCDE",0,104,4);
    tft.drawString("FGHIJKLMNO",0,156,4);
    tft.drawString("PQRSTUVWX",0,208,4);
    delay(DELAY);
    tft.fillScreen(HX8357_BLACK);
    tft.drawString("YZ[\\]^_`abc",0,0,4);
    tft.drawString("defghijklmno",0,52,4);
    tft.drawString("pqrstuvwxyz",0,104,4);
    xpos=0;
    xpos+=tft.drawString("{|}~",0,156,4);
    tft.drawChar(127,xpos,156,4);
    delay(DELAY);
    
    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_BLUE);

    tft.drawString("01234",0,0,6);
    tft.drawString("56789",0,80,6);
    tft.drawString("apm-:.",0,160,6);
    delay(DELAY);

    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_RED);

    tft.drawString("0123",0,0,7);
    tft.drawString("4567",0,120,7);
    delay(DELAY);

    tft.fillScreen(HX8357_BLACK);
    tft.drawString("890:.",0,0,7);
    tft.drawString("",0,120,7);
    delay(DELAY);
    
    tft.fillScreen(HX8357_BLACK);
    tft.setTextColor(HX8357_YELLOW,HX8357_BLACK);

    tft.drawString("0123",0,0,8);
    tft.drawString("4567",0,160,8);
    delay(DELAY);

    tft.fillScreen(HX8357_BLACK);
    tft.drawString("890:.",0,0,8);
    tft.drawString("",0,160,8);
    delay(DELAY);
    
    tft.setTextColor(HX8357_MAGENTA, HX8357_WHITE);

    tft.drawNumber(millis()-targetTime,0,180,4);
    delay(4001);
}

void rainbow(int ystart, int ylen)
{
    red = 31;
    green = 0;
    blue = 0;
    state = 0;
    colour = red << 11;
    
    for (int i = 0; i<160; i++) {
      tft.drawFastVLine(i, ystart, ylen, colour);
      switch (state) {
      case 0: 
        green +=2;
        if (green == 64) {
          green=63; 
          state = 1;
        }
        break;
      case 1: 
        red--;
        if (red == 255) {
          red = 0;
          state = 2; 
        }
        break;
      case 2: 
        blue ++;
        if (blue == 32) {
          blue=31; 
          state = 3; 
        }
        break;
      case 3: 
        green -=2;
        if (green ==255) {
          green=0; 
          state = 4; 
        }
        break;
      case 4: 
        red ++;
        if (red == 32) {
          red = 31; 
          state = 5; 
        }
        break;
      case 5: 
        blue --;
        if (blue == 255) {
          blue = 0; 
          state = 0; 
        }
        break;
      }
      colour = red<<11 | green<<5 | blue;
    }
}





