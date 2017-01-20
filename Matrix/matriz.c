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
#include <math.h>

int i, j;

struct MatrizStruct {
	int matrix_a[3][3];
	int matrix_aT[3][3];
	int matrix_aAdj[3][3];
};

int main(void) {
	struct MatrizStruct* matriz = malloc(sizeof(struct MatrizStruct));

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf("Numero %d,%d: ", i + 1, j + 1);
			scanf("%d", &matriz->matrix_a[i][j]);
		}
	}
	printf("\n");
	imprimir(matriz);
	printf("\n");
	printf("|A| =  %d\n", determinante(matriz));
	printf("\n");
	traspuesta(matriz);
	printf("\n");

	return 0;
}

void imprimir(Matriz m) {
	for (i = 0; i < 3; i++) {
		if (i == 1) {
			printf(" A  =");
		} else {
			printf("     ");
		}
		for (j = 0; j < 3; j++) {
			printf("%3d", m->matrix_a[i][j]);
		}
		printf("\n");
	}
}

int determinante(Matriz m) {
	return (m->matrix_a[0][0] * m->matrix_a[1][1] * m->matrix_a[2][2])
			+ (m->matrix_a[2][0] * m->matrix_a[0][1] * m->matrix_a[1][2])
			+ (m->matrix_a[0][2] * m->matrix_a[1][0] * m->matrix_a[2][1])
			- (m->matrix_a[2][0] * m->matrix_a[1][1] * m->matrix_a[0][2])
			- (m->matrix_a[0][0] * m->matrix_a[1][2] * m->matrix_a[2][1])
			- (m->matrix_a[0][1] * m->matrix_a[1][0] * m->matrix_a[2][2]);
}

void traspuesta(Matriz m) {
	m->matrix_aT[0][0] = m->matrix_a[0][0];
	m->matrix_aT[0][1] = m->matrix_a[1][0];
	m->matrix_aT[0][2] = m->matrix_a[2][0];
	m->matrix_aT[1][0] = m->matrix_a[0][1];
	m->matrix_aT[1][1] = m->matrix_a[1][1];
	m->matrix_aT[1][2] = m->matrix_a[2][1];
	m->matrix_aT[2][0] = m->matrix_a[0][2];
	m->matrix_aT[2][1] = m->matrix_a[1][2];
	m->matrix_aT[2][2] = m->matrix_a[2][2];

	for (i = 0; i < 3; i++) {
		if (i == 1) {
			printf(" AT =");
		} else {
			printf("     ");
		}
		for (j = 0; j < 3; j++) {
			printf("%3d", m->matrix_aT[i][j]);
		}
		printf("\n");
	}
}

void adjunta(Matriz m) {
	m->matrix_aAdj[0][0] = pow(-1, 2)
			* (m->matrix_a[1][1] * m->matrix_a[2][2]
					- m->matrix_a[2][0] * m->matrix_a[1][2]);
}

void inversa(Matriz m) {
	// una matriz solo es invertible si su determinante es distinto de 0.
}
