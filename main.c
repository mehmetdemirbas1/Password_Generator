#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <bcrypt.h>
#pragma comment(lib, "bcrypt.lib")

void generate_passwd(char* memory, int length)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
	size_t charset_len = sizeof(charset) - 1;
	NTSTATUS status = BCryptGenRandom(
		NULL,
		(PUCHAR)memory,
		(ULONG)length,
		BCRYPT_USE_SYSTEM_PREFERRED_RNG
	);

	if (!BCRYPT_SUCCESS(status)) {
		return;
	}

	for (int i = 0; i < length; ++i) {
		unsigned char random_byte = (unsigned char)*(memory + i);
		*(memory + i) = charset[random_byte % charset_len];
	}
}

int main(int argc, const char* argv[])
{
	if (argc != 2) {
		printf("Usage: passgen <number of the bytes>\n");
	}
	int length = atoi(argv[1]);
	printf("Generating password of %d bytes\n", length);

	char* password = (char*)malloc(length);
	generate_passwd(password, length);
	printf("Genereted Password: %s \n", password);

	free(password);
}