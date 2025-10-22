# =================================================================
# Variables de Configuración
# =================================================================

TARGET = lru
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

# 🆕 Carpetas de Salida
BIN_DIR = bin
OBJ_DIR = obj

# Archivos fuente (.c)
SRCS = lru.c lru_add.c lru_add_buscar_nodo.c lru_add_inicio.c lru_add_remove_node.c lru_all.c lru_get.c lru_menu.c lru_node_create.c lru_search.c lru_free.c

# 🆕 Archivos objeto con la ruta de la carpeta obj/
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# =================================================================
# Reglas de Compilación
# =================================================================

# Regla 'all' depende de que existan las carpetas y el ejecutable
all: $(BIN_DIR) $(OBJ_DIR) $(BIN_DIR)/$(TARGET)

# 🆕 Regla para crear la carpeta de salida 'bin'
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# 🆕 Regla para crear la carpeta de salida 'obj'
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 🆕 Regla principal para enlazar el ejecutable
# El ejecutable se guarda en bin/
$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# 🆕 Regla de Patrón para compilar archivos .c a .o
# El archivo .o se guarda en obj/
$(OBJ_DIR)/%.o: %.c lru.h
	$(CC) $(CFLAGS) -c $< -o $@

# =================================================================
# Reglas Auxiliares
# =================================================================

# 🆕 Regla 'clean' limpia las carpetas de salida
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(BIN_DIR)/$(TARGET)

.PHONY: all clean run
