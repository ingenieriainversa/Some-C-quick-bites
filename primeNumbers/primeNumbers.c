/*
 * primeNumbers v0.01
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
 * Compilation: gcc -std=gnu99 -O0 -g3 -Wall -c -o primeNumbers.o "primeNumbers.c"
 *              gcc -o primeNumbers primeNumbers.o
 *
 * Usage:       ./primeNumbers
 */
 
#include <stdio.h>

int main(int argc, char **argv) {
	int limite = 1000, primo;

	for (int i = 2; i <= limite; i++) {
		for (int j = 2; j < i; j++) {
			primo = 1;
			if (i % j == 0) {
				primo = 0;
				break;
			}
		}
		if (primo != 0) printf("%d ", i);
	}
	return 0;
}
