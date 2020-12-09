from os import listdir
from bmp_to_arr import parse_bmp
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


const uint8_t {array_name}[] PROGMEM = {{
	{pixels}
}};

#endif /* {define_macro} */'''

def main():
	for bmp in listdir(BMP_PATH):
		if not bmp.endswith(".bmp"):
			print(f"{bmp} is not a bmp file")
			continue
		bytes_values = parse_bmp(BMP_PATH + bmp)
		bmp = Path(bmp)
		array_name = bmp.stem.replace('-', '_')
		header_path = HEADER_PATH + array_name + ".h"
		
		with open(header_path, "w") as header_file:
			pixels = ', '.join(f"0x{pixel:02x}" for pixel in bytes_values)
			header_file.write(HEADER_FORMAT.format(define_macro="__" + array_name.upper() + "_H__", array_name=array_name, pixels=pixels))


if __name__ == "__main__":
	main()