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
