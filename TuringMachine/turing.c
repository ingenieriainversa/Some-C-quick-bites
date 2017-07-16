/*
 * turinMachine v0.03
 * Copyleft - 2017  Javier Dominguez Gomez
 * Written by Javier Dominguez Gomez <jdg@member.fsf.org>
 * GnuPG Key: D6648E2B
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
 * Compilation: gcc -std=gnu99 -O0 -g3 -Wall -c -o turing.o "turing.c"
 *              gcc -o turing turing.o
 *
 * Usage:       ./turing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

/* Longitud maxima + 1. */
#define MAX_LONG 256

/* Variables para la constante de bombeo y para subcadenas de w. */
int i, longitudW;

void estado_q0(char*, int);
void estado_q1(char*, int);
void estado_q2(char*, int);

void printLog(char *w) {
	printf("w es \"%s\" (%lu)\n\n", w, strlen(w));
}

void addBlankL(char *w) {
	/* Recorro el array de derecha a izquierda y desplazo
	 * los caracteres una posicion a la derecha */
	for (i = strlen(w); i > 0; i--) {
		w[i] = w[i - 1];
	}

	/* Finalmente añado un blanco por la izquierda. */
	w[i] = '_';
	printLog(w);
}

void addBlankR(char *w) {
	/* Concateno la cadena w con un blanco por la derecha. */
	strcat(w, "_");
	printLog(w);
}

void fin(char *w){
	printf("Enhorabuena! se cumple que a^{n}b^{n} | n >= 0\n");
}

void printTest(char *w, int i, char x, char m, char *e){
	printf("w es: \"%s\". Leo \"%c\", lo cambio por \"%c\", me muevo a la %c y me voy al estado %s.\n", w, w[i], x, m, e);
}

void estado_q0(char *w, int i) {
	// Si leo un 0
	if (w[i] == '0') {

		printTest(w, i, '_', 'R', "q1");

		// lo cambio por un blanco
		w[i] = '_';
		// me muevo a la derecha (R) y me voy al estado q1.
		estado_q1(w, i += 1);

		// Si leo un 1
	} else if (w[i] == '1') {

		printTest(w, i, '_', 'L', "q2");

		// lo cambio por un blanco
		w[i] = '_';
		// me muevo a la izquierda (L) y me voy al estado q2.
		estado_q2(w, i -= 1);

		// Si leo un blanco
	} else if (w[i] == '_') {

		printTest(w, i, '_', '!', "q0");

		// lo dejo en blanco
		w[i] = '_';
		// y finalmente se detiene la maquina de Turing.
		fin(w);
	}
}

void estado_q1(char *w, int i) {
	// Si leo un 0
	if (w[i] == '0') {

		printTest(w, i, '0', 'R', "q1");

		// no modifico el valor 0,
		// me muevo a la derecha (R) y sigo en el estado q1.
		estado_q1(w, i += 1);

		// Si leo un 1
	} else if (w[i] == '1') {

		printTest(w, i, '1', 'R', "q1");

		// no modifico el valor 1,
		// me muevo a la derecha (R) y sigo en el estado q1.
		estado_q1(w, i += 1);

		// Si leo un blanco
	} else if (w[i] == '_') {

		printTest(w, i, '_', 'L', "q0");

		// lo dejo en blanco
		w[i] = '_';
		// me muevo a la izquierda (L) y me voy al estado q0.
		estado_q0(w, i -= 1);
	}
}

void estado_q2(char *w, int i) {
	// Si leo un 0
	if (w[i] == '0') {

		printTest(w, i, '0', 'L', "q2");

		// no modifico el valor 0,
		// me muevo a la izquierda (L) y sigo en el estado q2.
		estado_q2(w, i -= 1);

		// Si leo un 1
	} else if (w[i] == '1') {

		printTest(w, i, '1', 'L', "q2");

		// no modifico el valor 1,
		// me muevo a la izquierda (L) y sigo en el estado q2.
		estado_q2(w, i -= 1);

		// Si leo un blanco
	} else if (w[i] == '_') {

		printTest(w, i, '_', 'R', "q0");

		// lo dejo en blanco
		w[i] = '_';
		// me muevo a la derecha (R) y me voy al estado q0.
		estado_q0(w, i += 1);
	}
}

int main(int argc, char *argv[]) {

	/* Se asigna memoria para la cadena w. */
	char *w = malloc(MAX_LONG);

	printf("Introduce una cadena: ");

	/* Guarda la cadena w, con limite de longitud. */
	fgets(w, MAX_LONG, stdin);

	/* Se obtiene la logitud de la cadena de entrada,
	 * sin tener en cuanta el salto de linea. */
	longitudW = strlen(w) - 1;

	/* Elimina salto de linea del final, si existiera. */
	if ((longitudW + 1 > 0) && (w[longitudW] == '\n')) {
		w[longitudW] = '\0';
	}

	printLog(w);
	printf("Añadiendo un blanco por la izquierda.\n");
	addBlankL(w);

	printf("Añadiendo un blanco por la derecha.\n");
	addBlankR(w);

	/* Le digo a la maquina de Turing que empiece
	 * por el caracter w[1] en el estado q0 */
	estado_q0(w, 1);

	free(w);

	return 0;
}
