# Nom du compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Repertoires
SRC_DIR = src
BIN_DIR = bin
INC_DIR = include

# Recuperation de tous les fichiers .c dans SRC_DIR
SRC = $(wildcard $(SRC_DIR)/*.c)

# Transformation en fichiers objets (.o)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)

# Nom de l'executable principal
TARGET = $(BIN_DIR)/mon_programme

# Regle par defaut
all: $(TARGET)

# Compilation de l'executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation des fichiers .o
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers compiles
clean:
	rm -f $(BIN_DIR)/*.o $(TARGET)

# Nettoyage complet
fclean: clean
	rm -f $(BIN_DIR)/*

# Recompilation complete
re: fclean all
