# Variables
CC = gcc
CFLAGS = -Wall -Werror
SRC = sum.c sumTest.cpp
OBJ = $(SRC:.c=.o)
TARGET = build/sumTest

# Directories
BUILD_DIR = build

# Rules
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L/usr/local/lib -lgtest -lpthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -L/usr/local/lib -lgtest -lpthread

clean:
	rm -rf $(BUILD_DIR) $(OBJ)

.PHONY: all clean# Variables
CC = gcc
CFLAGS = -Wall -Werror
SRC = sum.c sumTest.cpp
OBJ = $(SRC:.c=.o)
TARGET = build/sumTest

# Directories
BUILD_DIR = build

# Rules
all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L/usr/local/lib -lgtest -lpthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -L/usr/local/lib -lgtest -lpthread

clean:
	rm -rf $(BUILD_DIR) $(OBJ)

.PHONY: all clean