#include "ESP32S3_SUPERMINI_PINOUT.h"

// Array of unsafe pins
const int unsafePins[] = {3, 9, 10, 11, 12, 13, 14, 33, 34, 35, 36, 37, 38, 39, 40, 41, 45, 46, 47, 48};
const int unsafePinsCount = sizeof(unsafePins) / sizeof(unsafePins[0]);

// Array of safe pins
const int safePins[] = {0, 1, 2, 4, 5, 6, 7, 8, 15, 16, 17, 18, 19, 20, 21, 26, 27, 28, 29, 30, 31, 32, 42, 43, 44};
const int safePinsCount = sizeof(safePins) / sizeof(safePins[0]);

bool isPinSafe(int pin) {
  for (int i = 0; i < unsafePinsCount; i++) {
    if (pin == unsafePins[i]) {
      return false;
    }
  }
  return true;
}

const char* getPinType(int pin) {
  switch(pin) {
    case 3: case 45: case 46: return "Strapping Pin";
    case 9: case 10: case 11: case 12: case 13: case 14: 
    case 33: case 34: case 35: case 36: case 37: case 38:
    case 47: case 48: return "Flash/PSRAM Pin";
    case 39: case 40: case 41: return "JTAG Debug Pin";
    default: return "General GPIO";
  }
}

void initializeSafePins() {
  Serial.println("ESP32-S3 SuperMini: Initializing safe GPIO pins as inputs...");
  for (int i = 0; i < safePinsCount; i++) {
    pinMode(safePins[i], INPUT);
  }
  Serial.println("ESP32-S3 SuperMini: Safe pins initialized");
}

void printPinWarning(int pin) {
  if (!isPinSafe(pin)) {
    Serial.print("⚠️ ESP32-S3 SuperMini WARNING: Pin GPIO");
    Serial.print(pin);
    Serial.print(" is a ");
    Serial.print(getPinType(pin));
    Serial.println(" - use may disrupt system operation!");
  }
}

const int* getSafePinsArray() {
  return safePins;
}

int getSafePinsCount() {
  return safePinsCount;
}

int validatePin(int pin, const char* purpose) {
  if (purpose != nullptr) {
    Serial.print("ESP32-S3 SuperMini: Validating pin ");
    Serial.print(pin);
    Serial.print(" for ");
    Serial.println(purpose);
  }
  
  if (!isPinSafe(pin)) {
    printPinWarning(pin);
    return -1; // Error code for unsafe pin
  }
  
  return 0; // Success
}