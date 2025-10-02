// This is based on the details outlined on this page:
// https://www.espboards.dev/esp32/esp32-s3-super-mini/

#ifndef ESP32S3_SUPERMINI_PINOUT_H
#define ESP32S3_SUPERMINI_PINOUT_H

#include <Arduino.h>

// ============================================================================
// 🚨 RESTRICTED PINS - USE WITH CAUTION!
// ============================================================================

// 🛠️ Strapping Pins (Critical for boot behavior)
#define PIN_GPIO3     3   // 🛠️ Sampled at reset for JTAG interface selection
#define PIN_GPIO45    45  // 🛠️ Determines flash/PSRAM power voltage at boot
#define PIN_GPIO46    46  // 🛠️ Input-only, defines boot mode with GPIO0

// ⚡ Flash/PSRAM Pins (Critical for system operation)
#define PIN_FSPIHD    9  // ⚡ Connected to external flash (data/hold signal)
#define PIN_FSPICS0   10 // ⚡ Flash chip select - REQUIRED for flash access
#define PIN_FSPID     11 // ⚡ Flash data line - do not use when flash/PSRAM active
#define PIN_FSPICLK   12 // ⚡ Flash clock - CRITICAL, reserve for memory
#define PIN_FSPIQ     13 // ⚡ Flash data line - not available when flash active
#define PIN_FSPIWP    14 // ⚡ Flash write-protect - reserve for flash operations

#define PIN_FSPIHD2   33 // ⚡ Internal flash hold pin (alternative)
#define PIN_FSPICS02  34 // ⚡ Internal flash chip select

// PSRAM Specific Pins (Octal PSRAM modules)
#define PIN_PSRAM_D0  35 // ⚡ PSRAM data line - reserved for memory
#define PIN_PSRAM_CLK 36 // ⚡ PSRAM clock - dedicated to memory interface
#define PIN_PSRAM_DQS 37 // ⚡ PSRAM DQS signal - do not repurpose
#define PIN_FSPIWP2   38 // ⚡ Flash write-protect (alternative)

// 🪛 JTAG Debugging Pins
#define PIN_MTCK  39 // 🪛 Default JTAG TCK - interferes with debugging if used
#define PIN_MTDO  40 // 🪛 Default JTAG TDO - interferes with debugging if used
#define PIN_MTDI  41 // 🪛 Default JTAG TDI - interferes with debugging if used

// ⚡ Octal SPI Pins (High-speed variants only)
#define PIN_SPICLK_P  47 // ⚡ Octal SPI differential clock+ (1.8V)
#define PIN_SPICLK_N  48 // ⚡ Octal SPI differential clock- (1.8V)

// ============================================================================
// ✅ SAFE GPIO PINS (Generally available for use)
// ============================================================================

// Digital I/O Pins (Safe to use)
#define PIN_GPIO0    0   // ✅ Note: Boot mode pin, but can be used after boot
#define PIN_GPIO1    1   // ✅ 
#define PIN_GPIO2    2   // ✅ 
#define PIN_GPIO4    4   // ✅
#define PIN_GPIO5    5   // ✅
#define PIN_GPIO6    6   // ✅
#define PIN_GPIO7    7   // ✅
#define PIN_GPIO8    8   // ✅
#define PIN_GPIO15   15  // ✅
#define PIN_GPIO16   16  // ✅
#define PIN_GPIO17   17  // ✅
#define PIN_GPIO18   18  // ✅
#define PIN_GPIO19   19  // ✅
#define PIN_GPIO20   20  // ✅
#define PIN_GPIO21   21  // ✅

// Additional GPIO Pins
#define PIN_GPIO26   26  // ✅
#define PIN_GPIO27   27  // ✅
#define PIN_GPIO28   28  // ✅
#define PIN_GPIO29   29  // ✅
#define PIN_GPIO30   30  // ✅
#define PIN_GPIO31   31  // ✅
#define PIN_GPIO32   32  // ✅
#define PIN_GPIO42   42  // ✅
#define PIN_GPIO43   43  // ✅
#define PIN_GPIO44   44  // ✅


// ============================================================================
// 📊 PIN CATEGORIES (Organized by function)
// ============================================================================

// SPI Pins (when not conflicting with flash)
#define PIN_SPI_SCK   12  // ⚠️ Conflicts with FSPICLK!
#define PIN_SPI_MISO  13  // ⚠️ Conflicts with FSPIQ!
#define PIN_SPI_MOSI  11  // ⚠️ Conflicts with FSPID!
#define PIN_SPI_SS    10  // ⚠️ Conflicts with FSPICS0!

// Safe SPI Pins (use these instead for peripheral SPI)
#define PIN_SAFE_SPI_SCK   PIN_GPIO17
#define PIN_SAFE_SPI_MISO  PIN_GPIO18  
#define PIN_SAFE_SPI_MOSI  PIN_GPIO16
#define PIN_SAFE_SPI_SS    PIN_GPIO15

// I2C Pins (typical assignments)
#define PIN_I2C_SDA   PIN_GPIO8
#define PIN_I2C_SCL   PIN_GPIO9   // ⚠️ Note: GPIO9 is FSPIHD!

// Safe I2C Pins (alternative)
#define PIN_SAFE_I2C_SDA   PIN_GPIO42
#define PIN_SAFE_I2C_SCL   PIN_GPIO43

// UART Pins
#define PIN_UART0_TX  PIN_GPIO43
#define PIN_UART0_RX  PIN_GPIO44
#define PIN_UART1_TX  PIN_GPIO17
#define PIN_UART1_RX  PIN_GPIO18

// ============================================================================
// 🎯 SPECIFIC BOARD PINOUT (ESP32-S3 SuperMini)
// ============================================================================

// Display Pins
#define PIN_DISPLAY_CS   10    // ⚠️ FSPICS0 - use with caution!
#define PIN_DISPLAY_DC   PIN_GPIO9     // ⚠️ FSPIHD - use with caution!
#define PIN_DISPLAY_RST  PIN_GPIO8     // ✅ Safe
#define PIN_DISPLAY_BUSY PIN_GPIO12    // ⚠️ FSPICLK - use with caution!

// LED Pins
#define PIN_LED_WS2812   PIN_GPIO48    // ⚠️ SPICLK_N - Octal SPI variant only
#define PIN_LED_BLUE     PIN_GPIO2     // ✅ Safe

// Safe Display Pins (alternative assignments)
#define PIN_SAFE_DISPLAY_CS   PIN_GPIO15
#define PIN_SAFE_DISPLAY_DC   PIN_GPIO16  
#define PIN_SAFE_DISPLAY_RST  PIN_GPIO17
#define PIN_SAFE_DISPLAY_BUSY PIN_GPIO18

// ============================================================================
// 🔧 UTILITY FUNCTIONS
// ============================================================================

// Check if pin is safe for general use
bool isPinSafe(int pin);

// Get pin type description
const char* getPinType(int pin);

// Initialize safe pins only
void initializeSafePins();

// Warning message for restricted pins
void printPinWarning(int pin);

// Get array of safe pins (for iteration)
const int* getSafePinsArray();
int getSafePinsCount();

// Quick safety check with return code
int validatePin(int pin, const char* purpose = nullptr);

#endif