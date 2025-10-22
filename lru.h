#ifndef LRU_H
#define LRU_H

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 



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

LRUCache* create_cache(int capacity);
Node* create_node(char data);
Node* buscar_nodo(LRUCache* cache, char data);
void remove_node(LRUCache* cache, Node* node);
void add_inicio(LRUCache* cache, Node* node);
void menu();
void add_data(LRUCache* cache, char data);
void get_data(LRUCache* cache, char data);
int search_cache(LRUCache* cache, char data);
void display_cache(LRUCache* cache);
void free_cache(LRUCache* cache);

#endif
