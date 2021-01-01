#include <Arduino.h>
#include <screen.h>
#include <bmps/elite_dangerous.h>

#include <Keypad.h>

#define KEYPAD_ROW_COUNT (4)
#define KEYPAD_COL_COUNT (3)

const uint8_t KEYPAD_ROWS[] = {4,5,6,7};
const uint8_t KEYPAD_COLS[] = {8,9,10};
char keys[] = {'A', 'B', 'C',
			   '1', '2', '3',
			   '4', '5', '6',
			   '7', '8', '9'
			};


Keypad kpd = Keypad( keys, KEYPAD_ROWS, KEYPAD_COLS, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT);

Screen screen;
uint32_t time_stamp = 0;

void setup()
{
	/* The space after dangrous is to make the scrolling look better */
	screen.begin("Elite Dangerous", ELITE_DANGEROUS_BMP);
}

void loop()
{	
	if (kpd.check_keypad())
    {
		byte pin = kpd.get_pressed_pins()[0];
		screen.set_title(String((kpd[pin])));
    }
	if ((millis() - time_stamp) > 200)
	{
		time_stamp = millis();
		screen.scroll_title();
	}
}