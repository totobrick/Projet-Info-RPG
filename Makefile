CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -lncurses

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXECUTABLE = exec_TPA

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c Header.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)

