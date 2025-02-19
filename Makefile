CC = GCC

CFLAGS = -Wall -Wextra -I./src/headerd

SRC_DIR = src
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/dirReader.c

OBJ_FILES = $(SRC_FILES:.c=.o)

TARGET = dir_reader

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(TARGET)

rebuild: clean all

.PHONY: clean rebuild

