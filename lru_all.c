/**
 * @file lru_all.c
 * @brief Implementación de la función para mostrar el contenido completo de la caché LRU.
 *
 * Esta función recorre la lista doblemente enlazada desde el head (MRU) hasta el tail (LRU)
 * e imprime los datos de cada nodo, permitiendo al usuario visualizar el estado actual
 * y el orden de prioridad del caché.
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
 * @brief Muestra el contenido completo de la caché, desde MRU (head) a LRU (tail).
 *
 * Recorre la lista enlazada e imprime la información de cada nodo. Si el caché está
 * vacío o no ha sido inicializado, imprime un mensaje de error o estado.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @return void No retorna valor.
 */

void display_cache(LRUCache* cache)
{
    if (cache == NULL) //Verificación de errores
    {
        printf("No hay cache. Utiliza 'create <n>' primero.\n");
        return;
    }

    Node* current = cache->head;

    if (current == NULL) 
    {
        printf("Contenido del cache: [vacio]\n");
        return;
    }

    printf("Contenido del cache: ");
    while (current != NULL) // Recorre de MRU (head) a LRU (tail).
    {
        printf("[%c]", current->data);
        if (current->next != NULL) 
        {
            printf(" - ");
        }
        current = current->next;
    }
    printf("\n");
}
