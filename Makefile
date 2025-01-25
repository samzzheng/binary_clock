# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lncurses

# Targets and files
TARGET = clock
SRC = main.c display.c
OBJ = $(SRC:.c=.o)

# Raspberry Pi configuration (if needed)
FLAVOR = mac
INCLUDE_PI = -I/usr/include/ncurses
LDFLAGS_PI = -lwiringPi

ifeq ($(FLAVOR),pi)
    INCLUDE = $(INCLUDE_PI)
    LDFLAGS = $(LDFLAGS_PI)
endif

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ $^ $(LDFLAGS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# Ensure `clock.sh` is executable, then run it
run: $(TARGET)
	chmod +x clock.sh
	./clock.sh | ./$(TARGET)

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)