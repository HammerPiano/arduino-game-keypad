#pragma once
#include <Arduino.h>
#include <screen.h>

#define COMMS_BAUD_RATE (115200)


/*
 * Message format:
 * From computer, commands:
 * X+<command>:<parameters>
 * 
 * Commands:
 * 	I - update image, parameters: image data (768 bytes of buffer)
 * 	T - update title, parameters: title
*/

class Comms
{
public:

	enum config_update_type
	{
		NOTHING,
		TITLE,
		IMAGE
	};

	/**
	 * @brief This function starts the internal serial USB port
	 * 
	 * @param baud baud rate, defaults to COMMS_BAUD_RATE
	 */
	void begin(unsigned long baud = COMMS_BAUD_RATE)
	{
		Serial.begin(baud);
		Serial.println("Arduino Joystick!");
	}

	
	/**
	 * @brief This function checks if new data has arrived
	 * 
	 * @return true if there is data, false otherwise 
	 */
	bool data_available()
	{
		return Serial.available();
	}

	/**
	 * @brief This function updates the current profile settings
	 *		  Meaning, if data regarding image, title... is in the buffer
	 * 
	 * @return what updated
	 */
	config_update_type update()
	{
		config_update_type update_type = config_update_type::NOTHING;
		if (data_available() == false)
		{
			update_type = config_update_type::NOTHING;
		}

		String command_string = Serial.readStringUntil(parameter_seperator);

		if (command_string == command_title)
		{
			handle_update_title();
			update_type = config_update_type::TITLE;

		}
		else if (command_string == command_image)
		{
			if (handle_update_image())
			{
				update_type = config_update_type::IMAGE;
			}
		}
		
		return update_type;
	}


	byte * get_image_buffer()
	{
		//return _image_buffer;
	}
	String & get_title()
	{
		return _title;
	}

private:

	const String command_image = "X+I";
	const String command_title = "X+T";
	const String button_prefix = "B+";
	const String command_button_prefix = "C+";

	const char parameter_seperator = ':';
	/**
	 * @brief This function updates the internal image buffer
	 * 
	 * @return true image buffer updated successfully
	 * @return false image buffer update timed out
	 */
	bool handle_update_image()
	{
		// readBytes returns how many bytes have been read, it must be equal to the size of the buffer to make sure everything works
		//return Serial.readBytes(_image_buffer, sizeof(_image_buffer)) == sizeof(_image_buffer);		
	}

	void handle_update_title()
	{
		_title = Serial.readString();
	}

	// size is in bits, aka pixels!
	//byte _image_buffer[SCREEN_BMP_MAX_SIZE / 8];
	String _title;
	
};