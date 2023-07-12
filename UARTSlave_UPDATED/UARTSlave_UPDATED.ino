// Slave
// used RP2040-zero
// TX pin GPI08
// RX pin GPI09

unsigned long startMillis;  // some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000;
const int n = 30;
char myString[n] ;
char receivedChar;
bool isSerial2Available = true;  // flag variable to track Serial2 availability

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  startMillis = millis();  // initial start time
  currentMillis = startMillis;
}

void loop() {
  int i = 0;

  if (currentMillis - startMillis >= period) { // Reset the start time
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
   startMillis = currentMillis; // Update the start time after reading

    if (isSerial2Available) {
      Serial.println(myString);
      if (myString[0] != '\0') {
        Serial.println("RECEIVED !");
        Serial2.write("Confirm !");
        for (int j = 0; j < n; j++) {
          myString[j] = '\0';
        }
      }
    } else {
      Serial.println("Serial2 is not available!");
      isSerial2Available = true;  // Reset the flag variable
    }
  }

  currentMillis = millis();
}
