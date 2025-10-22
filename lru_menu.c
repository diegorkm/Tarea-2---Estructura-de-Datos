/**
 * @file lru_menu.c
 * @brief Implementación de la función que muestra el menú de comandos de la aplicación LRU.
 *
 * Esta función proporciona al usuario una referencia rápida de todos los comandos
 * disponibles para interactuar con el sistema de caché.
 *
 * * @authors 
 *          - Diego Peralta
 *          - Sebastian Ramirez
 *          - Rodolfo Aguilar
 *          - Benjamin Reyes
 * @date 24 de Octubre de 2025
 */

#include "lru.h"


/**
 * @brief Imprime en la consola el listado de comandos disponibles para la interacción del usuario.
 *
 * Los comandos incluyen:
 * - 'create <n>' para inicializar la caché[cite: 15].
 * - 'add <x>' para añadir/promover un dato[cite: 18].
 * - 'search <x>' para buscar un dato sin alterar su prioridad[cite: 20].
 * - 'get <x>' para "usar" un dato y modificar su prioridad[cite: 17].
 * - 'all' para ver el contenido del caché[cite: 20].
 * - 'exit' para liberar la memoria y terminar el programa[cite: 57].
 *
 * @param void No recibe parámetros.
 * @return void No retorna valor.
 */
void menu()
{
	printf("\nComandos disponibles:\n");
	printf("create <n> : Crea un cache de tamanyo n\n");
	printf("add <x>    : Anyade el elemento x al cache\n");
	printf("search <x> : Busca un elemento x en el cache\n");
	printf("get <x>    : Utiliza el elemento x del cache\n");
	printf("all        : Muestra el contenido del cache\n");
	printf("exit       : Libera el cache y sale del programa\n\n");
}
