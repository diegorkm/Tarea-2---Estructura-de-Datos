/**
 * @file lru_add_buscar_nodo.c
 * @brief Implementación de la función auxiliar para buscar un nodo dentro de la caché.
 *
 * Esta función recorre la lista doblemente enlazada desde el MRU (head) para 
 * encontrar la primera ocurrencia de un dato específico. Es utilizada por 
 * las funciones de manipulación del caché como add_data() y get_data().
 *
 * @author Diego Peralta, Sebastian Ramirez, Rodolfo Aguilar, Benjamin Reyes 
 * @date 24 de Octubre de 2025
 */

#include "lru.h"


/**
 * @brief Busca un nodo específico en la caché por su dato.
 *
 * Recorre la lista desde el head (MRU) hasta el tail (LRU). 
 * Si el dato es encontrado (Cache Hit), retorna un puntero al nodo. 
 * Si no se encuentra (Cache Miss), retorna NULL. 
 * Esta es una operación de solo lectura y no modifica la prioridad del dato.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param data El dato (carácter) a buscar.
 * @return Node* Puntero al nodo encontrado, o NULL si el dato no está presente.
 */
Node* buscar_nodo(LRUCache* cache, char data)
{
    Node* actual = cache->head;
    // Recorre la lista mientras 'actual' no sea NULL.
    while (actual != NULL) 
    {
        if (actual->data == data) 
        {
            return actual; // Retorna el nodo si encuentra el dato.
        }

        actual = actual->next;
    }
    return NULL; // Retorna NULL si el dato no fue encontrado.
}