/*
 * exampleBasicAuth.c v0.01
 * Copyleft - 2014  Javier Dominguez Gomez
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
 * Compilation: gcc -std=gnu99 -Wall -c -MMD -MP -MF"exampleBasicAuth.d" -MT"exampleBasicAuth.d" -o "exampleBasicAuth.o" exampleBasicAuth.c
 *              gcc -o exampleBasicAuth exampleBasicAuth.o -lcrypt
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
 
#define clear() fprintf(stdout,"\033[H\033[J\n")
 
static const char *title = "Example C authentication";
const float version = 0.01;
 
char header(float),login(float),tries(int,int);
int linea(int);
 
int line(int s) {
	fprintf(stdout,"+");
	for (int i = 0; i <= s; i++) {
		fprintf(stdout,"-");
	}
	fprintf(stdout,"+\n");
	return 0;
}
 
char header(float v) {
	line(25);
	fprintf(stdout,"| %s v%-4.2f |\n",title,v);
	linea(25);
	return 0;
}
 
char attempts(int attempts, int times) {
	if (attempts == times) {
		fprintf(stderr,"\n\t\tToo many attempts. Exit.\n");
		exit(1);
	}
	return 0;
}
 
char login(float v) {
	clear();
	const char *u = "$1$7h3PJFHK$pDqnoIBwBomxiFev8Czwz.";
	const char *p = "$1$Yh3PJR3E$IX1rbs.IliGgOC/7ccFlr/";
	const int times = 3;
	char *U,*P;
	int i;
	header(v);
	for (i = 0;i < times;i++) {
		U = crypt(getpass("\n User:\t"), u);
		if (strcmp(U,u) != 0) {
			fprintf(stderr,"\t\tWrong user\n");
			continue;
		}
		P = crypt(getpass(" Password:\t"), p);
		if (strcmp(P,p) != 0) {
			fprintf(stderr,"\n\t\tWrong password\n");
			continue;
		}
		break;
	}
	attempts(i,times);
	return 0;
}
 
int main(int argc,char *argv[]) {
	int stdOut = '\0';
 
	//Authentication
	stdOut = login(version);
 
	if (!stdOut) {
		clear();
		header(version);
		fprintf(stdout,"\n Authentication successful!\n\n");
	}
}
