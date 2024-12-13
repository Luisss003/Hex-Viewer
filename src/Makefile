# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executable
TARGET = program

# Object files
OBJS = main.o operations.o utils.o

# Default target
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
main.o: main.c operations.h utils.h constants.h
	$(CC) $(CFLAGS) -c main.c

operations.o: operations.c operations.h constants.h
	$(CC) $(CFLAGS) -c operations.c

utils.o: utils.c utils.h constants.h
	$(CC) $(CFLAGS) -c utils.c

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

