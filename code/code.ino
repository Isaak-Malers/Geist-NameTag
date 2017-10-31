// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//note that this is NOT the same pinout that is typically used by the library and other online examples, this pinout is optimized for the smaller arduinos
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//define the strings that are going to be displayed
String ip = "   10.10.0.11   ";
String firmware = "Pink Flustered Chickadee";


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  printIP();
  scrollName();
}

void scrollName(){
  lcd.setCursor(0,0);
  lcd.print(firmware);
  for(int pos=0; pos < firmware.length()-16; pos++){
    lcd.scrollDisplayLeft();
    delay(210);
  }
}


void printIP(){
  lcd.setCursor(0, 1);
  lcd.print(ip);
}

