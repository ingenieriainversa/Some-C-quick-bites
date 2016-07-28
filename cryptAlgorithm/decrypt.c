#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uso_err(char *bin) {
	fprintf(stderr, "Uso: %s [cadena de texto]\n", bin);
	exit(1);
}

int main(int argc, char **argv) {
	int i, z, x;
	char *hexadecimal, *caracter;

	switch (argc) {
	case 1:
		uso_err(argv[0]);
		break;
	default:
		for (i = 1; i < argc; i++) {
			char *cadena = argv[i];
			for (z = 0, x = 1; z < strlen(cadena); z++, x++) {
				caracter = cadena[z];
				hexadecimal = malloc(strlen(caracter)+2);
				printf("%c", cadena[z]);
				if(z%2) printf("\n");
			}
		}
	}

	return 0;
}
