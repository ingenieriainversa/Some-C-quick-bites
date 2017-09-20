#include <stdio.h>
#include <limits.h>

int main(void) {
	printf("number of bits in a char: %d\n", CHAR_BIT);
	printf("minimum value for a signed char: %d\n", SCHAR_MIN);
	printf("maximum value for a signed char: %d\n", SCHAR_MAX);
	printf("maximum value for an unsigned char: %d\n", UCHAR_MAX);
	printf("minimum value for a char: %d\n", CHAR_MIN);
	printf("maximum value for a char: %d\n", CHAR_MAX);
	printf("maximum multibyte length of a character accross locales: %d\n", MB_LEN_MAX);
	printf("minimum value for a short: %d\n", SHRT_MIN);
	printf("maximum value for a short: %d\n", SHRT_MAX);
	printf("maximum value for an unsigned short: %d\n", USHRT_MAX);
	printf("minimum value for an int: %d\n", INT_MIN);
	printf("maximum value for an int: %d\n", INT_MAX);
	printf("maximum value for an unsigned int: %d\n", UINT_MAX);
	printf("minimum value for a long: %ld\n", LONG_MIN);
	printf("maximum value for a long: %ld\n", LONG_MAX);
	printf("maximum value for an unsigned long: %ld\n", ULONG_MAX);
}
