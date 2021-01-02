#pragma once

#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeMono9pt7b.h>

#define SCREEN_WIDTH (128)
#define SCREEN_HEIGHT (64)

/*
 ? My version of SSD1306 screen is divided to 2 parts, top quarter has yellow pixels, and the rest has cyan pixels
 ? These definitions are the Y start and end of each section, since they are dividing the rows
 ? Yellow section is used for titles, texts...	- 128x16
 ? Cyan section is for pictures					- 128x48
*/
#define SCREEN_YELLOW_START (0)
#define SCREEN_YELLOW_END (15)
#define SCREEN_BLUE_START (16)
#define SCREEN_BLUE_END (63)

#define SCREEN_BLUE_HEIGHT (SCREEN_HEIGHT - SCREEN_BLUE_START)

// ? floor((SCREEN_WIDTH) / character width of the font = 11
// ? A good aproximation for the mono-space font
#define SCREEN_TITLE_LENGTH (11)
#define SCREEN_TITLE_X_OFFSET (0)
#define SCREEN_TITLE_Y_OFFSET (12)
// For somereason, my address select in the module is soldered incorrectly
#define SCREEN_ADDRESS (0x3C)


class Screen
{
public:
	Screen() : _display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire),
															_title(""), _bit_map(nullptr)
	{
		
	}
	
	void begin(const String & title, const uint8_t * bit_map)
	{
		
		_display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
		_display.display();
		delay(2000);// Give Adafruit some time on screen for their lovely job
		_display.setFont(&FreeMono9pt7b);
		_display.setTextColor(WHITE);
		// Reset the display
		_display.clearDisplay();
		// draw the underline
		_display.drawLine(0, SCREEN_YELLOW_END, SCREEN_WIDTH - 1, SCREEN_YELLOW_END, WHITE);
		set_title(title);
		set_bit_map(bit_map);
	}

	/**
	 * @brief Set the title string
	 * 
	 * 
	 * @param title 
	 * 
	 * @remark In order to print the whole title on the screen, the length must be 11 characters or less
	 * @remark If len(title)>11, call scroll_title to manually scroll the title to show all characters
	 */
	void set_title(const String & title)
	{
		_current_index = 0;
		this->_title = title;
		cyclic_title_print(SCREEN_TITLE_LENGTH);
	}



	/**
	 * @brief Scrolls the title
	 * 
	 * @remark if the title is 11 characters or less, this function has no effect 
	 */
	void scroll_title()
	{
		if (_title.length() <= SCREEN_TITLE_LENGTH)
		{
			return;
		}
		_current_index++;
		if (_current_index > _title.length())
		{
			_current_index = 0;
		}
		cyclic_title_print(SCREEN_TITLE_LENGTH, _current_index);
	}

	void set_bit_map(const uint8_t * bit_map)
	{	
		// Clear the icon section
		this->_bit_map = bit_map;
		_display.fillRect(0, SCREEN_BLUE_START, SCREEN_WIDTH, SCREEN_BLUE_HEIGHT, BLACK);
		if (bit_map == nullptr)
		{
			return;
		}
		_display.drawBitmap(0, SCREEN_BLUE_START, bit_map, SCREEN_WIDTH, SCREEN_BLUE_HEIGHT, WHITE);
		_display.display();
	}

private:

	void cyclic_title_print(size_t char_num, size_t start_index=0)
	{
		bool space_printed = false;
		size_t current_index = start_index;
		if (char_num > this->_title.length())
		{
			char_num = this->_title.length();
		}
		// Clear the title (execpt the underline)
		this->_display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_YELLOW_END, BLACK);
		this->_display.setCursor(SCREEN_TITLE_X_OFFSET, SCREEN_TITLE_Y_OFFSET);
		for (size_t printed_character_count = 0; printed_character_count < char_num; printed_character_count++)
		{
			/* Cyclic print of the title */
			if (start_index + printed_character_count == this->_title.length())
			{
				_display.print(' ');
				printed_character_count++;
				space_printed = true;
			}
			current_index = start_index + printed_character_count;
			// Space counts as a character printed, but not in the string, so we must subtract the 1 from number of characters to include the space
			if (space_printed)
			{
				// Are we about to underflow?
				if (current_index == 0)
				{
					current_index = this->_title.length() - 1;
				}
				else
				{
					current_index--;
				}
				
			}
			_display.print(_title[current_index % this->_title.length()]);
		}
		_display.display();
	}
	size_t _current_index = 0;
	Adafruit_SSD1306 _display;
	String _title;
	const uint8_t * _bit_map;
};