//used RP2040-zero
//TX pin GPI08 
//RX pin GPI09 
char myString[10];
void setup(){
  Serial.begin(9600);
  Serial2.begin(9600);

}
void loop() {
  Serial2.readBytes(myString,5);
  //int value = Serial2.read();
  Serial.println(myString);
  //Serial.println(value);
  Serial.println(" RECIEVED !");
  delay(1000);
}
