/*
 * NumericSymmetry - example1 v0.01
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
 * Compilation: gcc -std=gnu99 -O0 -g3 -Wall -c -o example1.o "example1.c"
 *              gcc -o example1 example1.o
 *
 * Usage:       ./example1
 */

#include <stdio.h>

int concat();

int main(void) {
	int num = 1;

	for (int i = 1; i <= 9; i++) {
		printf("%9d * 8 + %d = %d\n", num, i, num * 8 + i);
		num = concat(num, i + 1);
	}
}

int concat(int x, int y) {
	int temp = y;
	while (y != 0) {
		x *= 10;
		y /= 10;
	}
	return x + temp;
}
