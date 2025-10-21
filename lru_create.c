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
        printf("El tamaño minimo del caché es 5.\n");
        return NULL;
    }

    LRUCache* cache = (LRUCache*) malloc(sizeof(LRUCache));
    if (cache == NULL) {
        printf("Error al asignar memoria para el caché.\n");
        return NULL;
    }

    cache->capacity = capacity;
    cache->current_size = 0;
    cache->head = NULL;
    cache->tail = NULL;

    return cache;
}
