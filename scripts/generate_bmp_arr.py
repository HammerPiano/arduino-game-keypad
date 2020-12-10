from os import listdir
from bmp_to_arr import parse_bmp, get_bmp_size
from pathlib import Path

# ! Apperantly platformio uses a venv to run this scripts, to install external libraries we must call pip from the python
# ! Like this:
# Import("env")
# env.Execute("pip install ...")
# 
# ! Not kidding
# ! https://docs.platformio.org/en/latest/projectconf/advanced_scripting.html#extra-python-packages

BMP_PATH = "bmps/"
HEADER_PATH = "include/bmps/"

HEADER_FORMAT = ''' #include <Arduino.h>

#ifndef {define_macro}
#define {define_macro}

#define {array_name}_WIDTH  ({width})
#define {array_name}_HEIGHT ({height})

const uint8_t BMP_{array_name}[] PROGMEM = {{
	{pixels}
}};

#endif /* {define_macro} */'''

def main():
	print("generating c arrays from BMP pictures:")
	for bmp in listdir(BMP_PATH):
		print(bmp)
		if not bmp.endswith(".bmp"):
			print(f"warning - {bmp} is not a bmp file")
			continue
		bytes_values = parse_bmp(BMP_PATH + bmp)
		width, height = get_bmp_size(BMP_PATH + bmp)
		bmp = Path(bmp)
		array_name = bmp.stem.replace('-', '_').upper()
		header_path = HEADER_PATH + bmp.stem.replace('-', '_') + ".h"
		with open(header_path, "w") as header_file:
			pixels = ', '.join(f"0x{pixel:02x}" for pixel in bytes_values)
			define_macro = "__" + array_name.upper() + "_H__"
			header_file.write(HEADER_FORMAT.format(define_macro=define_macro,
												array_name=array_name,
												pixels=pixels,
												width=width,
												height=height
												))

main()