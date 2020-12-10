#pragma once
#include <Arduino.h>
#define BMP_HEIGHT 48
#define BMP_WIDTH 128
#define KEYPAD_COUNT 9
struct PROFILE_FLASH_t
{
	const char * title ;
	const uint32_t keypad_values[KEYPAD_COUNT] PROGMEM;
	const uint8_t  pixels[BMP_HEIGHT * BMP_WIDTH / 8] PROGMEM;
};
