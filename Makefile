CC=gcc
CFLAGS=-Wall -std=c99
LDFLAGS=-lncurses
SOURCES=health.c
EXECUTABLE=health

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

clean:
	rm -rf $(EXECUTABLE)
