#include<stdio.h>

int main() {
	int limite = 1000;

	for (int i = 2; i < limite; i++) {
		int primo = 1;

		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				primo = 0;
				break;
			}
		}

		if (primo == 1) printf("%d ", i);
	}
	return 0;
}
