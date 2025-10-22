#include "lru.h"

/**
 * @brief Busca un dato en la caché LRU y devuelve su posición (1-basada).
 * * @param cache Puntero a la estructura LRUCache.}
 * @param data El carácter (letra) a buscar.
 * @return int La posición del dato (1-basada) si se encuentra, o -1 si no está.
 */

int search_cache(LRUCache* cache, char data)
{
    int position;
    if (cache == NULL)
    {
        return -1;
    }

    Node* current = cache->head;
    position = 1; // La posición se cuenta desde 1 (el head es la posición 1).

    while (current != NULL) // Recorre la lista enlazada desde el MRU (head) hasta el LRU (tail).
    {
        if (current->data == data)
        {
            return position;  //Dato encontrado, devuelve la posición.
        }
        current = current->next;
        position++;
    }

    return -1; // Si no encuentra el dato, devuelve -1.
}