#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			if (cache == NULL)
			{
				printf("\nError: El cache no ha sido creado. Use 'create <n>'.\n");
				continue;
			}
			else
			{
				scanf(" %c", &letra);
				add_data(cache, letra);
			}
		}

		if (strcmp(comando, "search") == 0)
		{
			char buscar_letra;
			scanf(" %c", &buscar_letra);
			if (cache == NULL)
			{
				printf("\nError: El cache no ha sido creado. Use 'create <n>'.\n");
			}
			else
			{
				int posicion = search_cache(cache, buscar_letra);
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
