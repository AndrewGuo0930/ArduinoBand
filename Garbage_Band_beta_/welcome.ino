#include "Display.h"

void Display::welcome()
{
    //welcome
    lcd.begin(16, 2); //set col and row
    lcd.print("   Welcome to");
    lcd.setCursor(0, 1); //set cursor to next line
    lcd.print("  Garbage Band");
    delay(2000);
}
