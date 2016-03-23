/* Compilation: gcc -std=gnu99 -Wall -c -MMD -MP -MF"testAuthentication.d" -MT"testAuthentication.d" -o "testAuthentication.o" testAuthentication.c
 *              gcc -o testAuthentication testAuthentication.o -lcrypt
 */
 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
 
int main(void) {
	const char * const pass = "$1$Fw1PJ/2K$KhVip8FBuJMNXpZh.XqGX."; // Encrypted string before with encryptString.c
	char *result;
	int ok;
 
	result = crypt(getpass("Password: "), pass);
	ok = strcmp(result, pass) == 0;
 
	puts(ok ? "Login successful!" : "Wrong password");
	return ok ? 0 : 1;
}
