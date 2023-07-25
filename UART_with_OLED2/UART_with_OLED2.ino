//used RP2040-zero
//TX pin GPI08 
//RX pin GPI09
#include <GyverOLED.h>
GyverOLED<SSH1106_128x64> oled;
const int n = 30;
char myString[n] ;
char receivedChar;
bool isSerial2Available = true;
void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);

}
void loop() {
  int i =0;
   while (i < n) {
      if (Serial2.available()) {
       // startMillis = currentMillis;
        receivedChar = Serial2.read();

        if (receivedChar == ';') {
          myString[i] = '\0';
          break;
        }

        myString[i] = receivedChar;
        i++;
      } else {
        isSerial2Available = false;
        break;
      }
    }
  if (isSerial2Available) {
      Serial.println(myString);
      delay(1000);
      
      
    } else {
    //   Serial.println("Serial2 is not available!");
    delay(1000);
      isSerial2Available = true;  // Reset the flag variable
    }
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
    if (myString[0] != '\0') {
        Serial.println("RECEIVED !");
        for (int j = 0; j < n; j++) {
          myString[j] = '\0';
        }
  }
  oled.rect(0,0,127,63,OLED_STROKE);
  oled.update();
  delay(2000);
  
}