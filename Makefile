CC = gcc

CFLAGS = -W -Wall -Wextra -I./src/headers -D_POSIX_C_SOURCE=200809L --std=c17 -pedantic -Wno-unused-parameter -Wno-unused-variable -Werror

SRC_SRC = src
BUILD_DIR = build

SRC_FILES = src/main.c src/dirReader.c

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

TARGET = dir_reader

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
		mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ_FILES)
		$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.c: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJ_DIR) $(TARGET)

rebuild: clean all

.PHONY: clean rebuild
