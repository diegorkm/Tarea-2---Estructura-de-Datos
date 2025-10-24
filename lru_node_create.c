/**
 * @file lru_node_create.c
 * @brief Implementación de las funciones para la creación de la estructura LRUCache y de los nodos Node.
 *
 * Contiene la definición de dos funciones clave para la inicialización:
 * 1. create_cache(): Asigna y configura la estructura principal del caché.
 * 2. create_node(): Asigna y configura un nodo individual que será parte de la lista doblemente enlazada.
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
 * * Asigna memoria para un nuevo nodo e inicializa sus punteros 'prev' y 'next' a NULL.
 * El dato proporcionado es almacenado en el campo 'data'.
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
