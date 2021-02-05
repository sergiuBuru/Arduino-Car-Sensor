/*
 * How to configure and pair two HC-05 Bluetooth Modules
 * by Dejan Nedelkovski, www.HowToMechatronics.com
 * 
 *                 == MASTER CODE ==
 */
#include <LiquidCrystal.h>
int potPin = 7;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int state = 0;
void setup() {
  analogWrite(potPin, 10);
  lcd.begin(16, 2);
  //pinMode(potPin, OUTPUT);
  Serial.begin(9600); // Default communication rate of the Bluetooth module
  //lcd.write("Dist: ");
  //lcd.setCursor(6,0);
}

void loop() {
 
 if(Serial.available()){ // Checks whether data is comming from the serial port
    delay(100);
    lcd.clear();
    lcd.write("Dist: ");
    
    lcd.setCursor(6,0);
    
    Serial.write(state);
    while(Serial.available() > 0) {
      lcd.write(Serial.read());  
    }
    lcd.write("cm    ");
 }
}
