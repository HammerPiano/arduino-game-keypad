from imageio import imread
from sys import argv

PARAMETER_COUNT = 2 # program path, and picture path
# Size of the BMP is 128x48 pixels
BMP_WIDTH = 128
BMP_HEIGHT = 48

def get_pixel_list(bmp_image):
	pixels = []
	assert ((len(bmp_image) <= BMP_HEIGHT) and (len(bmp_image[0]) <= BMP_WIDTH)),  "Incorrect size for BMP image"
	for row in bmp_image:
		for pixel in row:
			# Each pixel has the RGB values of it, the format is 8 bits for each pixel
			# And since the display is 1bit per pixel, if the average value is above 127,
			# half of 8 bits the pixel will be lit
			pixels.append(1 if sum(pixel)/len(pixel) > 127 else 0)
	return pixels

def pixels_to_bytes(pixels):
	# Pixels are store in an array, each bit alone. We combine 8 bits to a bit, as this is how it is stored
	bytes_list = []
	for index in range(0, len(pixels), 8):
		# pixels are stored LSBit first, bytes are MSBit first, so reverese them
		bit_list = pixels[index: index + 8]	
		bit_list = bit_list[::-1]
		byte_value = 0
		for bit_index, bit in enumerate(bit_list):
			byte_value |= bit << bit_index
		bytes_list.append(byte_value)
	return bytes_list

def parse_bmp(bmp_path):
	# Read the bmp image
	bmp_image = imread(bmp_path)
	height = len(bmp_image)
	width = len(bmp_image[0])
	pixels = get_pixel_list(bmp_image)
	return height, width, pixels_to_bytes(pixels)


if __name__ == "__main__":
	if len(argv) != PARAMETER_COUNT:
		print("Usage: bmp_to_arr.py <bmp_path>")
		exit()
	print(parse_bmp(argv[1]))