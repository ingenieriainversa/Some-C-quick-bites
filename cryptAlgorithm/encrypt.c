#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uso_err(char *bin) {
	fprintf(stderr, "Uso: %s [cadena de texto]\n", bin);
	exit(1);
}

int main(int argc, char **argv) {
	int i, z, x;

	switch (argc) {
	case 1:
		uso_err(argv[0]);
		break;
	default:
		for (i = 1; i < argc; i++) {
			char *cadena = argv[i];
			for (z = 0, x = 1; z < strlen(cadena); z++, x++) {
				printf("%c : %d : %.3d : %.3d : %02X : %02X\n", cadena[z], x,
						cadena[z], cadena[z] - z, cadena[z], cadena[z] - x);
			}
			if (i != argc - 1)
				printf("%c : %d : %.3d : %.3d : %02X : %02X\n", 32, x, 32,
						32 - x, 32, 32 - x);
		}
		printf("\n");

		for (i = 1; i < argc; i++) {
			char *cadena = argv[i];
			for (z = 0, x = 1; z < strlen(cadena); z++, x++) {
				printf("%02X", cadena[z] - x);
			}
			if (i != argc - 1)
				printf("%02X", 32 - x);
		}
		printf("\n");
	}

	return 0;
}
