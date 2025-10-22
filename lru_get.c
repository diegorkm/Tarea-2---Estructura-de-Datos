/**
 * @file lru_get.c
 * @brief Implementación de la función `get_data` para simular el uso de un elemento en la caché LRU.
 *
 * Esta función simula la operación de "uso" o "lectura" de un elemento en el caché.
 * Si el elemento existe (Cache Hit), se promueve al inicio (MRU) para reflejar 
 * que es el dato más recientemente utilizado. Si no existe (Cache Miss), no hace nada.
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
 * @brief Simula el uso de un dato en la caché LRU, promoviéndolo a MRU si existe.
 *
 * Busca el dato en el caché.
 * - **Cache Hit:** Si el nodo es encontrado, se remueve de su posición actual 
 * y se añade al inicio de la lista (MRU).
 * - **Cache Miss:** Si el nodo no es encontrado, no se realiza ninguna modificación.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param data El carácter (letra) a buscar y usar.
 * @return void No retorna valor.
 */

void get_data(LRUCache* cache, char data) 
{   //Comprobación de errores
    if (cache == NULL || cache->capacity == 0) 
    {
        printf("Error: El cache no ha sido inicializado.\n");
        return;
    }
    //Revisa si existe el nodo en el cache
    Node* existente = buscar_nodo(cache, data);
    if (existente != NULL) //Si existe el nodo:
    {
        remove_node(cache, existente); //Lo quita de su posición actual
        add_inicio(cache, existente); //Lo añade al inicio (MRU)
        printf("\nElemento %c encontrado y movido a inicio.\n", data);
    } 
    else 
    {   //Si el nodo no existe:
        printf("\nElemento %c no encontrado en el cache.\n", data);
    }
}   
