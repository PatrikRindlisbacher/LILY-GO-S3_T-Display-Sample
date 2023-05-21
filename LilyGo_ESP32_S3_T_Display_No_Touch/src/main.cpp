#include <Arduino.h>

//************************ LILYGO_T_DISPLAY_S3_NO_TOUCH_BLANK ***************** 
// Platine:     LillyGo T-Display-S3
// Prozessor:   ESP32-S3R8 16MB Flash 8MB PSRAM  STEMMA-QT-Qwiic-Stecker
// TFT-Treiber: ST7789 8 Bit Parallel 320 x 170 Pixel

#include "lgfx_config.h"

static LGFX lcd;  
static LGFX_Sprite tftSprite(&lcd);                                             // Display Object LGFX_Sprite used as lcd

void setup() {                                                                  // SETUP
  lcd.init();
  tftSprite.setRotation(1);                                                     // LCD Rotation 1=90Grad drehen
  tftSprite.setColorDepth(8);                                                   // Color Depth
  tftSprite.createSprite(170, 320);                                             // !! Sprite ??x?? Auflösung
}

void loop() {                                                                   // Loop
  tftSprite.setFont(&FreeSans18pt7b);                                           // Font
  tftSprite.clear();
  tftSprite.setCursor(0,0);
  tftSprite.drawCentreString("grbl-io", 160, 85);
  tftSprite.pushSprite(0, 0); 
  delay(2000);
  tftSprite.clear();
  tftSprite.pushSprite(0, 0); 
  delay(500);
}
