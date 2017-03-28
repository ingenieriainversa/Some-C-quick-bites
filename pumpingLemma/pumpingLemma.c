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
#define MAX_LONG 256

/* Variables para la constante de bombeo y para subcadenas de w. */
int n, longitudW, longitudXY, longitudX, longitudY, longitudZ;
bool check_1, check_2, check_3;

void printCheck1(bool check_1, int longitudW, int n) {
	printf("|w|>=n  \t (%s) -> |%d|>=%d\n", check_1 ? "true" : "false",
			longitudW, n);
}
void printCheck2(bool check_2, int longitudXY, int n) {
	printf("|xy|<=n  \t (%s) -> |%d|<=%d\n", check_2 ? "true" : "false",
			longitudXY, n);
}

void printCheck3(bool check_3, int longitudY) {
	printf("|y|>0   \t (%s) -> |%d|>0\n", check_3 ? "true" : "false",
			longitudY);
}

int checkLongitudDeCadena(char *cadena) {
	if (cadena == NULL) {
		printf("ERROR: Longitud de cadena.\n");
		return 1;
	} else {
		return 0;
	}
}

int main(int argc, char *argv[]) {

	/* Se asigna memoria para la cadena l del lenguaje, y se comprueba si esta bien. */
	char *l = malloc(MAX_LONG);
	checkLongitudDeCadena(l);

	printf("Introduce un lenguaje: ");

	/* Guarda la cadena l, con limite de longitud. Por ejemplo 01^n0. */
	fgets(l, MAX_LONG, stdin);



	/* Se asigna memoria para la cadena w y se comprueba si esta bien. */
	char *w = malloc(MAX_LONG);
	checkLongitudDeCadena(w);

	/* Se obtiene la logitud de la cadena de entrada. */
	longitudW = strlen(w) - 1;

	/* Elimina salto de linea del final, si existiera. */
	if ((longitudW + 1 > 0) && (w[longitudW] == '\n')) {
		w[longitudW] = '\0';
	}

	printf("Introduce la constante de bombeo (int): ");

	/* Guarda la constante de bombeo.*/
	scanf("%d", &n);

	printf("\nCadena w\t\t-> %s\n", w);
	printf("Constante de bombeo n\t-> %d\n\n", n);

	/* Se asigna memoria para la subcadena xy y se comprueba si esta bien. */
	char *xy = malloc(sizeof(n));
	checkLongitudDeCadena(xy);

	/* 1. Se comprueba si |w|>=n. */
	if (longitudW >= n) {
		check_1 = true;

		/* 2. Se descompone la cadena w en tres subcadenas x,y y z. */

		/* Copio los n primeros simbolos de la cadena w en la subcadena xy. */
		strncpy(xy, w, n);

		/* Elimino el ultimo caracter de la cadena xy. */
		xy[n] = 0;

		/* Se obtiene la logitud de la cadena xy. */
		longitudXY = strlen(xy);

		/* 2.1 Se comprueba que |xy|<=n. */
		if (longitudXY <= n) {
			check_2 = true;

			/* Se asigna memoria para la subcadena z y se comprueba si esta bien. */
			char *z = malloc(longitudW - longitudXY);
			checkLongitudDeCadena(z);

			/* Copio los ultimos simbolos de la cadena w en la subcadena z. */
			strcpy(z, &w[n]);

			/* Se obtiene la logitud de la cadena z. */
			longitudZ = strlen(z);

			/* Se asigna memoria para la subcadena z y se comprueba si esta bien. */
			char *x = malloc(longitudW - longitudXY);
			checkLongitudDeCadena(x);

			/* Copio los n-1 primeros simbolos de la cadena xy en la subcadena x. */
			strncpy(x, xy, n - 1);

			/* Elimino el ultimo caracter de la cadena x. */
			x[n - 1] = 0;

			/* Se obtiene la logitud de la cadena x. */
			longitudX = strlen(x);

			/* Se asigna memoria para la subcadena y y se comprueba si esta bien. */
			char *y = malloc(longitudXY - longitudX);
			checkLongitudDeCadena(y);

			/* Copio los ultimos simbolos de la cadena w en la subcadena y. */
			strcpy(y, &xy[longitudXY - 1]);

			/* Se obtiene la logitud de la cadena y. */
			longitudY = strlen(y);

			/* 2.2 Se comprueba que y no es cadena vacia. */
			if (longitudY > 0) {
				check_3 = true;
				printCheck1(check_1, longitudW, n);
				printCheck2(check_2, longitudXY, n);
				printCheck3(check_3, longitudY);

				/* 2.3 Se comprueba que para todo k>=0 la cadena xy^{k}z tambien pertenece a L. */
				int k = 5;
				char *nueva_cadena = malloc(longitudW - 1);
				checkLongitudDeCadena(nueva_cadena);
				strcpy(nueva_cadena, x);
				while (k > 0) {
					strcat(nueva_cadena, y);
					k--;
				}
				strcat(nueva_cadena, z);

				printf("\n%s + %s + %s = _%s_\n", x, y, z, nueva_cadena);
			} else {
				check_3 = false;
				printCheck3(check_3, longitudY);
			}

			free(x);
			free(y);
			free(z);
		} else {
			check_2 = false;
			printCheck2(check_2, longitudXY, n);
		}
	} else {
		check_1 = false;
		printCheck1(check_1, longitudW, n);
		return 1;
	}

	free(w);
	free(xy);

	return 0;
}
