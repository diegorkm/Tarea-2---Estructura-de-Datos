/**
 * @file lru_add_remove_node.c
 * @brief Implementación de la función para remover un nodo de la lista doblemente enlazada de la caché LRU.
 *
 * Esta función ajusta los punteros 'prev' y 'next' de los nodos adyacentes al nodo
 * que se desea remover, garantizando que la lista se mantenga coherente. También
 * actualiza los punteros 'head' y 'tail' del caché si el nodo removido era uno de ellos.
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
 * @brief Remueve un nodo específico de la lista doblemente enlazada del caché.
 *
 * La remoción funciona ajustando los punteros del nodo anterior y posterior
 * al nodo dado. También maneja los casos especiales donde el nodo a remover
 * es el 'head' (MRU) o el 'tail' (LRU) de la caché.
 *
 * @param cache Puntero a la estructura LRUCache.
 * @param node Puntero al nodo que se desea desvincular de la lista.
 * @return void No retorna valor.
 */
void remove_node (LRUCache* cache, Node* node)
{

    //Manejo del puntero 'PREV' (Ajuste del nodo anterior)
    
    if (node -> prev != NULL) //Si el nodo a remover no es el head
    {
        node->prev->next = node->next;// el anterior pasa al siguiente
    } 
    else  //Si el nodo a remover es el head, el siguiente nodo se convierte en el nuevo head (MRU)
    {
        cache->head = node->next;
    }
    if(node -> next != NULL)  // Si el nodo a remover NO es el tail (tiene un nodo siguiente)
    {
        node->next->prev = node->prev; // el siguiente apunta al anterior
    } 
    else 
    {
        cache->tail = node->prev; // si es tail, el anterior es el nuevo tail
    }
    cache->current_size--;
}
