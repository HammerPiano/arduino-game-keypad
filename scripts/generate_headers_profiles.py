from bmp_to_arr import parse_bmp
import json
from os import listdir

REQUIRED_KEYS = ['title', 'keypad_values', 'bit_map']
BMP_DIRECTORY = 'bmps/'
INCLUDE_DIRECTORY = 'include/profiles/'
PROFILE_DIRECTORY = 'profiles/'
PIXELS_IN_ROW = 8
KEYPAD_BUTTON_COUNT = 9


def format_pixels(pixels):
	lines = []
	for i in range(0, len(pixels), PIXELS_IN_ROW):
		lines.append(', '.join('0x{0:02x}'.format(pixel) for pixel in pixels[i:i+PIXELS_IN_ROW]))
	return ',\n\t\t'.join(lines)


def read_json(json_path):
	with open(json_path) as profile_file:
		profile = json.load(profile_file)
	for key in REQUIRED_KEYS:
		if key not in profile:
			raise RuntimeError(f"Invalid profile, no key {key}")
	if len(profile['keypad_values']) != KEYPAD_BUTTON_COUNT:
		raise RuntimeError("Invalid keypad button count")
	return profile


def generate_profile_header(profile, struct_name, header_template):
	# Deep copy, not to modify the original
	header_template_parameters = dict(profile)
	header_template_parameters['pixels'] = format_pixels(parse_bmp(profile['bit_map']))
	header_template_parameters['keypad_values'] = ', '.join(str(keypad) for keypad in profile['keypad_values'])
	header_template_parameters['struct_name'] = struct_name
	return header_template.format(**header_template_parameters)

def main():
	with open('scripts/template_header.h') as template_header_file:
		template_header = template_header_file.read()
	for profile_path in listdir(PROFILE_DIRECTORY):
		profile = read_json(PROFILE_DIRECTORY + profile_path)
		profile_name = profile_path[:profile_path.find('.')]
		header_path = INCLUDE_DIRECTORY + profile_name + '.h'
		struct_name = profile_name.upper() + '_PROFILE'
		with open(header_path, 'w') as profile_header:
			profile_header.write(generate_profile_header(profile, struct_name, template_header))

main()