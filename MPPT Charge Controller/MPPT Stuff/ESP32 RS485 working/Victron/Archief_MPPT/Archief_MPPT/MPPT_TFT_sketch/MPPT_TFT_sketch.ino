/* Connections:
    MPPT pin     MPPT        Arduino     Arduino pin
    1            GND         GND         GND
    2            RX          TX          -              do not use!
    3            TX          RX          19 (MEGA)
    4            Power+      none        -              do not use!
 */


#include <Adafruit_GFX_AS.h>    // Core graphics library
#include <Adafruit_HX8357_AS.h> // Hardware-specific library

Adafruit_HX8357_AS tft = Adafruit_HX8357_AS(); 

byte red = 31;
byte green = 0;
byte blue = 0;
byte state = 0;
unsigned int colour = red << 11;
byte len = 12;
int intmeetwaarde;
String label, val;
String CS7 =  "";
String ERR1 = "     Geen";
String CS0 =  "      Uit";
String CS2 =  "     Fout";
String CS3 =  "     Bulk";
String CS4 =  "Absorptie";
String CS5 =  "  Druppel";
float meetwaarde;
char buf[45];
char laadstroom[6];
char paneelvermogen[6];
char voorloop[12];
char laadstatus[12];
char foutmelding[12];
char yieldgisteren[6];
char vermogengisteren[6];
char yieldvandaag[6];

void setup(void)  
{
  tft.begin(HX8357B);                                       // Start communication with the display
  tft.setRotation(1);
  Serial1.begin(19200);                                     // Start communication with the MPPT controller, on the MEGA communication is through serial port 1
  CS7.toCharArray(voorloop,len);  

  tft.setTextSize(2);                                       // I think this sets the font size, this font size of course can be adjusted
  tft.fillScreen(HX8357_BLACK);
    
  tft.setTextColor(HX8357_BLUE,HX8357_BLACK);               // Setting text to blue, background to black
    
  tft.drawString("Informatiepaneel zonnestroom",0,0,2);     // The text printed here in setup, is only printed once. This is the information on the display that will not change.
  tft.drawString("van zeiljacht Romlea",0,30,2);            // Of course this can be adjusted to any colour combinations you would like and any tekst you would like
    
  tft.setTextColor(HX8357_GREEN,HX8357_BLACK);    

  tft.drawString("Paneelvermogen",0,90,2);                  // 0,90 refers to the coordinates on the screen, I believe 2 being the text size. Maybe worth experimenting with
  tft.drawString("Watt",400,90,2);                          // to set it to your own needs

  tft.drawString("Laadstroom",0,120,2);
  tft.drawString("Ampère",400,120,2);

  tft.drawString("Laadstatus",0,150,2);

  tft.drawString("Foutmelding",0,180,2);

  tft.setTextColor(HX8357_MAGENTA,HX8357_BLACK);            // The colours can be found back in one of the included libraries.
  tft.drawString("Opbrengst vandaag",0,210,2);
  tft.drawString("kWh",400,210,2);


  tft.setTextColor(HX8357_RED,HX8357_BLACK);
  tft.drawString("Opbrengst gisteren",0,240,2);
  tft.drawString("kWh",400,240,2);

  tft.drawString("Max vermogen gisteren",0,275,2);
  tft.drawString("Watt",400,275,2);
} 

void loop() 
{
  if (Serial1.available())
   {
        label = Serial1.readStringUntil('\t');                // this is the actual line that reads the label from the MPPT controller
        val = Serial1.readStringUntil('\r\r\n');              // this is the line that reads the value of the label
        
     if (label == "I")                                        // I chose to select certain paramaters that were good for me. check the Victron whitepaper for all labels.
     {                                                        // In this case I chose to read charging current
        val.toCharArray(buf, sizeof(buf));                    // conversion of val to a character array. Don't ask me why, I saw it in one of the examples of Adafruit and it works.
        float meetwaarde = atof(buf);                         // conversion to float
        meetwaarde = meetwaarde/1000;                         // calculating the correct value, see the Victron whitepaper for details. The value of label I is communicated in milli amps.
        dtostrf(meetwaarde, len, 2, laadstroom);              // conversion of calculated value to string
        laadstroom[len] = ' '; laadstroom[len+1] = 0;
        tft.setTextColor(HX8357_GREEN,HX8357_BLACK);          // setting color scheme
        tft.drawString(laadstroom,230,120,2);                 // printing string of the value including a "space"
     }
     else if (label == "PPV")                             
     {
        val.toCharArray(buf, sizeof(buf));                    // By studying these small routines, you can modify to reading the parameters you want,
        meetwaarde = atof(buf);                               // converting them to the desired value (milli-amps to amps or whatever)
        dtostrf(meetwaarde, len, 0, paneelvermogen);          // setting color scheme etc.
        paneelvermogen[len] = ' '; paneelvermogen[len+1] = 0; 
        tft.setTextColor(HX8357_GREEN,HX8357_BLACK);    
        tft.drawString(paneelvermogen,230,90,2);       
     }
     else if (label == "H22") 
     {
        val.toCharArray(buf, sizeof(buf));
        float meetwaarde = atof(buf);
        meetwaarde=meetwaarde/100;
        dtostrf(meetwaarde, len, 2, yieldgisteren);
        yieldgisteren[len] = ' '; yieldgisteren[len+1] = 0;
        tft.setTextColor(HX8357_RED,HX8357_BLACK);
        tft.drawString(yieldgisteren,230,240,2);
     }
     else if (label == "H20") 
     {
        val.toCharArray(buf, sizeof(buf));
        float meetwaarde = atof(buf);
        meetwaarde=meetwaarde/100;
        dtostrf(meetwaarde, len, 2, yieldvandaag);
        yieldvandaag[len] = ' '; yieldvandaag[len+1] = 0;
        tft.setTextColor(HX8357_MAGENTA,HX8357_BLACK);
        tft.drawString(yieldvandaag,230,210,2);
     }
     else if (label == "H23") 
     {
        val.toCharArray(buf, sizeof(buf));
        meetwaarde = atof(buf);
        dtostrf(meetwaarde, len, 0, vermogengisteren);
        vermogengisteren[len] = ' '; vermogengisteren[len+1] = 0;
        tft.setTextColor(HX8357_RED,HX8357_BLACK);
        tft.drawString(vermogengisteren,230,275,2);

     } 
     else if (label == "ERR")                               // This routine reads the error code. If there is no error, "Geen" will be printed. See line 24 of this sketch
     {                                                      // else the actual error code will be printed. Refer to the Victron whitepaper for reference.
             val.toCharArray(buf, sizeof(buf));
             intmeetwaarde = atoi(buf);
             if (intmeetwaarde == 0)
             {
             ERR1.toCharArray(foutmelding,len);
             }
             else if (intmeetwaarde != 0)  
             {
             itoa (foutmelding, intmeetwaarde, 12);
             }
        tft.setTextColor(HX8357_GREEN,HX8357_BLACK);    
        tft.drawString(voorloop,265,180,2);
        tft.drawString(foutmelding,265,180,2);

     }   
     else if (label == "CS")                                  // this routine reads Charge Status, see lines 25 - 29
     {
        val.toCharArray(buf, sizeof(buf));
        intmeetwaarde = atoi(buf);
        if (intmeetwaarde == 0)
        {
        CS0.toCharArray(laadstatus,len);
        }
        else if (intmeetwaarde == 2)
        {
        CS2.toCharArray(laadstatus,len);
        }
        else if (intmeetwaarde == 3)
        {
        CS3.toCharArray(laadstatus,len);
        }
        else if (intmeetwaarde == 4)
        {
        CS4.toCharArray(laadstatus,len);
        }
        else if (intmeetwaarde == 5)
        {
        CS5.toCharArray(laadstatus,len);
        }
        laadstatus[len] = ' '; laadstatus[len+1] = 0;
        tft.setTextColor(HX8357_GREEN,HX8357_BLACK);  
        tft.drawString(voorloop,265,150,2);          
        tft.drawString(laadstatus,265,150,2);
     }
   }
}
