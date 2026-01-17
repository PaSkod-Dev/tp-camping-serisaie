# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Isrc
OBJ_DIR = build/obj
BIN_DIR = build/bin

# Fichiers source
ENTITIES = src/entities/client/client.c \
           src/entities/sejour/sejour.c \
           src/entities/emplacement/emplacement.c \
           src/entities/emplacement/types_emplacement.c \
           src/entities/sport/sport.c \
           src/entities/location_sport/location_sport.c

SERVICES = src/services/facturation/facturation.c \
           src/services/gestion_sejour/gestion_sejour.c \
           src/services/gestion_location/gestion_location.c

UTILS = src/utils/validation.c \
        src/utils/date_utils.c

UI = src/ui/menu.c \
     src/ui/affichage.c

SOURCES = $(ENTITIES) $(SERVICES) $(UTILS) $(UI) src/main.c
OBJECTS = $(SOURCES:src/%.c=$(OBJ_DIR)/%.o)

# Cible principale
all: $(BIN_DIR)/camping

$(BIN_DIR)/camping: $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean