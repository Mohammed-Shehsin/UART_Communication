
//Master
//used Rasberry pi Pico 
//TX pin GP8 
//RX pin GP9 
void setup() {
  Serial.begin(9600);
 Serial2.begin(9600);

}
void loop() {
  if (Serial.available()) {
    String input = Serial.readString();
    Serial2.write(input.c_str(), input.length());
    String confirm = Serial.readString();
    if(confirm == "Confirm !"){
      Serial.println(confirm);
    }else{
      Serial.println("ERROR");
    }
  }
}
