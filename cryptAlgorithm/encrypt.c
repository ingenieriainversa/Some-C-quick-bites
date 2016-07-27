#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void uso_err(char *bin) {
	fprintf(stderr, "Uso: %s [cadena de texto]\n", bin);
	exit(1);
}

int main(int argc, char **argv) {

	int i, z;

	switch (argc) {
	case 1:
		uso_err(argv[0]);
		break;
	default:
		for (i = 1; i < argc; i++) {
			char *cadena = argv[i];
			for (z = 0; z < strlen(cadena); z++) {
				printf("%c : %02X\n", cadena[z], cadena[z]);
			}
			if (i != argc - 1)
				printf("%c : %02X\n", 32, 32);
		}
	}

	return 0;
}
