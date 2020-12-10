#include <Arduino.h>
#include <screen.h>
#include <bmps/elite_logo.h>

Screen screen;

void setup()
{
	/* The space after dangrous is to make the scrolling look better */
	screen.begin("Elite Dangerous ", BMP_ELITE_LOGO);
}

void loop()
{
	screen.scroll_title();
	delay(200);
}