#include <ESP32S3_SUPERMINI_PINOUT.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("ESP32-S3 SuperMini Safe Pin Usage Example");
  Serial.println("=========================================");
  
  // Initialize safe pins
  supermini_initializeSafePins();
  
  // Test various pin assignments with validation
  int testPins[] = {
    SUPERMINI_LED_BLUE, 
    SUPERMINI_DISPLAY_CS, 
    SUPERMINI_SAFE_DISPLAY_CS, 
    SUPERMINI_FSPICLK
  };
  
  const char* purposes[] = {
    "Blue LED",
    "Display CS (unsafe)",
    "Display CS (safe alternative)", 
    "Flash Clock (CRITICAL)"
  };
  
  for (int i = 0; i < 4; i++) {
    Serial.println();
    int result = supermini_validatePin(testPins[i], purposes[i]);
    if (result == 0) {
      Serial.println("  -> Pin is safe to use");
    } else {
      Serial.println("  -> PIN UNSAFE - consider alternatives");
    }
  }
  
  // Use safe pins for demonstration
  pinMode(SUPERMINI_LED_BLUE, OUTPUT);
  digitalWrite(SUPERMINI_LED_BLUE, HIGH);
  
  Serial.println("\nBlue LED activated on safe pin GPIO2");
}

void loop() {
  // Blink blue LED using safe pin
  digitalWrite(SUPERMINI_LED_BLUE, !digitalRead(SUPERMINI_LED_BLUE));
  delay(1000);
}