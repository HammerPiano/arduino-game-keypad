#pragma once

#include <Arduino.h>

#define WIDTH	(128)
#define HEIGHT	(48)

const uint8_t ELITE_DANGEROUS_BMP[] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01,
	0x38, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03,
	0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x02,
	0x90, 0x40, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07,
	0x70, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x02,
	0x80, 0xe0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x0e,
	0x78, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x06,
	0x38, 0x40, 0x78, 0x00, 0x00, 0x00, 0x00, 0x1e,
	0x7c, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x1c,
	0x78, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x3e,
	0x7e, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x01, 0xf0,
	0x79, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x7e,
	0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0f, 0x80,
	0x7b, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x00, 0xfc,
	0x0f, 0x80, 0x00, 0x00, 0x01, 0xf0, 0x0e, 0x00,
	0xf0, 0xe0, 0x0f, 0x80, 0x00, 0x00, 0x01, 0xf0,
	0x17, 0xc0, 0x00, 0x00, 0x03, 0xe8, 0x0c, 0x00,
	0xf0, 0x60, 0x17, 0xc0, 0x00, 0x00, 0x03, 0xe8,
	0x1b, 0xd0, 0x00, 0x00, 0x0b, 0xd8, 0x0c, 0x01,
	0xe0, 0x60, 0x1b, 0xd0, 0x00, 0x00, 0x0b, 0xd8,
	0x0f, 0xd8, 0x04, 0x20, 0x1b, 0xf8, 0x0c, 0x01,
	0xe0, 0x60, 0x0f, 0xd8, 0x04, 0x20, 0x1b, 0xf8,
	0x0f, 0xdc, 0x06, 0x60, 0x3b, 0xf0, 0x0c, 0x01,
	0xe0, 0x60, 0x0f, 0xdc, 0x06, 0x60, 0x3b, 0xf0,
	0x0f, 0xee, 0x06, 0x60, 0x77, 0xf0, 0x0c, 0x03,
	0xc0, 0x60, 0x0f, 0xee, 0x06, 0x60, 0x77, 0xf0,
	0x07, 0xef, 0x04, 0x20, 0xf7, 0xe0, 0x0c, 0x03,
	0xc0, 0x60, 0x07, 0xef, 0x04, 0x20, 0xf7, 0xe0,
	0x01, 0xf7, 0x85, 0xa1, 0xef, 0x00, 0x0c, 0x07,
	0x80, 0x60, 0x01, 0xf7, 0x85, 0xa1, 0xef, 0x00,
	0x02, 0xf3, 0xc3, 0xc3, 0xce, 0x80, 0x0c, 0x07,
	0x80, 0x60, 0x02, 0xf3, 0xc3, 0xc3, 0xce, 0x80,
	0x03, 0x75, 0xf1, 0x8f, 0xad, 0x80, 0x0c, 0x0f,
	0x00, 0x60, 0x03, 0x75, 0xf1, 0x8f, 0xad, 0x80,
	0x01, 0xf6, 0xf1, 0x8f, 0x6f, 0x00, 0x06, 0x1e,
	0x00, 0xc0, 0x01, 0xf6, 0xf1, 0x8f, 0x6f, 0x00,
	0x01, 0xfa, 0xf1, 0x8f, 0x5f, 0x00, 0x02, 0x3c,
	0x01, 0x80, 0x01, 0xfa, 0xf1, 0x8f, 0x5f, 0x00,
	0x01, 0xfd, 0xe3, 0xc7, 0xbf, 0x00, 0x00, 0xf8,
	0x03, 0x00, 0x01, 0xfd, 0xe3, 0xc7, 0xbf, 0x00,
	0x00, 0xfd, 0xe7, 0xe7, 0xbf, 0x00, 0x00, 0xf0,
	0x06, 0x00, 0x00, 0xfd, 0xe7, 0xe7, 0xbf, 0x00,
	0x00, 0x7d, 0xe7, 0xe7, 0xbe, 0x00, 0x01, 0xe0,
	0x0c, 0x00, 0x00, 0x7d, 0xe7, 0xe7, 0xbe, 0x00,
	0x00, 0x3e, 0xfb, 0xdf, 0x7c, 0x00, 0x00, 0x80,
	0x18, 0x00, 0x00, 0x3e, 0xfb, 0xdf, 0x7c, 0x00,
	0x00, 0x1f, 0x7d, 0xbe, 0xf0, 0x00, 0x00, 0x18,
	0x30, 0x00, 0x00, 0x1f, 0x7d, 0xbe, 0xf0, 0x00,
	0x00, 0x07, 0xbf, 0xfd, 0xe8, 0x00, 0x00, 0x0c,
	0x60, 0x00, 0x00, 0x07, 0xbf, 0xfd, 0xe8, 0x00,
	0x00, 0x0b, 0xde, 0x7b, 0xd8, 0x00, 0x00, 0x06,
	0xc0, 0x00, 0x00, 0x0b, 0xde, 0x7b, 0xd8, 0x00,
	0x00, 0x0d, 0xee, 0x77, 0xb8, 0x00, 0x00, 0x03,
	0x80, 0x00, 0x00, 0x0d, 0xee, 0x77, 0xb8, 0x00,
	0x00, 0x0e, 0xf6, 0x6f, 0x70, 0x00, 0x00, 0x01,
	0x00, 0x00, 0x00, 0x0e, 0xf6, 0x6f, 0x70, 0x00,
	0x00, 0x07, 0x7a, 0x5e, 0xe0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x07, 0x7a, 0x5e, 0xe0, 0x00,
	0x00, 0x03, 0xbc, 0x3d, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x03, 0xbc, 0x3d, 0xc0, 0x00,
	0x00, 0x01, 0xbe, 0x7d, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x01, 0xbe, 0x7d, 0x80, 0x00,
	0x00, 0x00, 0x3e, 0x7c, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x3e, 0x7c, 0x00, 0x00,
	0x00, 0x00, 0x3d, 0xbc, 0x00, 0x00, 0x39, 0xfc,
	0x06, 0x00, 0x00, 0x00, 0x3d, 0xbc, 0x00, 0x00,
	0x00, 0x00, 0x1d, 0xb8, 0x00, 0x00, 0x10, 0x86,
	0x06, 0x00, 0x00, 0x00, 0x1d, 0xb8, 0x00, 0x00,
	0x00, 0x00, 0x0e, 0x70, 0x00, 0x00, 0x10, 0x83,
	0x09, 0x00, 0x00, 0x00, 0x0e, 0x70, 0x00, 0x00,
	0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x10, 0x81,
	0x09, 0x00, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00,
	0x00, 0x00, 0x06, 0x60, 0x00, 0x00, 0x10, 0x81,
	0x09, 0x00, 0x00, 0x00, 0x06, 0x60, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x10, 0x81,
	0x10, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x10, 0x81,
	0x1f, 0x80, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x10, 0x83,
	0x20, 0x40, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x10, 0x86,
	0x20, 0x40, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xfc,
	0x70, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};