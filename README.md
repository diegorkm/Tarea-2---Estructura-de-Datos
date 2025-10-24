# Caché LRU - Implementación en C

## Descripción General

Este proyecto implementa un **sistema de Caché LRU (Least Recently Used)** utilizando una estructura de datos de **lista doblemente enlazada** en lenguaje C.

## Autores

- Diego Peralta
- Sebastian Ramirez
- Rodolfo Aguilar
- Benjamin Reyes

## Características Principales

### Estructuras de Datos

El sistema se compone de dos estructuras principales:

- **Node**: Representa un nodo individual en la lista doblemente enlazada
- **LRUCache**: Estructura principal que gestiona el caché

### Operaciones Soportadas

| Operación | Descripción |
|-----------|-------------|
| `create <n>` | Crea un caché con capacidad n (mínimo 5) |
| `add <x>` | Añade o promueve el elemento x al MRU |
| `get <x>` | Usa el elemento x, promoviéndolo al MRU |
| `search <x>` | Busca x sin alterar su prioridad |
| `all` | Muestra el contenido completo del caché |
| `exit` | Libera memoria y termina el programa |

## Arquitectura del Sistema

### Política LRU

El algoritmo **Least Recently Used** mantiene los elementos más recientemente usados al inicio de la lista (MRU - Most Recently Used) y los menos usados al final (LRU - Least Recently Used).

**Comportamiento:**
- **Cache Hit**: Si el elemento existe, se mueve al inicio (MRU)
- **Cache Miss**: Si no existe y hay espacio, se añade al inicio
- **Reemplazo**: Si el caché está lleno, se elimina el LRU (tail) antes de añadir

### Diagrama de Flujo
```
MRU (head) ←→ [Nodo 1] ←→ [Nodo 2] ←→ ... ←→ [Nodo N] ←→ LRU (tail)
     ↑                                                      ↑
  Más reciente                                      Menos reciente
```

## Estructura de Archivos

| Archivo | Propósito |
|---------|-----------|
| `lru.h` | Definiciones de estructuras y prototipos |
| `lru.c` | Función main y bucle interactivo |
| `lru_node_create.c` | Creación de caché y nodos |
| `lru_add.c` | Lógica de añadir/usar elementos |
| `lru_add_buscar_nodo.c` | Búsqueda interna de nodos |
| `lru_add_inicio.c` | Inserción al inicio (MRU) |
| `lru_add_remove_node.c` | Remoción de nodos |
| `lru_get.c` | Uso de elementos existentes |
| `lru_search.c` | Búsqueda de posición |
| `lru_all.c` | Visualización del caché |
| `lru_menu.c` | Menú de comandos |
| `lru_free.c` | Liberación de memoria |

## Compilación y Ejecución

### Requisitos
- Compilador GCC o compatible
- Make (opcional)

### Compilar
```bash
gcc -o lru lru.c lru_add.c lru_add_buscar_nodo.c lru_add_inicio.c \
    lru_add_remove_node.c lru_all.c lru_free.c lru_get.c \
    lru_menu.c lru_node_create.c lru_search.c -Wall
```

### Ejecutar
```bash
./lru
```

## Ejemplo de Uso
```
lru> create 5
Cache creado con tamaño: 5

lru> add A
Elemento A añadido al cache.

lru> add B
Elemento B añadido al cache.

lru> all
Contenido del cache: [B] - [A]

lru> get A
Elemento A encontrado y movido a inicio.

lru> all
Contenido del cache: [A] - [B]

lru> search A
El dato A esta presente en la posicion 1 del cache.

lru> exit
Liberando cache y saliendo del programa
```

## Complejidad Computacional

| Operación | Complejidad |
|-----------|-------------|
| Búsqueda | O(n) |
| Inserción al inicio | O(1) |
| Remoción | O(1) |
| Añadir elemento | O(n) |

## Documentación Adicional

La documentación completa generada con Doxygen se encuentra en la carpeta `doc/html/`.

Para visualizarla, abre el archivo `doc/html/index.html` en tu navegador.

## Generar Documentación
```bash
doxygen Doxyfile
```

## Notas Importantes

- La capacidad mínima del caché es 5 elementos
- Los datos almacenados son caracteres (letras mayúsculas)
- La memoria se libera automáticamente al usar el comando `exit`
- El sistema maneja correctamente casos de caché lleno y vacío

## Manejo de Errores

El sistema incluye validaciones para:
- Capacidad mínima de caché
- Caché no inicializado
- Errores de asignación de memoria
- Operaciones sobre caché vacío

---

**Fecha**: Octubre 2024  
**Versión**: 1.0