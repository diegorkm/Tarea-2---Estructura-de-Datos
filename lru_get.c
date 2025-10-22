#include "lru.h"

void get_data(LRUCache* cache, char data) 
{
    if (cache == NULL || cache->capacity == 0) 
    {
        printf("Error: El cache no ha sido inicializado.\n");
        return;
    }

    Node* existente = buscar_nodo(cache, data);
    if (existente != NULL)
    {
        remove_node(cache, existente);
        add_inicio(cache, existente);
        printf("\nElemento %c encontrado y movido a inicio.\n", data);
    } 
    else 
    {
        printf("\nElemento %c no encontrado en el cache.\n", data);
    }
}   
