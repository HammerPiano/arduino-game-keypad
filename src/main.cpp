#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeMono9pt7b.h>
#include <Adafruit_SSD1306.h>
#include "bmps/elite_logo.h"
#define SCREEN_BLUE_SECTION (16)
#define SCREEN_YELLOW_SECTION (48)
#define SCREEN_WIDTH (128) // OLED display width, in pixels
#define SCREEN_HEIGHT (SCREEN_BLUE_SECTION + SCREEN_YELLOW_SECTION) // OLED display height, in pixels

// For somereason, my address select in the module is soldered incorrectly
#define DISPLAY_ADDRESS (0x3C)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void test_print(uint8_t offset)
{
	display.clearDisplay();
	display.setFont(&FreeMono9pt7b);
	display.setTextColor(SSD1306_WHITE); // Draw white text
	display.setCursor(0, offset);     // Start at top-left corner
	display.print("Lorem Ipsum");
	display.drawLine(0, 15, 126, 15, WHITE);// "underline"
	display.display();
}

void setup()
{
	if(!display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS))
	{ // Address 0x3D for 128x64
		for(;;); // Don't proceed, loop forever
	}
	test_print(12);
	display.drawBitmap(40, 16, elite_logo, 48, 42, WHITE);
	display.display();
}

void loop()
{

}