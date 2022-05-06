/* Connections:
    MPPT pin     MPPT        Arduino     Arduino pin
    1            GND         GND         GND
    2            RX          TX          -              do not use!
    3            TX          RX          19 (MEGA)
    4            Power+      none        -              do not use!
 */


String label, val, laadstatus;
float meetwaarde;

void setup()  
{
  Serial.begin(57600);
  Serial1.begin(19200);
} 

void loop() 
{
  if (Serial1.available())
   {
        label = Serial1.readStringUntil('\t');      
        val = Serial1.readStringUntil('\r\r\n');
        Serial.println(label + val);
   } 
}
