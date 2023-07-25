//used RP2040-zero
//TX pin GPI08 
//RX pin GPI09
#include <GyverOLED.h>
GyverOLED<SSH1106_128x64> oled;
char myString[10];
void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);

}
void loop() {
  Serial2.readBytes(myString,5);
  //int value = Serial2.read();
  Serial.print(myString);
  //Serial.println(value);
  Serial.println(" RECIEVED !");
  delay(1000);
}

void setup1(){
  oled.init();
  oled.clear();
  oled.update();
  oled.setCursorXY(30,26);
  oled.print("Welcome !");
  oled.rect(0,0,127,63,OLED_STROKE);
  oled.update();
  delay(1000);
}
void loop1(){
   oled.clear();
  oled.setCursorXY(26,26);
  oled.print(myString);
  oled.print(" Recieved !");
  oled.rect(0,0,127,63,OLED_STROKE);
  delay(100);
  oled.update();
}