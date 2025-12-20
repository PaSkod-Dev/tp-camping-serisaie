
# Makefile - Camping "La Cerisaie"
# Gestion des types d'emplacement
# AUTHORS : SEWONOU Pascal & EDOH BEDI Komi Godwin
# CREATED : 09/12/2025
# UPDATED : 20/12/2025

# Configuration du compilateur
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Isrc/include

# Fichiers sources, objets et cible
SRC = src/main.c src/types_emplacement.c
OBJ = src/main.o src/types_emplacement.o
TARGET = cerisaie_types_emplacement.exe

# Regles de compilation

# Regle par defaut : compiler le programme
all: $(TARGET)

# Compilation du programme (lien des objets)
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compilation des fichiers objets
src/main.o: src/main.c src/include/types_emplacement.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/types_emplacement.o: src/types_emplacement.c src/include/types_emplacement.h
	$(CC) $(CFLAGS) -c src/types_emplacement.c -o src/types_emplacement.o

# Nettoyage des fichiers generes
# Compatible Git Bash (rm) et Windows CMD (del)
clean:
	-@rm -f $(TARGET) $(OBJ) 2>/dev/null || del /Q $(TARGET) src\*.o 2>nul || true

# Execution du programme
run: $(TARGET)
	./$(TARGET)

# Regles speciales
.PHONY: all clean run

# FIN DU FICHIER Makefile