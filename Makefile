CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Isrc/include
SRC = src/main.c src/types_emplacement.c
OBJ = $(SRC:.c=.o)
TARGET = cerisaie_types_emplacement

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	-@del /Q src\main.o src\types_emplacement.o cerisaie_types_emplacement.exe 2>nul || exit 0