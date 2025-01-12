# Makefile for compiling stack.c

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = hashmap

# Source files
SRCS = hashmap.c

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

