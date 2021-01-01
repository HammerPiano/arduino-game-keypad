/**
 * This file is originaly from the Keypad library
 * https://github.com/Chris--A/Keypad
 * 
 * Modified to serve this project
 */

#pragma once


typedef struct {
    byte rows;
    byte columns;
} KeypadSize;


/**
 * @brief This class repersents a keypad
 * 
 * 
 * Usage:	call check keypad, if any keys are pressed, it returns true
 * 			the number of pins pressed is in get_pressed_pins_count, and the list is in get_pressed_pins
 */
class Keypad {
public:

	Keypad(char * userKeymap, const byte * row_pins, const byte * col_pins, byte numRows, byte numCols) : _row_pins(row_pins), _coloumn_pins(col_pins)
	{
		sizeKpd.rows = numRows;
		sizeKpd.columns = numCols;
		pressed_pins = new byte[numRows * numCols];
		pressed_pins_count = 0;

		// Init pins
		for (byte i=0; i<sizeKpd.rows; i++)
		{
			pinMode(_row_pins[i],INPUT_PULLUP);
		}

		for (byte i = 0; i < sizeKpd.columns; i++)
		{
			pinMode(_coloumn_pins[i], INPUT);
		}
		

		begin(userKeymap);

		setDebounceTime(10);
		startTime = millis();
	}

	unsigned long holdTimer;

	// Populate the key list.
	bool check_keypad()
	{
		bool keyActivity = false;

		// Limit how often the keypad is scanned. This makes the loop() run 10 times as fast.
		if ( (millis()-startTime) > debounceTime )
		{
			scanKeys();
			keyActivity = get_pressed_pins_count() > 0;
			startTime = millis();
		}

		return keyActivity;
	}
	void begin(char *userKeymap)
	{
    	keymap = userKeymap;
	}

	void setDebounceTime(uint16_t debounce)
	{
		// Recommenced is atleast 10ms, to allow the button to stabilize
		debounceTime = debounce;
	}

	byte * get_pressed_pins()
	{
		return pressed_pins;
	}

	byte get_pressed_pins_count()
	{
		return pressed_pins_count;
	}

	char operator[](byte pin_number)
	{
		return keymap[pin_number];
	}

private:
	unsigned long startTime;
	char * keymap;
    const byte *_row_pins;
    const byte *_coloumn_pins;
	KeypadSize sizeKpd;
	uint16_t debounceTime;

	byte * pressed_pins;
	byte pressed_pins_count;

	void scanKeys()
	{
		pressed_pins_count = 0;
		// bitMap stores ALL the keys that are being pressed.
		for (byte c=0; c<sizeKpd.columns; c++)
		{
			pinMode(_coloumn_pins[c],OUTPUT);
			digitalWrite(_coloumn_pins[c], LOW);	// Begin column pulse output.
			for (byte r=0; r<sizeKpd.rows; r++)
			{
				// keypress is active low so invert to high.
				if (digitalRead(_row_pins[r]) == LOW) 
				{
					/* Values, 2d array, with rows number of arraies, each colum number of cells */
					pressed_pins[pressed_pins_count] = r * sizeKpd.columns + c; 
					pressed_pins_count++;
				}
			}
			// Set pin to high impedance input. Effectively ends column pulse.
			digitalWrite(_coloumn_pins[c],HIGH);
			pinMode(_coloumn_pins[c],INPUT);
		}
	}

	
};