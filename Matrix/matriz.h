/*
 * matriz.h v0.01
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
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

struct MatrizStruct;
typedef struct MatrizStruct* Matriz;

void printDatos(Matriz m);
int determinante(Matriz m);
Matriz traspuesta(Matriz m);
Matriz adjunta(Matriz m);
Matriz inversa(Matriz m);

#endif /* MATRIZ_H_ */
