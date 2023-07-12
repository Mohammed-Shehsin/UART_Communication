// // Slave
// // used RP2040-zero
// // TX pin GPI08
// // RX pin GPI09
// //#include <vector>
// #include<string>
// unsigned long startMillis;  // some global variables available anywhere in the program
// unsigned long currentMillis;
// const unsigned long period = 1000;
// const int n = 50;
// char myString[n] ;
// char receivedChar;
// bool isSerial2Available = true;  // flag variable to track Serial2 availability

// std::vector<std::string> splitBySpace(const char* charArray) {
//     std::vector<std::string> substrings;
//     std::string currentSubstring;
//     int length = strlen(charArray);

//     for (int i = 0; i < length; i++) {
//         if (charArray[i] == ' ') {
//             if (!currentSubstring.empty()) {
//                 substrings.push_back(currentSubstring);
//                 currentSubstring.clear();
//             }
//         } else {
//             currentSubstring += charArray[i];
//         }
//     }

//     if (!currentSubstring.empty()) {
//         substrings.push_back(currentSubstring);
//     }

//     return substrings;
// }
// bool isInteger(const std::string& str) {
//     if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
//         return false;

//     char* endPtr;
//     std::strtol(str.c_str(), &endPtr, 10);

//     return (*endPtr == '\0');
// }

// bool isFloat(const std::string& str) {
//     if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+') && (str[0] != '.')))
//         return false;

//     char* endPtr;
//     std::strtof(str.c_str(), &endPtr);

//     return (*endPtr == '\0');
// }

// bool isBoolean(const std::string& str) {
//     //  std::string lowercaseStr;
//     // lowercaseStr.reserve(str.length());
//     // for (size_t i = 0; i < str.length(); ++i) {
//     //     lowercaseStr.push_back(tolower(str[i]));
//     // }
//     return (str == "true" || str == "false");
// }

// void convertToInteger(const std::string& str) {
//     int value = std::stoi(str);
//     Serial.println("Integer :");
//     Serial.println(value);
// }

// void convertToFloat(const std::string& str) {
//     float value = std::stof(str);
//      Serial.println("Float :");
//      Serial.println(value);
// }

// void convertToBoolean(const std::string& str) {
//     bool value = (str == "true");
//   Serial.println("Boolean :");
//   Serial.println(value);
// }

// void convertToString(const std::string& str) {
//    Serial.println("String :");
//    Serial.println(str.c_str());
// }


// void setup() {
//   Serial.begin(115200);
//   Serial2.begin(115200);
//   startMillis = millis();  // initial start time
//   currentMillis = startMillis;
// }

// void loop() {
//   int i = 0;

//   if (currentMillis - startMillis >= period) { // Reset the start time
//     while (i < n) {
//       if (Serial2.available()) {
//        // startMillis = currentMillis;
//         receivedChar = Serial2.read();

//         if (receivedChar == ';') {
//           myString[i] = '\0';
//           break;
//         }

//         myString[i] = receivedChar;
//         i++;
//       } else {
//         isSerial2Available = false;
//         break;
//       }
//     }
//    startMillis = currentMillis; // Update the start time after reading

   

//     if (isSerial2Available) {

//      std::vector<std::string> substrings = splitBySpace(myString);
//      Serial.println("------------------------------------------------------------");
//          for (const auto& substring : substrings) {
//         if (isInteger(substring)) {
//             convertToInteger(substring);
//         } else if (isFloat(substring)) {
//             convertToFloat(substring);
//         } else if (isBoolean(substring)) {
//             convertToBoolean(substring);
//         } else {
//             convertToString(substring);
//         }
//     }
//      Serial.println();
//      Serial.println(myString);
//      Serial.println("-------------------------------------------------------------");
//       if (myString[0] != '\0') {
//         Serial.println("RECEIVED !");
//         Serial2.write("Confirm !");
//         for (int j = 0; j < n; j++) {
//           myString[j] = '\0';
//         }
//       }
//     } else {
//       //Serial.println("Serial2 is not available!");
//       isSerial2Available = true;  // Reset the flag variable
//     }
//   }

//   currentMillis = millis();
// }





#include <vector>
#include <string>

struct MyStructure {
  std::string str;
  bool boolean;
 // int timelap;
  int integer;
  float floating;
};

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 1000;
const int n = 50;
const int structSize = 4;
char myString[n];
char receivedChar;
bool isSerial2Available = true;  // flag variable to track Serial2 availability

std::vector<std::string> splitBySpace(const char* charArray) {
  std::vector<std::string> substrings;
  std::string currentSubstring;
  int length = strlen(charArray);

  for (int i = 0; i < length; i++) {
    if (charArray[i] == ' ') {
      if (!currentSubstring.empty()) {
        substrings.push_back(currentSubstring);
        currentSubstring.clear();
      }
    } else {
      currentSubstring += charArray[i];
    }
  }

  if (!currentSubstring.empty()) {
    substrings.push_back(currentSubstring);
  }

  return substrings;
}

bool isInteger(const std::string& str) {
  if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+')))
    return false;

  char* endPtr;
  std::strtol(str.c_str(), &endPtr, 10);

  return (*endPtr == '\0');
}

bool isFloat(const std::string& str) {
  if (str.empty() || ((!isdigit(str[0])) && (str[0] != '-') && (str[0] != '+') && (str[0] != '.')))
    return false;

  char* endPtr;
  std::strtof(str.c_str(), &endPtr);

  return (*endPtr == '\0');
}

bool isBoolean(const std::string& str) {
  return (str == "true" || str == "false");
}

void convertToInteger(const std::string& str, int& value) {
  value = std::stoi(str);
}

void convertToFloat(const std::string& str, float& value) {
  value = std::stof(str);
}

void convertToBoolean(const std::string& str, bool& value) {
  value = (str == "true");
}

void convertToString(const std::string& str, std::string& value) {
  value = str;
}

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial2.setTimeout(300);
  startMillis = millis();  // initial start time
  currentMillis = startMillis;
}

void loop() {
  int i = 0;

  if (currentMillis - startMillis >= period) { // Reset the start time
    while (i < n) {
      if (Serial2.available()) {
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
      std::vector<std::string> substrings = splitBySpace(myString);

      if (substrings.size() == structSize) {
        MyStructure receivedData;
        convertToString(substrings[0], receivedData.str);
        convertToBoolean(substrings[1], receivedData.boolean);
        // convertToInteger(substrings[2],receivedData.timelap);
        // convertToInteger(substrings[3], receivedData.integer);
        // convertToFloat(substrings[4], receivedData.floating);
        convertToInteger(substrings[2], receivedData.integer);
        convertToFloat(substrings[3], receivedData.floating);
        

        // Print the received structure
        Serial.println("-----------------------------------------------------------------------------------------");
        Serial.println("Received Structure:");
        Serial.print("String: ");
        Serial.println(receivedData.str.c_str());
        Serial.print("Boolean: ");
        Serial.println(receivedData.boolean ? "true" : "false");
        // Serial.print("Timeslap: ");
        // Serial.println(receivedData.timelap);
        Serial.print("Integer: ");
        Serial.println(receivedData.integer);
        Serial.print("Float: ");
        Serial.println(receivedData.floating);
        Serial.println();
        
        // Debugging 
        Serial.print("Received String:");
        Serial.println(myString);
        Serial.print("Number of Substrings: ");
        Serial.println(substrings.size());
        Serial.println();
      
        Serial.println("-----------------------------------------------------------------------------------------");
        // Send confirmation
        Serial2.write("Confirm !");
        
      } else {
        Serial.println("------------------------------Invalid structure received!-------------------------------");
        Serial.println(myString);
      }

      // Clear the received string buffer
      for (int j = 0; j < n; j++) {
        myString[j] = '\0';
      }
    } else {
      isSerial2Available = true;  // Reset the flag variable
    }
  }

  currentMillis = millis();
}

// char myString[10];
// void setup(){
//   Serial.begin(115200);
//   Serial2.begin(115200);

// }
// void loop() {
//   Serial2.readBytes(myString,6);
//   Serial.print(myString);
//  // Serial.println(" RECIEVED !");
//   delay(1000);
// }
