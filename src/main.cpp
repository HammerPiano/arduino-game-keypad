#include <Arduino.h>
#include <screen.h>
#include <bmps/elite_dangerous.h>

#include <Joystick.h>
#include <Keypad.h>

#define KEYPAD_ROW_COUNT (4)
#define KEYPAD_COL_COUNT (3)

#define SCREEN_UPDATE_INTERVAL (200)
#define BUTTON_RELEASE_INTERVAL (1000)

#define NO_BUTTON (0xFF)

const uint8_t KEYPAD_ROWS[] = {4,5,6,7};
const uint8_t KEYPAD_COLS[] = {8,9,10};
char keys[] = {'A', 'B', 'C',
			   '1', '2', '3',
			   '4', '5', '6',
			   '7', '8', '9'
			};


Keypad kpd = Keypad( keys, KEYPAD_ROWS, KEYPAD_COLS, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT);
// Oh god I hate this soo much, but I need only buttons not a whole plane
Joystick_ joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK, 9, 0, false, false, false, false, false, false, false, false, false, false, false);
Screen screen;
uint32_t time_stamp = 0, button_press_time = 0;
byte pressed_button = NO_BUTTON;

void setup()
{
	/* The space after dangrous is to make the scrolling look better */
	//screen.begin("Elite Dangerous", ELITE_DANGEROUS_BMP);
	joystick.begin();
}

void loop()
{	
	if (kpd.check_keypad() && pressed_button == NO_BUTTON)
    {
		byte pin = kpd.get_pressed_pins()[0];
		byte pin_value = kpd[pin] - '1';
		//screen.set_title(String((kpd[pin])));
		if (pin_value <= 9)
		{
			joystick.pressButton(pin_value);
			pressed_button = pin_value;
			button_press_time = millis();
		}

    }
	if ((millis() - time_stamp) > 200)
	{
		time_stamp = millis();
		//screen.scroll_title();
	}

	if (pressed_button != NO_BUTTON && ((millis() - button_press_time) >= BUTTON_RELEASE_INTERVAL))
	{
		joystick.releaseButton(pressed_button);
		pressed_button = NO_BUTTON;
	}
}