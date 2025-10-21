#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lru.h"


int main(int argc, char* argv[]) 
{
	int n, ejecutando=1;
	char letra, comando[7];
	LRUCache* cache = NULL;
	
	menu();

	while (ejecutando)
	{
		printf("lru> ");
		scanf("%s", comando);

		if (strcmp(comando, "create") == 0)
		{
			if (cache == NULL)
			{
				scanf("%d", &n);
				cache = create_cache(n);
				if (cache != NULL)
				{
					printf("\nCache creado con tamayo: %d\n", cache->capacity);
				} 
			
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
