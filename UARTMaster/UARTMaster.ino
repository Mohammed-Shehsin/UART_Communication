//used Rasberry pi Pico 
//TX pin GP8 
//RX pin GP9 
char myString[6]="Hello";
void setup() {
  Serial.begin(9600);
 Serial2.begin(9600);

}
void loop(){
   Serial2.write(myString,5);
 // String value = Serial.readString();
 // int value = Serial.read();
 // Serial2.write(value);
  Serial.println();
  delay(1000);
}
