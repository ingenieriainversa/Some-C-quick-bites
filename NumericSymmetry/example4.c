/*
 * NumericSymmetry - example4 v0.01
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
 * Compilation: gcc -std=gnu99 -O0 -g3 -Wall -c -o example4.o "example4.c"
 *              gcc -o example4 example4.o
 *
 * Usage:       ./example4
 */

#include <stdio.h>

int main(void) {
	double num = 1;

	for (int i = 1; i <= 9; i++) {
		printf("%9.0f * %-9.0f = %0.f\n", num, num, num*num);
		num = (num * 10) + 1;
	}
}
