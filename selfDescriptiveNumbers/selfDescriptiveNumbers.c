#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char w[10];
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

int main() {
	for(num=0;num<=9999999999;num++){
		printf("w = %s\n\n", w);
		compruebaNumero(w);
	}

//	printf("Cantidad de 0 que tiene: %d\n");
//	printf("Cantidad de 1 que tiene: %d\n");
//	printf("Cantidad de 2 que tiene: %d\n");
//	printf("Cantidad de 3 que tiene: %d\n");
//	printf("Cantidad de 4 que tiene: %d\n");
//	printf("Cantidad de 5 que tiene: %d\n");
//	printf("Cantidad de 6 que tiene: %d\n");
//	printf("Cantidad de 7 que tiene: %d\n");
//	printf("Cantidad de 8 que tiene: %d\n");
//	printf("Cantidad de 9 que tiene: %d\n");
}
