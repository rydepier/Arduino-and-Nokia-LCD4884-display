#include "LCD4884.h" 

#include "bildbmp.h"  
// x-y-relation for prepairing pictures is 28 x 19 ~ 3 x 2
// because LCD-pixels in 84x48 matrix seem to bee not quadratic
// use a high density 3x2 picture, resize to 84x48 non propotional
// and change to black and white 
// google for bmp to pic converter to prepare include-file 

#define DELAY1 200
#define DELAY2 1000
#define DELAY3 5000

unsigned char text[] = "This is|Leo -|our|little|grand-|son.";

void setup()
{
  lcd.LCD_init(); // creates instance of LCD
}

void loop()
{  
   unsigned char i=0, line=0, pos=0, offset;
   unsigned char mychar;
   /*********** 1st ***********/
   lcd.LCD_clear(); // blanks the display
   delay(DELAY1);
   lcd.LCD_draw_bmp_pixel(0,0, bildbmp, 84,48);
   delay(DELAY3);
   lcd.LCD_set_XY(pos,line); //not necessary
   while (mychar=text[i++]) {
     if (mychar != '|') {
       lcd.LCD_prop_write_char(mychar, MENU_NORMAL);
     } else {
       line++;
       pos = 0;
       lcd.LCD_set_XY(pos,line);
     }
     delay(DELAY1);
   } 
   delay(DELAY3);
   /*********** 2nd ***********/
   lcd.LCD_clear(); // blanks the display
   delay(DELAY1);
   lcd.LCD_draw_bmp_pixel(0,0, bild2bmp, 84,48);
   delay(DELAY3);
   lcd.LCD_prop_write_string(0,0,"This",MENU_NORMAL);
   delay(DELAY2);
   lcd.LCD_prop_write_string(0,1,"is",MENU_NORMAL);
   delay(DELAY2);
   lcd.LCD_prop_write_string(0,2,"Trixi -",MENU_NORMAL);
   delay(DELAY2);
   lcd.LCD_prop_write_string(0,3,"his",MENU_NORMAL);
   delay(DELAY2);
   lcd.LCD_prop_write_string(0,4,"\"big\"",MENU_NORMAL);
   delay(DELAY2);
   lcd.LCD_prop_write_string(0,5,"sister.",MENU_NORMAL);
   delay(DELAY3);
}
