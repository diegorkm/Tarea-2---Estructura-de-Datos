#include <stdio.h>
#include "lru.h"

void menu()
{
	printf("\nComandos disponibles:\n");
	printf("create <n> : Crea un cache de tamanyo n\n");
	printf("add <x>    : Anyade el elemento x al cache\n");
	printf("get <x>    : Utiliza el elemento x del cache\n");
	printf("all        : Muestra el contenido del cache\n");
	printf("exit       : Libera el cache y sale del programa\n\n");
}