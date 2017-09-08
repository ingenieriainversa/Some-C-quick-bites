#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int num;
int veces[10];

bool compruebaNumero(char *w) {
	int i, j, longitudW;

	/* Se obtiene la logitud de la cadena, sin
	 * tener en cuenta el salto de linea. */
	longitudW = strlen(w) - 1;

	/* Elimina salto de linea del final, si existiera. */
	if ((longitudW + 1 > 0) && (w[longitudW] == '\n')) {
		w[longitudW] = '\0';
	}

	for (i = 0; i <= longitudW; i++) {

		/* Convierto el char en su int correspondiente [0-9] */
		int iw = w[i] - '0';

		/* Identifico las veces que aparece un
		 * numero en cada posicion del array. */
		for (j = 0; j <= 9; j++) {
			if (iw == j) {
				veces[j] += 1;
			}
		}
	}

	for (i = 0; i <= longitudW; i++) {

		/* Convierto el char en su int correspondiente [0-9] */
		int iw = w[i] - '0';

		if (veces[i] != iw) {
			printf("Error: No es un numero autodefinido.");
			return false;
		}
	}
	return true;
}

int getLongitudInt(long x) {
	int len = 1;
	while (x > 0) {
		x = x / 10;
		len++;
	}
	return len - 2;
}

int main() {
	int n = 12103;

	int longitudInt = getLongitudInt(n), numArray[longitudInt];

	while (n > 0) {
		numArray[longitudInt] = n % 10;
		n /= 10;
		longitudInt--;
	}

	printf("%d\n", numArray[0]);

	int i;
	for(i=0;i<=9;i++){
		printf("%d\n", numArray[i]);
	}

//for(num=0;num<=9999999999;num++){
	printf("num = %d\n", n);
//compruebaNumero(w);
//}
}
