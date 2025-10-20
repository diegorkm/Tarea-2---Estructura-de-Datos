#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) 
{
	int n;
	char letra;

	if (strcmp(argv[1], "create") == 0) 
	{
		n = atoi(argv[2]);
		printf("\ncache creado con tamanyo: %d\n", n);
	}

	if (strcmp(argv[1], "add") == 0)
	{
		letra = argv[2][0];
		printf("\nLetra %c anyadida al cache\n", letra);
	}

	if (strcmp(argv[1], "all") == 0)
	{
		printf("\nMostrando el contenido del cache: \n");
	}

	if (strcmp(argv[1], "get") == 0)
	{
		letra = argv[2][0];
		printf("\nSe ha utilizado: %c\n", letra);
	}

	if (strcmp(argv[1], "exit") == 0)
	{
		printf("\nLiberando cache y saliendo del programa\n");
	}

	return 0;
}