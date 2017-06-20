/*
 * matriz.c v0.01
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
 * Compilation: gcc -O0 -g3 -Wall -c -MF"matriz.d" -MT"matriz.o" -o "matriz.o" "matriz.c"
 *              gcc  -o "matriz" ./matriz.o
 *
 * Usage:       ./matriz
 */

#include "matriz.h"

#include <stdio.h>
#include <stdlib.h>

int i, j;

struct MatrizStruct {
	int matrix_a[3][3];
	int matrix_aT[3][3];
	int matrix_aAdj[3][3];
	int matrix_aInv[3][3];
};

int determinante(Matriz m) {
	return (m->matrix_a[0][0] * m->matrix_a[1][1] * m->matrix_a[2][2])
			+ (m->matrix_a[2][0] * m->matrix_a[0][1] * m->matrix_a[1][2])
			+ (m->matrix_a[0][2] * m->matrix_a[1][0] * m->matrix_a[2][1])
			- (m->matrix_a[2][0] * m->matrix_a[1][1] * m->matrix_a[0][2])
			- (m->matrix_a[0][0] * m->matrix_a[1][2] * m->matrix_a[2][1])
			- (m->matrix_a[0][1] * m->matrix_a[1][0] * m->matrix_a[2][2]);
}

Matriz traspuesta(Matriz m) {
	m->matrix_aT[0][0] = m->matrix_a[0][0];
	m->matrix_aT[0][1] = m->matrix_a[1][0];
	m->matrix_aT[0][2] = m->matrix_a[2][0];
	m->matrix_aT[1][0] = m->matrix_a[0][1];
	m->matrix_aT[1][1] = m->matrix_a[1][1];
	m->matrix_aT[1][2] = m->matrix_a[2][1];
	m->matrix_aT[2][0] = m->matrix_a[0][2];
	m->matrix_aT[2][1] = m->matrix_a[1][2];
	m->matrix_aT[2][2] = m->matrix_a[2][2];

	return m;
}

Matriz adjunta(Matriz m) {
	m->matrix_aAdj[0][0] = m->matrix_a[1][1] * m->matrix_a[2][2] - m->matrix_a[2][1] * m->matrix_a[1][2];
	m->matrix_aAdj[0][1] = -(m->matrix_a[1][0] * m->matrix_a[2][2] - m->matrix_a[2][0] * m->matrix_a[1][2]);
	m->matrix_aAdj[0][2] = m->matrix_a[1][0] * m->matrix_a[2][1] - m->matrix_a[2][0] * m->matrix_a[1][1];
	m->matrix_aAdj[1][0] = -(m->matrix_a[0][1] * m->matrix_a[2][2] - m->matrix_a[2][1] * m->matrix_a[0][2]);
	m->matrix_aAdj[1][1] = m->matrix_a[0][0] * m->matrix_a[2][2] - m->matrix_a[2][0] * m->matrix_a[0][2];
	m->matrix_aAdj[1][2] = -(m->matrix_a[0][0] * m->matrix_a[2][1] - m->matrix_a[2][0] * m->matrix_a[0][1]);
	m->matrix_aAdj[2][0] = m->matrix_a[0][1] * m->matrix_a[1][2] - m->matrix_a[1][1] * m->matrix_a[0][2];
	m->matrix_aAdj[2][1] = -(m->matrix_a[0][0] * m->matrix_a[1][2] - m->matrix_a[1][0] * m->matrix_a[0][2]);
	m->matrix_aAdj[2][2] = m->matrix_a[0][0] * m->matrix_a[1][1] - m->matrix_a[1][0] * m->matrix_a[0][1];

	return m;
}

Matriz inversa(Matriz m) {
	/* Una matriz solo es invertible si su determinante es distinto de 0. */

	/* La matriz inversa es igual a (1/|A|)*(Adj(A))^t */

	/* Construyo solo la matriz traspuesta de la adjunta. Cada
	 * elemento de la matriz sera el numerador de una fraccion que
	 * tendra por denominador el determinite de la matriz de entrada. */
	m->matrix_aInv[0][0] = m->matrix_aAdj[0][0];
	m->matrix_aInv[0][1] = m->matrix_aAdj[1][0];
	m->matrix_aInv[0][2] = m->matrix_aAdj[2][0];
	m->matrix_aInv[1][0] = m->matrix_aAdj[0][1];
	m->matrix_aInv[1][1] = m->matrix_aAdj[1][1];
	m->matrix_aInv[1][2] = m->matrix_aAdj[2][1];
	m->matrix_aInv[2][0] = m->matrix_aAdj[0][2];
	m->matrix_aInv[2][1] = m->matrix_aAdj[1][2];
	m->matrix_aInv[2][2] = m->matrix_aAdj[2][2];

	return m;
}

void printDatos(Matriz m) {

	/* Imprime la matriz de entrada. */
	printf("\nMatriz:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%3d", m->matrix_a[i][j]);
		}
		printf("\n");
	}

	/* Imprime su determinante. */
	printf("\nEl determinante es: %d\n", determinante(m));

	/* Imprime la matriz traspuesta. */
	printf("\nMatriz traspuesta:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%3d", m->matrix_aT[i][j]);
		}
		printf("\n");
	}

	/* Imprime la matriz adjunta. */
	printf("\nMatriz adjunta:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("%3d", m->matrix_aAdj[i][j]);
		}
		printf("\n");
	}

	printf("\nMatriz inversa:\n");
	/* Solo se calculara la inversa si el determinante es distinto de cero. */
	if(determinante(m) != 0){
		inversa(m);

		/* Imprime la matriz inversa. */
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				printf("%3d/%d", m->matrix_aInv[i][j], determinante(m));
			}
			printf("\n");
		}
	} else {
		printf("No tiene invertida por que su determinante es 0.\n");
	}
}

int main(void) {
	Matriz matriz = malloc(sizeof(struct MatrizStruct));

	/* Pide datos de la matriz 3X3 */
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("Numero %d,%d: ", i + 1, j + 1);
			scanf("%d", &matriz->matrix_a[i][j]);
		}
	}

	/* Se calcula todo */
	determinante(matriz);
	traspuesta(matriz);
	adjunta(matriz);

	/* Se muestran todos los datos por pantalla. */
	printDatos(matriz);

	return 0;
}
