from bmp_to_arr import parse_bmp
import json
from os import listdir

PICTURE_DIRECTORY = 'bmps/'
INCLUDE_DIRECTORY = 'include/bmps/'
PIXELS_IN_ROW = 8
KEYPAD_BUTTON_COUNT = 9


def format_pixels(pixels):
	lines = []
	for i in range(0, len(pixels), PIXELS_IN_ROW):
		lines.append(', '.join('0x{0:02x}'.format(pixel) for pixel in pixels[i:i+PIXELS_IN_ROW]))
	return ',\n\t'.join(lines)


def main():
	with open('scripts/template_header.h') as template_header_file:
		template_header = template_header_file.read()
	for picture_path in listdir(PICTURE_DIRECTORY):
		height, width, pixels = parse_bmp(PICTURE_DIRECTORY+picture_path)
		pixels = format_pixels(pixels)
		header_path = INCLUDE_DIRECTORY + picture_path.replace('.bmp', '.h')
		picture_array_name = picture_path[:picture_path.find('.bmp')].upper() + '_BMP'
		with open(header_path, 'w') as profile_header:
			profile_header.write(template_header.format(**locals()))

main()