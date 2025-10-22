#include "lru.h"


void add_data(LRUCache* cache, char data) 
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
        printf("\nElemento %c ya existe, movido a inicio.\n", data);
        return;
    } 
    
    if (cache->current_size >= cache->capacity) 
    {
        Node* lru = cache->tail;
        char dato_eliminado = lru->data;
        remove_node(cache, lru);
        free(lru);
        printf("\nElemento %c eliminado (cache lleno)\n", dato_eliminado);
    }

    Node* nuevo_nodo = create_node(data);
    if(nuevo_nodo == NULL) 
    {
        printf("Error al crear el nodo\n");
        return;
    }

    add_inicio(cache, nuevo_nodo);
    printf("\nElemento %c anyadido al cache.\n", data);
}