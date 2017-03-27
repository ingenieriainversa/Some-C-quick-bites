/*
 * pumpingLemma v0.01
 * Copyleft - 2017  Javier Dominguez Gomez
 * Written by Javier Dominguez Gomez <jdg@member.fsf.org>
 * GnuPG Key: 6ECD1616
 * Madrid, Spain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Compilation: gcc -std=gnu99 -O0 -g3 -Wall -c -o pumpingLemma.o "pumpingLemma.c"
 *              gcc -o pumpingLemma pumpingLemma.o
 *
 * Usage:       ./pumpingLemma
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Longitud maxima + 1. */
#define MAX_LONG_W 256

/* Variables para la constante de bombeo y para subcadenas de w. */
int n, x, y;

int main(int argc, char *argv[]) {

	/* Se asigna memoria para la cadena w y se comprueba si esta bien. */
	char *w = malloc(MAX_LONG_W);
	if (w == NULL) {
		printf("ERROR: Longitud de cadena.\n");
		return 1;
	}

	printf("Introduce una cadena: ");

	/* Guarda la cadena w, con limite de longitud. */
	fgets(w, MAX_LONG_W, stdin);

	/* Se obtiene la logitud de la cadena de entrada. */
	int longitudW = strlen(w) - 1;

	/* Elimina salto de linea del final, si existiera. */
	if ((longitudW + 1 > 0) && (w[longitudW] == '\n')) {
		w[longitudW] = '\0';
	}

	printf("Introduce la constante de bombeo (int): ");

	/* Guarda la constante de bombeo.*/
	scanf("%d", &n);

	/* Se asigna memoria para la subcadena xy y se comprueba si esta bien. */
	char *xy = malloc(sizeof(n));
	if (xy == NULL) {
		printf("ERROR: Longitud de cadena.\n");
		return 1;
	}

	/* 1. Se comprueba si |w|>=n. */
	if (longitudW >= n) {
		printf("La cadena \"%s\" cumple la regla |w|>=n, ya que |%d|>=%d.\n\n",
				w, longitudW, n);

		/* 2. Se descompone la cadena w en tres subcadenas x,y y z. */
		int i;
		for (i = 0; i < longitudW; i++) {
			printf("w[%d] = %c\n", i, w[i]);
		}

		/* Copio los n primeros simbolos de la cadena w en la subcadena xy. */
		strncpy(xy, w, n);

		/* Elimino el ultimo caracter de la cadena xy. */
		xy[n] = 0;

		/* Se obtiene la logitud de la cadena xy. */
		int longitudXY = strlen(xy);

		/* Se asigna memoria para la subcadena z y se comprueba si esta bien. */
		char *z = malloc(longitudW - longitudXY);
		if (z == NULL) {
			printf("ERROR: Longitud de cadena.\n");
			return 1;
		}

		strcpy(z, &w[n]);

		printf("\nn = %d\n", n);
		printf("w = %s\n", w);
		printf("|w|>=n  \t -> |%d|>=%d\n", longitudW, n);
		printf("w = xyz \t -> %s = %s+%s\n", w, xy, z);

		/* 2.1 Se comprueba que |xy|<=n. */

		/* 2.2 Se comprueba que y no es cadena vacia. */

		/* 2.3 Se comprueba que para todo k>=0 la cadena xy^{k}z tambien pertenece a L. */

		free(w);
		free(xy);
		free(z);

	} else {
		printf("La cadena \"%s\" no cumple la regla |w|>=n, ya que |%d|<%d.\n",
				w, longitudW, n);
	}

	return 0;
}
