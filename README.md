# HW-364A 
![AHT20_BMP280 logo](https://github.com/peff74/esp8266_OLED_HW-364A/blob/main/front_1.jpg)
![AHT20_BMP280 logo](https://github.com/peff74/esp8266_OLED_HW-364A/blob/main/back.jpg)


- The HM605 is a very practical and cheap ESP8266 with 0.96 Inch OLED Display.
- It is sold on all known platforms.
- Some dealers provide incorrect technical data, which sometimes makes it difficult to get it up and running...



## Technical specs
- SDA is D6 / GPIO14
- SCL is D5 / GPIO12
- Address is 0x3C


## Code
```
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1   // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // If not work please scan the bus
#define OLED_SDA 14         // D6
#define OLED_SCL 12         // D5

Adafruit_SSD1306 *display;

int c = 0; 


void handle_oled(int c) {
  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(SSD1306_WHITE);
  display->setCursor(0, 0);
  display->println("Display is working!");
  display->println("");
  display->println("");
  display->println("Have fun with it");
  display->println("");
  display->println("");
  display->print("Uptime: ");
  display->print(c);
  display->println("s");
  display->display();
}


void setup() {
  display = new Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
  Wire.begin(OLED_SDA, OLED_SCL);
  display->begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
}

void loop() {
  handle_oled(c);
  c++;
  delay(1000);
}
```
   ![AHT20_BMP280 logo](https://github.com/peff74/esp8266_OLED_HW-364A/blob/main/front_2.jpg)
