#ifndef LRU_H
#define LRU_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

void menu();

typedef struct Node
{
    char data; 
    struct Node* prev;  // Puntero al nodo anterior
    struct Node* next;  // Puntero al nodo siguiente
}
Node;

typedef struct LRUCache
{
    int capacity;       // Capacidad maxima
    int current_size;   // Cuántos elementos hay ahora
    Node* head;         // nodo mas reciente (MRU)
    Node* tail;         // nodo menos reciente (LRU)
}
LRUCache;





#endif