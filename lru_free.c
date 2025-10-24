/**
 * @file lru_free.c
 * @brief Implementación de la función `free_cache` para liberar toda la memoria dinámica de la caché LRU.
 *
 * Esta función es crítica para evitar fugas de memoria (memory leaks). Recorre la lista 
 * doblemente enlazada, liberando nodo por nodo, y finalmente libera la estructura 
 * principal LRUCache.
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
 * @brief Libera toda la memoria dinámica asociada a la caché LRU.
 *
 * La liberación se realiza en dos fases:
 * 1. Recorre la lista enlazada (desde el head) y libera cada nodo individualmente.
 * 2. Finalmente, libera la estructura LRUCache principal.
 * Se incluye una verificación para asegurar que la función pueda ser llamada incluso 
 * si la caché nunca fue creada.
 *
 * @param cache Puntero a la estructura LRUCache a liberar.
 * @return void No retorna valor.
 */
void free_cache(LRUCache* cache) 
{
    //Verificación de seguridad, no intenta liberar si el cache es NULL
    if (cache == NULL) 
    {
        return;
    }
    Node* current = cache->head;
    Node* next_node = NULL; 

    //Recorre y libera todos los nodos
    while (current != NULL) 
    {
        next_node = current->next; // Guardamos el puntero, antes de liberar el nodo actual.
        free(current); // Liberamos memoria del nodo actual.
        current = next_node; // Avanzamos al siguiente nodo que guardamos.
    }
    free(cache);
}
