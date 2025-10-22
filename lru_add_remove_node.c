#include "lru.h"

void remove_node (LRUCache* cache, Node* node)
{


    if (node -> prev != NULL)
    {
        node->prev->next = node->next;// el anterior pasa al siguiente
    } 
    else 
    {
        cache->head = node->next;// si es head, el siguiente es el nuevo head
    }
    if(node -> next != NULL) 
    {
        node->next->prev = node->prev; // el siguiente apunta al anterior
    } 
    else 
    {
        cache->tail = node->prev; // si es tail, el anterior es el nuevo tail
    }
    cache->current_size--;
}
