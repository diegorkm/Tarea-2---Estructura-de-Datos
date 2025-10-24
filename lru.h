/**
 * @file lru.h
 * @brief Archivo de cabecera principal para el sistema de Caché LRU.
 *
 * Contiene las definiciones de las estructuras de datos (Node y LRUCache) y
 * los prototipos de todas las funciones que componen el mecanismo del caché,
 * Siguiendo la normativa de codificación y modularidad del proyecto.
 *
 * @authors - Diego Peralta
 *          - Sebastian Ramirez
 *          - Rodolfo Aguilar
 *          - Benjamin Reyes
 */

#ifndef LRU_H
#define LRU_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 


/**
 * @struct Node
 * @brief Representa un nodo en la lista doblemente enlazada de la caché.
 *
 * Los nodos almacenan el dato y los punteros para la gestión de la prioridad.
 */

typedef struct Node
{
    char data; 
    struct Node* prev;  // Puntero al nodo anterior
    struct Node* next;  // Puntero al nodo siguiente
}
Node;

/**
 * @struct LRUCache
 * @brief Estructura principal que define la caché LRU.
 *
 * Contiene los metadatos y los punteros a los extremos de la lista de prioridad.
 */

typedef struct LRUCache
{
    int capacity;       // Capacidad maxima
    int current_size;   // Cuántos elementos hay ahora
    Node* head;         // Nodo mas reciente (MRU)
    Node* tail;         // Nodo menos reciente (LRU)
}
LRUCache;

/**
 * @brief Crea e inicializa una nueva estructura LRUCache.
 *
 * @param capacity La capacidad máxima deseada para el caché (debe ser >= 5).
 * @return LRUCache* Puntero a la caché recién creada, o NULL si la capacidad es inválida o la asignación de memoria falla.
 */
LRUCache* create_cache(int capacity);

/**
 * @brief Crea un nuevo nodo (Node) con el dato especificado.
 *
 * @param data El carácter (letra mayúscula) a almacenar en el nodo.
 * @return Node* Puntero al nodo creado, o NULL si la asignación de memoria falla.
 */
Node* create_node(char data);

/**
 * @brief Busca un nodo específico en la caché por su dato.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param data El dato (letra) a buscar.
 * @return Node* Puntero al nodo encontrado, o NULL si el dato no está presente en la caché.
 */
Node* buscar_nodo(LRUCache* cache, char data);

/**
 * @brief Elimina un nodo de su posición actual en la lista doblemente enlazada.
 *
 * Esta función ajusta los punteros 'prev' y 'next' de los nodos adyacentes
 * y actualiza el head/tail si el nodo removido era uno de los extremos.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param node Puntero al nodo a remover.
 */
void remove_node(LRUCache* cache, Node* node);

/**
 * @brief Añade un nodo al inicio de la lista doblemente enlazada (posición MRU).
 *
 * Esta función establece el nodo como el nuevo head de la caché.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param node Puntero al nodo a insertar.
 */
void add_inicio(LRUCache* cache, Node* node);

/**
 * @brief Muestra el menú de comandos disponibles para el usuario.
 */
void menu();

/**
 * @brief Implementa la lógica de añadir un dato al caché.
 *
 * Si el dato existe, se promueve a MRU. Si no existe, se añade a MRU,
 * y se elimina el LRU si la caché está llena.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param data El dato (letra) a añadir.
 */
void add_data(LRUCache* cache, char data);

/**
 * @brief Implementa la lógica de "usar" un dato.
 *
 * Si el dato existe (cache hit), se promueve a la posición MRU (head).
 * Si no existe (cache miss), no se realiza ninguna acción.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param data El dato (letra) a usar.
 */
void get_data(LRUCache* cache, char data);

/**
 * @brief Busca un dato en la caché e indica su posición.
 *
 * Esta función no altera la prioridad del dato.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param data El dato (letra) a buscar.
 * @return int La posición del dato (1-basada) en la lista, o -1 si no se encuentra.
 */
int search_cache(LRUCache* cache, char data);

/**
 * @brief Muestra el contenido completo de la caché desde MRU a LRU.
 *
 * @param cache Puntero a la estructura LRUCache.
 */
void display_cache(LRUCache* cache);

/**
 * @brief Libera toda la memoria dinámica asociada al caché.
 *
 * Libera los nodos de la lista y la estructura LRUCache en sí misma. 
 *
 * @param cache Puntero a la estructura LRUCache a liberar.
 */
void free_cache(LRUCache* cache);

#endif
