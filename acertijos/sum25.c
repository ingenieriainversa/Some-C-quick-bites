/*
 * sum25.c v0.01
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
 * Programa que obtiene la combinacion de numeros dispuestos
 * en 12 estados en forma de cuadrado. Los estados son a, b,
 * c, d, e, f, g, h, i, j, k y l. Se ha de asignar a cada
 * estado un numero entero del 1 al 12 sin repetir. Y también
 * se han de obtener las siguientes sumas: a+b+c+d=25,
 * d+e+f+g=25, g+h+i+j=25 y j+k+l+a=25.
 *
 *  a b c d
 *  l     e
 *  k     f
 *  j i h g
 *
 * Compilation: gcc -O0 -g3 -Wall -c -MF"sum25.d" -MT"sum25.o" -o "sum25.o" "sum25.c"
 *              gcc  -o "sum25" ./sum25.o
 *
 * Usage:       ./sum25
 */

#include <stdio.h>

int main(int argc, char *argv[]) {

	int a, b, c, d, e, f, g, h, i, j, k, l;

	for(a=1;a<=12;a++){
		for(b=1;b<=12;b++){
			for(c=1;c<=12;c++){
				for(d=1;d<=12;d++){
					if(a+b+c+d==25
							&& a!=b && a!=c && a!=d
							&& b!=a && b!=c && b!=d
							&& c!=a && c!=b && c!=d
							&& d!=a && d!=b && d!=c){
						for(e=1;e<=12;e++){
							for(f=1;f<=12;f++){
								for(g=1;g<=12;g++){
									if(d+e+f+g==25
											&& d!=a && d!=b && d!=c && d!=e && d!=f && d!=g
											&& e!=a && e!=b && e!=c && e!=d && e!=f && e!=g
											&& f!=a && f!=b && f!=c && f!=d && f!=e && f!=g
											&& g!=a && g!=b && g!=c && g!=d && g!=e && g!=f){
										for(h=1;h<=12;h++){
											for(i=1;i<=12;i++){
												for(j=1;j<=12;j++){
													if(g+h+i+j==25
															&& g!=a && g!=b && g!=c && g!=d && g!=e && g!=f && g!=h && g!=i && g!=j
															&& h!=a && h!=b && h!=c && h!=d && h!=e && h!=f && h!=g && h!=i && h!=j
															&& i!=a && i!=b && i!=c && i!=d && i!=e && i!=f && i!=g && i!=h && i!=j
															&& j!=a && j!=b && j!=c && j!=d && j!=e && j!=f && j!=g && j!=h && j!=i){
														for(k=1;k<=12;k++){
															for(l=1;l<=12;l++){
																if(j+k+l+a==25
																		&& j!=a && j!=b && j!=c && j!=d && j!=e && j!=f && j!=g && j!=h && j!=i && j!=k && j!=l
																		&& k!=a && k!=b && k!=c && k!=d && k!=e && k!=f && k!=g && k!=h && k!=i && k!=j && k!=l
																		&& l!=a && l!=b && l!=c && l!=d && l!=e && l!=f && l!=g && l!=h && l!=i && l!=j && l!=k
																		&& a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i && a!=j && a!=k && a!=l){
																	if(a+b+c+d+e+f+g+h+i+j+k+l==78){
																		printf("%.2d %.2d %.2d %.2d\t%.2d %.2d %.2d %.2d\t%.2d %.2d %.2d %.2d\t%.2d %.2d %.2d %.2d\t\n",
																				a, b, c, d, d, e, f, g, g, h, i, j, j, k, l, a);
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
