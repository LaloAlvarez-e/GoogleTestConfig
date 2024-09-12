# Variables
CC = gcc
CFLAGS = -Wall -Werror
SRC = sum.c main.c
OBJ = $(SRC:.c=.o)
TARGET = build/main

# Directories
BUILD_DIR = build

# Rules
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(OBJ)

.PHONY: all clean# Variables
CC = gcc
CFLAGS = -Wall -Werror
SRC = sum.c main.c
OBJ = $(SRC:.c=.o)
TARGET = build/main

# Directories
BUILD_DIR = build

# Rules
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(OBJ)

.PHONY: all clean