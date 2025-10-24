/**
 * @file lru_search.c
 * @brief Implementación de la función para buscar un dato en la caché LRU sin alterar su prioridad.
 *
 * Esta función es fundamental para verificar la existencia de un dato (Cache Hit/Miss)
 * en los comandos 'search' y 'get'. Retorna la posición del dato (1-basada) 
 * o -1 si no se encuentra, manteniendo la naturaleza de solo lectura.
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
 * @brief Busca un dato en la caché LRU y devuelve su posición (1-basada).
 * * @param cache Puntero a la estructura LRUCache.}
 * @param data El carácter (letra) a buscar.
 * @return int La posición del dato (1-basada) si se encuentra, o -1 si no está.
 */

int search_cache(LRUCache* cache, char data)
{
    int position;
    if (cache == NULL) //Valida si la cache ha sido creada
    {
        return -1;
    }

    Node* current = cache->head;
    position = 1; // La posición se cuenta desde 1 (el head es la posición 1).

    while (current != NULL) // Recorre la lista enlazada desde el MRU (head) hasta el LRU (tail).
    {
        if (current->data == data)
        {
            return position;  //Dato encontrado, devuelve la posición.
        }
        current = current->next;
        position++;
    }

    return -1; // Si no encuentra el dato, devuelve -1.
}