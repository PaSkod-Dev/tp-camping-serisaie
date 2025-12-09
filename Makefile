CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99

SRC = src/main.c src/types_emplacement.c
OBJ = $(SRC:.c=.o)
TARGET = cerisaie_types_emplacement

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)