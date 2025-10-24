/**
 * @file lru_add.c
 * @brief Implementación de la función principal para añadir (o usar) un dato en la caché LRU.
 *
 * Esta función aplica la lógica central del algoritmo LRU: maneja los "Cache Hits"
 * (promoviendo el nodo al MRU) y los "Cache Misses" (añadiendo el nuevo nodo al MRU
 * y eliminando el nodo LRU si la caché está llena).
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
 * @brief Añade un dato a la caché LRU, siguiendo la política de reemplazo.
 *
 * Los casos manejados son:
 * 1. **Cache Hit:** Si el dato existe, se remueve de su posición y se inserta al inicio (MRU).
 * 2. **Cache Miss (Lleno):** Si el dato no existe y la caché está llena, se elimina el nodo
 * LRU (tail), y luego se añade el nuevo nodo al inicio (MRU).
 * 3. **Cache Miss (Hay espacio):** Si el dato no existe y hay espacio, se añade directamente al inicio (MRU).
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param data El carácter (letra) a añadir o usar.
 * @return void No retorna valor.
 */
void add_data(LRUCache* cache, char data) 
{   //Verificación inicial del cache
    if (cache == NULL || cache->capacity == 0) 
    {
        printf("Error: El cache no ha sido inicializado.\n");
        return;
    }
    //Revisa si existe el nodo en el cache
    Node* existente = buscar_nodo(cache, data);
    if (existente != NULL) //Ya existe el elemento
    {   //Se quita de su posición y se mueve al inicio
        remove_node(cache, existente);
        add_inicio(cache, existente);
        printf("\nElemento %c ya existe, movido a inicio.\n", data);
        return;
    } 
    //Si el cache esta lleno, requiere reemplazo
    if (cache->current_size >= cache->capacity) 
    {   //Se identifica el LRU, que es el tail
        Node* lru = cache->tail;
        char dato_eliminado = lru->data;
        //Se desvincula el nodo LRU y se libera su memoria.
        remove_node(cache, lru);
        free(lru);
        printf("\nElemento %c eliminado (cache lleno)\n", dato_eliminado);
    }
    //Crea un nuevo nodo (aplica si habia espacio o si se acaba de liberar espacio)
    Node* nuevo_nodo = create_node(data);
    if(nuevo_nodo == NULL) 
    {
        printf("Error al crear el nodo\n");
        return;
    }
    //El nuevo nodo se añade al inicio (MRU)
    add_inicio(cache, nuevo_nodo);
    printf("\nElemento %c anyadido al cache.\n", data);
}
