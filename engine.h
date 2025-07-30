#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t bit_checker(uint8_t vec[], int idx)
{
  uint8_t byte = vec[idx / 8];
  unsigned offset = (idx % 8);
	return (byte >> offset) & 1;
}

uint8_t bit_flipper(uint8_t byte, unsigned idx)
{
	return byte ^ (1 << idx);
}

uint8_t popcount(uint8_t byte)
{
  byte -= (byte >> 1) & 0b01010101;
  byte = (byte & 0b00110011) + ((byte >> 2) & 0b00110011);
  byte = (byte + (byte >> 4)) & 0b00001111;
  return byte;
}

uint8_t xnor_dot(uint8_t byte1, uint8_t byte2)
{
	uint8_t xnor = ~(byte1 ^ byte2);
	return popcount(xnor);
}

uint8_t xnor_dot_vector(uint8_t vec1[], size_t len1, uint8_t vec2[], size_t len2)
{
	uint8_t *arr;
	size_t size = len1 < len2 ? len1 : len2;

	arr = (uint8_t*)calloc(size, sizeof(uint8_t));

	for (int i = 0; i < size; ++i)
	{
		arr[i] = ~(vec1[i] ^ vec2[i]);
	}

	uint8_t final_popcount;
	for (int i = 0; i < size; ++i)
	{
		final_popcount += popcount(arr[i]);
	}

	return final_popcount;
}

bool threshold(uint8_t byte, uint8_t threshold_byte, uint8_t threshold_distance)
{
	uint8_t distance = popcount(byte ^ threshold_byte);
	if (distance <= threshold_distance) { return true; } else { return false; }
}

bool activation(uint8_t byte, uint8_t threshold)
{
	if (byte <= threshold) { return true; } else { return false; }
}

/*int main()
{
	uint8_t vec1[] = { 0b11001100, 0b10101010, 0b11110000 };
	uint8_t vec2[] = { 0b10101010, 0b11110000, 0b00001111 };
	int xnor_dot = xnor_popcount(vec1, sizeof(vec1), vec2, sizeof(vec2));
	printf("The xnor dot product between vec1 and vec2 is: %d\n", xnor_dot);
}*/
