#include <Arduino.h>
#include <screen.h>
#include <profiles/elite_dangerous.h>

#include <Keypad.h>

#define KEYPAD_ROW_COUNT (4)
#define KEYPAD_COL_COUNT (3)

const uint8_t KEYPAD_ROWS[] = {4,5,6,7};
const uint8_t KEYPAD_COLS[] = {8,9,10};
String keys[] = {"Lorem", "Ipsum", "Test", "Foo", "Bar", "Baz", "Ahhh", "Arduino", "STM32", "One", "Two", "Three"};

auto kpd = Keypad<String>( keys, KEYPAD_ROWS, KEYPAD_COLS, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT);

Screen screen;
uint32_t time_stamp = 0;

void setup()
{
	/* The space after dangrous is to make the scrolling look better */
	screen.begin(ELITE_DANGEROUS_PROFILE.title, ELITE_DANGEROUS_PROFILE.pixels);
}

void loop()
{	
	if (kpd.getKeys())
    {
		screen.set_title(kpd[kpd.get_pressed_pins()[0]]);
    }
	if ((millis() - time_stamp) > 200)
	{
		time_stamp = millis();
		screen.scroll_title();
	}
}