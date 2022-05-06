// Demo based on:
// UTFT_Demo_320x240 by Henning Karlsen
// web: http://www.henningkarlsen.com/electronics
//

#include "SPI.h"
#include "Adafruit_GFX_AS.h"
#include "Adafruit_HX8357_AS.h"

#define HX8357_GREY 0x7BEF

Adafruit_HX8357_AS myGLCD = Adafruit_HX8357_AS();       // Invoke custom library
//Adafruit_HX8357_AS myGLCD = Adafruit_HX8357_AS(cs, dc ,mosi ,sclk , rst ,12);       // Invoke custom library
unsigned long runTime = 0;
void setup()
{
  randomSeed(analogRead(A0));
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  delay(10);
  digitalWrite(7, HIGH);
// Setup the LCD
  myGLCD.begin(HX8357B);
  myGLCD.setRotation(0);
}

void loop()
{
  randomSeed(millis());
  //randomSeed(1234); // This ensure test is repeatable with exact same draws each loop
  int buf[318];
  int x, x2;
  int y, y2;
  int r;
  runTime = millis();
// Clear the screen and draw the frame
  myGLCD.fillScreen(HX8357_BLACK);


  myGLCD.fillRect(0, 0, 319, 14,HX8357_RED);

  myGLCD.fillRect(0, 226, 319, 14,HX8357_GREY);

  myGLCD.setTextColor(HX8357_BLACK,HX8357_RED);
  myGLCD.drawCentreString("* HX8357_AS Color TFT Display Library *", 160, 3, 1);
  myGLCD.setTextColor(HX8357_YELLOW,HX8357_GREY);
  myGLCD.drawCentreString("Adapted by Bodmer 13/2/15", 160, 229,1);

  myGLCD.drawRect(0, 14, 319, 211, HX8357_BLUE);

// Draw crosshairs
  myGLCD.drawLine(159, 15, 159, 224,HX8357_BLUE);
  myGLCD.drawLine(1, 119, 318, 119,HX8357_BLUE);
  for (int i=9; i<310; i+=10)
    myGLCD.drawLine(i, 117, i, 121,HX8357_BLUE);
  for (int i=19; i<220; i+=10)
    myGLCD.drawLine(157, i, 161, i,HX8357_BLUE);

// Draw sin-, cos- and tan-lines  
  myGLCD.setTextColor(HX8357_CYAN);
  myGLCD.drawString("Sin", 5, 15,2);
  for (int i=1; i<318; i++)
  {
    myGLCD.drawPixel(i,119+(sin(((i*1.13)*3.14)/180)*95),HX8357_CYAN);
  }
  myGLCD.setTextColor(HX8357_RED);
  myGLCD.drawString("Cos", 5, 30,2);
  for (int i=1; i<318; i++)
  {
    myGLCD.drawPixel(i,119+(cos(((i*1.13)*3.14)/180)*95),HX8357_RED);
  }
  myGLCD.setTextColor(HX8357_YELLOW);
  myGLCD.drawString("Tan", 5, 45,2);
  for (int i=1; i<318; i++)
  {
    myGLCD.drawPixel(i,119+(tan(((i*1.13)*3.14)/180)),HX8357_YELLOW);
  }

  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

  myGLCD.drawLine(159, 15, 159, 224,HX8357_BLUE);
  myGLCD.drawLine(1, 119, 318, 119,HX8357_BLUE);
int col = 0;
// Draw a moving sinewave
  x=1;
  for (int i=1; i<(317*20); i++) 
  {
    x++;
    if (x==318)
      x=1;
    if (i>318)
    {
      if ((x==159)||(buf[x-1]==119))
        col = HX8357_BLUE;
      else
      myGLCD.drawPixel(x,buf[x-1],HX8357_BLACK);
    }
    y=119+(sin(((i*1.1)*3.14)/180)*(90-(i / 100)));
    myGLCD.drawPixel(x,y,HX8357_BLUE);
    buf[x-1]=y;
  }

  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

// Draw some filled rectangles
  for (int i=1; i<6; i++)
  {
    switch (i)
    {
      case 1:
        col = HX8357_MAGENTA;
        break;
      case 2:
        col = HX8357_RED;
        break;
      case 3:
        col = HX8357_GREEN;
        break;
      case 4:
        col = HX8357_BLUE;
        break;
      case 5:
        col = HX8357_YELLOW;
        break;
    }
    myGLCD.fillRect(70+(i*20), 30+(i*20), 60, 60,col);
  }

  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

// Draw some filled, rounded rectangles
  for (int i=1; i<6; i++)
  {
    switch (i)
    {
      case 1:
        col = HX8357_MAGENTA;
        break;
      case 2:
        col = HX8357_RED;
        break;
      case 3:
        col = HX8357_GREEN;
        break;
      case 4:
        col = HX8357_BLUE;
        break;
      case 5:
        col = HX8357_YELLOW;
        break;
    }
    myGLCD.fillRoundRect(190-(i*20), 30+(i*20), 60,60, 3,col);
  }
  
  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

// Draw some filled circles
  for (int i=1; i<6; i++)
  {
    switch (i)
    {
      case 1:
        col = HX8357_MAGENTA;
        break;
      case 2:
        col = HX8357_RED;
        break;
      case 3:
        col = HX8357_GREEN;
        break;
      case 4:
        col = HX8357_BLUE;
        break;
      case 5:
        col = HX8357_YELLOW;
        break;
    }
    myGLCD.fillCircle(100+(i*20),60+(i*20), 30,col);
  }
  
  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

// Draw some lines in a pattern

  for (int i=15; i<224; i+=5)
  {
    myGLCD.drawLine(1, i, (i*1.44)-10, 223,HX8357_RED);
  }

  for (int i=223; i>15; i-=5)
  {
    myGLCD.drawLine(317, i, (i*1.44)-11, 15,HX8357_RED);
  }

  for (int i=223; i>15; i-=5)
  {
    myGLCD.drawLine(1, i, 331-(i*1.44), 15,HX8357_CYAN);
  }

  for (int i=15; i<224; i+=5)
  {
    myGLCD.drawLine(317, i, 330-(i*1.44), 223,HX8357_CYAN);
  }
  
  //delay(2000);


  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

// Draw some random circles
  for (int i=0; i<100; i++)
  {
    x=32+random(256);
    y=45+random(146);
    r=random(30);
    myGLCD.drawCircle(x, y, r,random(0xFFFF));
  }

  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

// Draw some random rectangles
  for (int i=0; i<100; i++)
  {
    x=2+random(316);
    y=16+random(207);
    x2=2+random(316);
    y2=16+random(207);
    if (x2<x) {
      r=x;x=x2;x2=r;
    }
    if (y2<y) {
      r=y;y=y2;y2=r;
    }
    myGLCD.drawRect(x, y, x2-x, y2-y,random(0xFFFF));
  }

  //delay(2000);


  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

// Draw some random rounded rectangles
  for (int i=0; i<100; i++)
  {
    x=2+random(316);
    y=16+random(207);
    x2=2+random(316);
    y2=16+random(207);
    // We need to get the width and height and do some window checking
    if (x2<x) {
      r=x;x=x2;x2=r;
    }
    if (y2<y) {
      r=y;y=y2;y2=r;
    }
    // We need a minimum size of 6
    if((x2-x)<6) x2=x+6;
    if((y2-y)<6) y2=y+6;
    myGLCD.drawRoundRect(x, y, x2-x,y2-y, 3,random(0xFFFF));
  }

  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

 //randomSeed(1234);
 int colour = 0;
 for (int i=0; i<100; i++)
  {
    x=2+random(316);
    y=16+random(209);
    x2=2+random(316);
    y2=16+random(209);
    colour=random(0xFFFF);
    myGLCD.drawLine(x, y, x2, y2,colour);
  }

  //delay(2000);

  myGLCD.fillRect(1,15,317,209,HX8357_BLACK);

  byte i = 100;
  while (i--) {
    byte j = 100;
    while (j--) myGLCD.drawPixel(i+110,j+70,i+j);//2+random(316), 16+random(209),random(0xFFFF));
  }
  //delay(2000);

  //myGLCD.fillScreen(HX8357_BLUE);
  myGLCD.fillRect(0, 0, 319, 239,HX8357_BLUE);
  myGLCD.fillRoundRect(80, 70, 239-80,169-70, 3,HX8357_RED);
  
  myGLCD.setTextColor(HX8357_WHITE,HX8357_RED);
  myGLCD.drawCentreString("That's it!", 160, 93,2);
  myGLCD.drawCentreString("Restarting in a", 160, 119,2);
  myGLCD.drawCentreString("few seconds...", 160, 132,2);

  runTime = millis()-runTime;
  myGLCD.setTextColor(HX8357_GREEN,HX8357_BLUE);
  myGLCD.drawCentreString("Runtime: (msecs)", 160, 210,2);
  myGLCD.drawNumber(runTime, 130, 225,2);
  delay (5000);
}


