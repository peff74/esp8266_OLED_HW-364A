#include <U8g2lib.h>

#define OLED_RESET     U8X8_PIN_NONE // Reset pin (not used)
#define OLED_SDA 14                  // D6
#define OLED_SCL 12                  // D5

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, OLED_RESET, OLED_SCL, OLED_SDA);

int c = 0;

void handle_oled(int c) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 10, "Display is working!");
  u8g2.drawStr(0, 30, "Have fun with it");
  char buffer[20];
  snprintf(buffer, sizeof(buffer), "Uptime: %ds", c);
  u8g2.drawStr(0, 50, buffer);
  u8g2.sendBuffer();
}

void setup() {
  u8g2.begin();
}

void loop() {
  handle_oled(c);
  c++;
  delay(1000);
}
