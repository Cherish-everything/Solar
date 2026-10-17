#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

// --- PIN DEFINITIONS (Moved outside so the whole sketch can see them) ---
#define TFT_SCLK 10 // labeled SCL on the screen
#define TFT_MOSI 11 // labeled SDA on the screen
#define TFT_RST  9
#define TFT_DC   5
#define TFT_CS   6
#define TFT_BL   7

// Instantiate tft globally so setup() and loop() can both access it
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(){
  Serial.begin(115200);

  // Turn on backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.init(76, 284);          // Our panel size (portrait)
  tft.invertDisplay(false);   // Invert the colors if needed
  tft.setRotation(1);         // Landscape mode
  tft.fillScreen(ST77XX_BLACK); // clear the screen
  Serial.println("TFT Initialized!");

  tft.setTextSize(1);
  tft.setTextColor(ST77XX_WHITE, ST77XX_BLACK); // Fixed color macro
  tft.setCursor(120, 18);
  tft.print("AM");
}

void loop(){
  int currentHour = 7;
  int currentMinute = 0; // LIVE TIME SYSTEM LATER

  updateClock(currentHour, currentMinute);
  
  delay(1000); // Added delay so it updates cleanly every second
}

void updateClock(int hour, int minute){
  tft.fillRect(10, 10, 105, 30, ST77XX_BLACK);
  tft.setTextColor(ST77XX_GREEN, ST77XX_BLACK);
  tft.setTextSize(3);
  tft.setCursor(10, 10);

  if (hour < 10) tft.print("0");
  tft.print(hour);
  tft.print(":");
  if (minute < 10) tft.print("0"); // Added leading zero
  tft.print(minute);
}