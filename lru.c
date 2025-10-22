#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lru.h"


int main(int argc, char* argv[]) 
{
	int n, ejecutando=1, posicion;
	char letra, comando[7], buscar_letra;
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
					printf("\nCache creado con tamanyo: %d\n", cache->capacity);
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

		if (strcmp(comando, "search") == 0)
		{
			scanf(" %c", &buscar_letra);
			if (cache == NULL)
			{
				printf("\nError: El cache no ha sido creado. Use 'create <n>'.\n");
			}
			else
			{
				posicion = search_cache(cache, buscar_letra);
				if (posicion != -1)
				{
					printf("\nEl dato %c esta presente en la posicion %d del cache.\n", buscar_letra, posicion);
				}
				else 
				{
					printf("\nEl dato %c no esta presente. Devuelve %d.\n", buscar_letra, posicion);
				}
			}
		}

		if (strcmp(comando, "all") == 0)
		{
			display_cache(cache);
		}

		if (strcmp(comando, "get") == 0)
		{
			scanf(" %c", &letra);
			printf("\nSe ha utilizado: %c\n", letra);
			get_data(cache, letra);
		}

		if (strcmp(comando, "exit") == 0)
		{
			printf("\nLiberando cache y saliendo del programa\n");
			free_cache(cache);
			ejecutando = 0;
		}
	}
	return 0;
}
