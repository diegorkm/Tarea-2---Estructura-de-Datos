#include "lru.h"

/**
 * @brief Muestra todo el contenido de la caché LRU desde MRU (head) hasta LRU (tail).
 * 
 * Recorre la lista doblemente enlazada e imprime los caracteres en el formato:
 *   Cache contents: C - B - A
 * donde C es el más reciente (head/MRU) y A el menos reciente (tail/LRU).
 * 
 * @param cache Puntero a la estructura LRUCache.
 */
void display_cache(LRUCache* cache)
{
    if (cache == NULL) 
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
