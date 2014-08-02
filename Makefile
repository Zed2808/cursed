CC=g++
CFLAGS=-Wall
LDFLAGS=-lncurses
SOURCES=health.cpp
EXECUTABLE=health

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@

clean:
	rm -rf $(EXECUTABLE)
