#include "Display.h"

void Display::recording()
{
    lcd.begin(16, 2);
    lcd.print("  Recording...");
    delay(2000);
}
