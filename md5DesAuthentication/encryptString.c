/* Compilation: gcc -std=gnu99 -Wall -c -MMD -MP -MF"encryptString.d" -MT"encryptString.d" -o "encryptString.o" encryptString.c
 *              gcc -o encryptString encryptString.o -lcrypt
 */

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <crypt.h>
 
int main(void) {
	unsigned long seed[2];
	char salt[] = "$1$3xe26505";
	const char * const seedchars = "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *myString;
	int i;
 
	seed[0] = time(NULL);
	seed[1] = getpid() ^ (seed[0] >> 14 & 0x30000);
 
	for (i = 0; i < 8; i++) {
		salt[3 + i] = seedchars[(seed[i / 5] >> (i % 5) * 6) & 0x3f];
	}
 
	myString= crypt(getpass("Encrypted string: "), salt);
 
	puts(myString);
	return 0;
}
