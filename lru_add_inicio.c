#include "lru.h"

void add_inicio(LRUCache* cache, Node* node)
{
    // Se conectan los nodos a ambas direcciones
    node->next = cache->head;
    node->prev = NULL;

    //Si hay elementos, el antigua head apunta al atras
    if (cache->head != NULL) 
    {
        cache->head->prev = node;
    }

    // Actualizamos el head del cache
    cache->head = node;

    // si es el primer elemento, este tambien es el tail

    if (cache->tail == NULL) 
    {
        cache->tail = node;
    }
    
    //incrementamos el tamaño actual
    cache->current_size++;
}
