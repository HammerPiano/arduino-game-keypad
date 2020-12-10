#include <Arduino.h>
#include <screen.h>
#include <profiles/elite_dangerous.h>
#include <bmps/elite_logo.h>

#include <Keypad.h>

#define KEYPAD_ROW_COUNT (4)
#define KEYPAD_COL_COUNT (3)

const uint8_t KEYPAD_ROWS[] = {4,5,6,7};
const uint8_t KEYPAD_COLS[] = {8,9,10};
char keys[KEYPAD_ROW_COUNT][KEYPAD_COL_COUNT] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};

Keypad kpd = Keypad( makeKeymap(keys), KEYPAD_ROWS, KEYPAD_COLS, KEYPAD_ROW_COUNT, KEYPAD_COL_COUNT);

Screen screen;
uint32_t time_stamp = 0;

void setup()
{
	/* The space after dangrous is to make the scrolling look better */
	screen.begin(ELITE_DANGEROUS_PROFILE.title, ELITE_DANGEROUS_PROFILE.pixels);
	//screen.begin(" ", BMP_ELITE_LOGO);
}

void loop()
{	
	if (kpd.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
					screen.set_title(String(kpd.key[i].kchar));
                break;
                }
            }
        }
    }
	if ((millis() - time_stamp) > 200)
	{
		time_stamp = millis();
		screen.scroll_title();
	}
}