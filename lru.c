#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int main(int argc, char* argv[]) 
{
	int n, ejecutando=1, contador=0;
	char letra, comando[7];

	menu();

	while (ejecutando)
	{
		printf("lru> ");
		scanf("%s", comando);

		if (strcmp(comando, "create") == 0)
		{
			if (contador == 0)
			{
				scanf("%d", &n);
				printf("\nCache creado con tamanyo: %d\n", n);
				contador = 1;
			}
			else
			{
				printf("\nEl cache ya ha sido creado\n");
			}
		}

		if (strcmp(comando, "add") == 0)
		{
			scanf(" %c", &letra);
			printf("\nLetra %c anyadida al cache\n", letra);
		}

		if (strcmp(comando, "all") == 0)
		{
			printf("\nMostrando el contenido del cache: \n");
		}

		if (strcmp(comando, "get") == 0)
		{
			scanf(" %c", &letra);
			printf("\nSe ha utilizado: %c\n", letra);
		}

		if (strcmp(comando, "exit") == 0)
		{
			printf("\nLiberando cache y saliendo del programa\n");
			ejecutando = 0;
		}
	}
	return 0;
}

void menu()
{
	printf("\nComandos disponibles:\n");
	printf("create <n> : Crea un cache de tamanyo n\n");
	printf("add <x>    : Anyade el elemento x al cache\n");
	printf("get <x>    : Utiliza el elemento x del cache\n");
	printf("all        : Muestra el contenido del cache\n");
	printf("exit       : Libera el cache y sale del programa\n\n");
}