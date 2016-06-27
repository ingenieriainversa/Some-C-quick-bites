#include <stdio.h>

int concat();

int main(void) {
	int num = 1;

	for (int i = 1; i <= 9; i++) {
		printf("%9d * 8 + %d = %d\n", num, i, num * 8 + i);
		num = concat(num, i + 1);
	}
}

int concat(int x, int y) {
	int temp = y;
	while (y != 0) {
		x *= 10;
		y /= 10;
	}
	return x + temp;
}
