/**
 * @file lru.c
 * @brief Implementación del bucle principal (main) para el sistema de caché LRU.
 * * Este archivo contiene la función main que gestiona la interfaz de usuario por 
 * línea de comandos, permitiendo la creación, adición, búsqueda, uso, 
 * visualización y liberación del caché LRU.
 * @authors - Diego Peralta
 *          - Sebastian Ramirez
 *          - Rodolfo Aguilar
 *          - Benjamin Reyes
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lru.h"

/**
 * @brief Punto de entrada principal del programa LRU.
 * * Inicializa la caché y gestiona el bucle de comandos interactivo del usuario.
 * * @param argc Número de argumentos pasados por línea de comandos (no utilizado).
 * @param argv Array de strings de argumentos (no utilizado).
 * @return int Retorna 0 si el programa finaliza exitosamente.
 */

int main(int argc, char* argv[]) 
{
	//Variables de control y manejo de comandos.
	int n, ejecutando=1, posicion;
	char letra, comando[7], buscar_letra;
	//Puntero a la estructura de la cache, inicializando en NULL.
	LRUCache* cache = NULL;
	
	menu(); //Muestra el menú de comandos.

	while (ejecutando) //Bucle principal de ejecución
	{
		printf("lru> ");
		scanf("%s", comando); //Lee el comando ingresado por el usuario.

		/**
		 * @brief Comando "create"
		 * Inicializa el caché si aún no ha sido creado. 
		 * Requiere un entero para la capacidad máxima.
		 */

		if (strcmp(comando, "create") == 0)
		{
			if (cache == NULL)
			{
				scanf("%d", &n);
				cache = create_cache(n); 	// Si create_cache devuelve NULL, ya ha impreso el error interno (capacidad < 5 o malloc fallido).
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

		/**
		 * @brief Comando "add"
		 * Agrega un nuevo elemento al caché o promueve uno existente a MRU.
		 * Requiere un carácter (letra) a añadir.
		 */

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

		/**
		 * @brief Comando "search"
		 * Busca un elemento en el caché e imprime su posición (1-basada) o -1.
		 * No altera la prioridad del dato.
		 */

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

		/**
		 * @brief Comando "all"
		 * Muestra el contenido actual del caché, desde MRU (head) a LRU (tail).
		 * No altera la prioridad de los datos.
		 */

		if (strcmp(comando, "all") == 0)
		{
			display_cache(cache);
		}

		/**
		 * @brief Comando "get"
		 * Utiliza un elemento existente, promoviéndolo a MRU (posición 1).
		 * Si no existe, no hace nada.
		 */

		if (strcmp(comando, "get") == 0)
		{
			scanf(" %c", &letra);
			printf("\nSe ha utilizado: %c\n", letra);
			get_data(cache, letra);
		}

		/**
		 * @brief Comando "exit"
		 * Libera la memoria de la caché y sale del bucle principal.
		 */

		if (strcmp(comando, "exit") == 0)
		{
			printf("\nLiberando cache y saliendo del programa\n");
			free_cache(cache);
			ejecutando = 0;
		}
	}
	return 0;
}
