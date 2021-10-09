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

#define CONTROL_BUTTON_MINIMUM ('A')
#define COMMAND_BUTTON_MINIMUM ('1')

const uint8_t KEYPAD_ROWS[] = {4,5,6,7};
const uint8_t KEYPAD_COLS[] = {8,9,10};
char keys[] = {'A', 'B', 'C',
			   '1', '2', '3',
			   '4', '5', '6',
			   '7', '8', '9'
			};


Keypad kpd = Keypad( keys, KEYPAD_ROWS, KEYPAD_COLS, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT);
// Oh god I hate this soo much, but I need only buttons not a whole plane
Joystick_ joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_JOYSTICK, 12, 0, false, false, false, false, false, false, false, false, false, false, false);
Screen screen;
uint32_t time_stamp = 0, button_press_time = 0;
byte current_command_button = NO_BUTTON;
byte current_control_button = 0;

void setup()
{
	/* The space after dangrous is to make the scrolling look better */
	//screen.begin("Elite Dangerous", ELITE_DANGEROUS_BMP);

	// Init control buttons
	current_control_button = 0;

	// Start USB sub-process
	joystick.begin();
}

void loop()
{	
	if (kpd.check_keypad() && current_command_button == NO_BUTTON)
    {
		byte* pressed_buttons = kpd.get_pressed_pins();
		byte count = kpd.get_pressed_pins_count();
		for (byte i = 0; i < count; i++)
		{
			if (kpd[pressed_buttons[i]] >= CONTROL_BUTTON_MINIMUM)
			{
				current_control_button = pressed_buttons[i];
			}
			else
			{
				current_command_button = pressed_buttons[i];
			}
		}
		//screen.set_title(String((kpd[pin])));
		if (current_command_button != NO_BUTTON)
		{
			button_press_time = millis();
			joystick.pressButton(current_control_button);
			delay(20);
			joystick.pressButton(current_command_button);
		}
		
    }
	if ((millis() - time_stamp) > 200)
	{
		time_stamp = millis();
		//screen.scroll_title();
	}

	if (current_command_button != NO_BUTTON && ((millis() - button_press_time) >= BUTTON_RELEASE_INTERVAL))
	{
		joystick.releaseButton(current_command_button);
		joystick.releaseButton(current_control_button);
		current_command_button = NO_BUTTON;
	}
}