
struct myStruct {
  String str;
  bool booleans;
  int timestamp;
  int integer;
  float floats;
};

// List of random strings
const String stringList[] = {
  "apple",
  "banana",
  "cherry",
  "orange",
  "pears"
};

unsigned long startMillis = millis();

unsigned long currentMillis;
const unsigned long interval = 1000;
String confirm;

void sendStruct(const myStruct &data) {
  String newString = data.str + " " + (data.booleans ? "true" : "false") + " "+String(data.timestamp)+" " + String(data.integer) + " " + String(data.floats, 2) + ";";
  // Send the message
  Serial2.write(newString.c_str(), newString.length());
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial2.setTimeout(300);
}

void loop() {
  myStruct data;
  int randomIndex = random(0, 5);
  data.timestamp = millis();
  data.str = stringList[randomIndex];
  data.booleans = random(0, 2);  
  data.integer = random(-100, 100);  
  data.floats = random(-1000, 1000) / 10.0;  
 
 
  currentMillis = millis();
 
  sendStruct(data);

  startMillis = currentMillis; // Update the previous time to the current time

  while(currentMillis - startMillis <= interval){
    currentMillis = millis();
    confirm = Serial2.readString();
    if(confirm != ""){
      break;
    }
  }

  if (confirm == "Confirm !") {
    Serial.println(confirm);
  } else {
    Serial.println("ERROR");
    Serial.println(randomIndex);
    Serial.println(data.str);
    Serial.println(data.booleans);
    Serial.println(data.integer);
    Serial.println(data.floats);
  }
}
