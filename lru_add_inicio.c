/**
 * @file lru_add_inicio.c
 * @brief Implementación de la función para añadir o promover un nodo al inicio (MRU) de la caché LRU.
 *
 * Esta función es fundamental para el algoritmo LRU, ya que cualquier nodo que es añadido 
 * o "usado" (promovido) debe ser colocado en la posición de máxima prioridad (head).
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
 * @brief Añade un nodo dado al inicio de la lista doblemente enlazada (MRU).
 *
 * Esta función maneja cuatro casos principales:
 * 1. Conexión del nuevo nodo con el antiguo head.
 * 2. Actualización del puntero 'prev' del antiguo head.
 * 3. Actualización del puntero 'head' del caché.
 * 4. Manejo del caso en que la lista estaba vacía (actualización del tail).
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param node Puntero al nodo que se va a insertar como nuevo head.
 * @return void
 */

void add_inicio(LRUCache* cache, Node* node)
{
    //Conecta el nuevo nodo con la estructura existente.
    // Se conectan los nodos a ambas direcciones
    node->next = cache->head;
    node->prev = NULL; //El nuevo nodo siempre será el primero, por lo que su 'prev' es NULL.

    //Si hay elementos, el antiguo head apunta al nuevo nodo
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
