#include<stdio.h>
#include<math.h>

int inversor(int numero) {
	int nDigitos = (numero == 0 ? 1 : (int) (log10(numero) + 1));
	int numeroInvertido = 0;
	do {
		nDigitos -= 1;
		numeroInvertido += (numero % 10) * (pow(10, nDigitos));
		numero /= 10;
	} while (numero != 0);

	return numeroInvertido;
}

int main() {
	int numero = 10000, i, z;

	for (i = 0, z = 0; i <= numero; i++) {
		int numeroInvertido = inversor(i);
		int resultado = i - numeroInvertido;
		if (resultado == 6174) {
			z++;
			printf("%.2d. %.4d - %.4d = %d\n", z, i, numeroInvertido, resultado);
		}
	}
	return 0;
}
