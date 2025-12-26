#include<stdio.h>
#include<stdlib.h>

void generate_passwd(void* memory, int lenght)
{

}

int main(int argc, const char* argv[])
{
	if (argc != 2) {
		printf("Usage: passgen <number of the bytes>\n");
	}
	int lenght = atoi(argv[1]);
	printf("Generating password of %d bytes\n", lenght);

	void* password = malloc(lenght);




	free(password);
}