#include<stdio.h>
#include<stdbool.h>

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
	int n, x, y, kaprekar;

	do {
		printf("Numero de 4 digitos: ");
		scanf("%d", &n);
	} while (CompruebaDigitos(n) == false);

	kaprekar = n;

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
