#include "lru.h"
void free_cache(LRUCache* cache) 
{
    
    if (cache == NULL) 
    {
        return;
    }
    Node* current = cache->head;
    Node* next_node = NULL; 

    while (current != NULL) 
    {
        next_node = current->next; // Guardamos el puntero, antes de liberar el nodo actual.
        free(current); // Liberamos memoria del nodo actual.
        current = next_node; // Avanzamos al siguiente nodo que guardamos.
    }
    free(cache);
}
