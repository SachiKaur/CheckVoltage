#include "LiquidCrystal.h"

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

float input_voltage = 0.0;
float temp=0.0;

void setup()
{
   Serial.begin(9600);     
   lcd.begin(16, 2);       
   lcd.print("DIGITAL VOLTMETER");
}
void loop()
{
   int analog_value = analogRead(A0);
   input_voltage = (analog_value * 5.0) / 1024.0; 
   
   if (input_voltage < 0.1) 
   {
     input_voltage=0.0;
   } 
    Serial.print("v= ");
    Serial.println(input_voltage);
    lcd.setCursor(0, 1);
    lcd.print("Voltage= ");
    lcd.print(input_voltage);
    delay(300);
}
