/**
 * lru_create.c
 * Implementación de la función para crear una caché LRU.
 * 
 * Autores: 
 * Fecha: 24 de Octubre de 2025
 * 
 * Descripción:
 *      Esta función reserva memoria para una estructura LRUCache,
 *      valida que la capacidad sea al menos 5 e inicializa
 *      los punteros head y tail en NULL. 
 */

#include "lru.h"

/**
 * @brief Crea e inicializa una caché LRU con la capacidad dada.
 * 
 * @param capacity Capacidad máxima del caché. Debe ser >= 5.
 * @return LRUCache* Puntero a la caché creada, o NULL si falla
 *      (capacidad inválida o error de memoria).
 */

LRUCache* create_cache(int capacity){
    if (capacity < 5){
        printf("El tamanyo minimo del cache es 5.\n");
        return NULL;
    }

    LRUCache* cache = (LRUCache*) malloc(sizeof(LRUCache));
    if (cache == NULL) {
        printf("Error al asignar memoria para el cache.\n");
        return NULL;
    }

    cache->capacity = capacity;
    cache->current_size = 0;
    cache->head = NULL;
    cache->tail = NULL;

    return cache;
}

/**
 * @brief Crea un nuevo nodo (Node) para almacenar un dato de tipo char.
 * * @param data El carácter (letra mayúscula) que se almacenará en el nodo.
 * @return Node* Puntero al nodo creado, o NULL si falla la asignación de memoria.
 */

Node* create_node(char data) 
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) 
    {
        printf("Error al asignar memoria para el nodo.\n");
        return NULL;
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}
