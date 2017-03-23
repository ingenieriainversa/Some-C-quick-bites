/*
 * kaprekarConstant v0.01
 * Copyleft - 2016  Javier Dominguez Gomez
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
 * Compilation: gcc -std=gnu99 -O0 -g3 -Wall -c -o kaprekarConstant.o "kaprekarConstant.c"
 *              gcc -o kaprekarConstant kaprekarConstant.o
 *
 * Usage:       ./kaprekarConstant
 */
 
#include<stdio.h>
#include<stdbool.h>

/* Procedimiento para ordenar dos numeros. */
void swap(int *x, int *y) {
	if (*x < *y) {
		int aux;
		aux = *x;
		*x = *y;
		*y = aux;
	}
}

/* Funcion que devuelve la longitud de un int. */
int LongitudInt(int n) {
	int i = 1;
	while (n > 9) {
		i++;
		n /= 10;
	}
	return i;
}

/* Funcion que devuelve un int con sus digitos en orden descendente. */
int OrdenacionDescendenteInt(int n) {
	int i, n_ordenado = 0;
	for (i = 9; i >= 0; i--) {
		int aux = n;
		while (aux > 0) {
			int digit = aux % 10;
			if (digit == i) {
				n_ordenado *= 10;
				n_ordenado += digit;
			}
			aux /= 10;
		}
	}
	return n_ordenado;
}

/* Funcion que devuelve un int con sus digitos en orden ascendente. */
int OrdenacionAscendenteInt(int n) {
	int i, n_ordenado = 0;
	for (i = 0; i <= 9; i++) {
		int aux = n;
		while (aux > 0) {
			int digit = aux % 10;
			if (digit == i) {
				n_ordenado *= 10;
				n_ordenado += digit;
			}
			aux /= 10;
		}
	}
	return n_ordenado;
}

/* Funcion que comprueba si el numero introducido tiene 4 digitos. */
static bool CompruebaDigitos(int n) {
	if (LongitudInt(n) < 4) {
		printf("Longitud del numero %d invalida. Tiene que tener 4 digitos.\n", n);
		return false;
	} else {
		return true;
	}
}

int main() {
	int n, x, y = 0, kaprekar = 0;

	do {
		printf("Numero de 4 digitos: ");
		scanf("%d", &n);
	} while (CompruebaDigitos(n) == false);

	x = n;
	y = OrdenacionAscendenteInt(x);

	/* Se asigna a x el numero mayor y a y el menor. */
	swap(&x, &y);

	kaprekar = x - y;
	printf("%d - %d = %d\n", x, y, kaprekar);

	do {
		if (kaprekar == 0) {
			printf("Numero %d invalido por resto 0.\n", n);
			break;
		}
		x = OrdenacionDescendenteInt(kaprekar);
		y = OrdenacionAscendenteInt(kaprekar);
		kaprekar = x - y;
		printf("%d - %d = %d\n", x, y, kaprekar);
	} while (kaprekar != 6174);

	return 0;
}
