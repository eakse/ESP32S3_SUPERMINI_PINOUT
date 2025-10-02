# ESP32-S3 SuperMini Pinout

Pin definitions and safety validation for ESP32-S3 SuperMini boards, specifically the one linked below:  
https://www.espboards.dev/esp32/esp32-s3-super-mini

## Quick Use

```cpp
#include <ESP32S3_SUPERMINI_PINOUT.h>

void setup() {
  // Safe pins
  pinMode(PIN_GPIO4, OUTPUT);

  // Check if pin is safe
  if(supermini_isPinSafe(10)) {
    // Use pin 10
  }
}