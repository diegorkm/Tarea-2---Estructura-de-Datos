#include "lru.h"

Node* buscar_nodo(LRUCache* cache, char data)
{
    Node* actual = cache->head;
    while (actual != NULL) 
    {
        if (actual->data == data) 
        {
            return actual;
        }

        actual = actual->next;
    }
    return NULL;
}