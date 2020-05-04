#include "Display.h"

void Display::menu()
{
    //show the menu: *song #game
    lcd.begin(16, 2);//set the col and row
    lcd.print("     *:Song");
    lcd.setCursor(0, 1); //set the cursor to next line
    lcd.print("     #:Game");

    key = 0;
    while (key == 0) key = keyboard.getKey(); // prevent non-stop execution
}
        
    
