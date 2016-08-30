#include<stdio.h>

int main() {
	int numero = 1475, i=0;
	printf("%d invertido:\n", numero);
	do {
		i++;
		printf("%d %d\n", i, numero%10);
		numero/=10;
	} while (numero!=0);
	printf("\nFinalmente i vale %d.", i);
	return 0;
}
