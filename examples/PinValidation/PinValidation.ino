#include <ESP32S3_SUPERMINI_PINOUT.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("ESP32-S3 Pin Validation");
  Serial.println("=======================");
  
  // Test all pins
  for (int pin = 0; pin <= 48; pin++) {
    Serial.print("GPIO");
    Serial.print(pin);
    Serial.print(": ");
    Serial.print(getPinType(pin));
    
    if (isPinSafe(pin)) {
      Serial.println(" ✅ SAFE");
    } else {
      Serial.println(" ❌ RESTRICTED");
    }
  }
}

void loop() {
  // nothing to do here
}