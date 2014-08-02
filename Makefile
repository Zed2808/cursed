CC = g++
CFLAGS = -Wall -c
LFLAGS = -lncurses
EXECUTABLE = GUI
OBJS = main.o gui.o player.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

gui.o: gui.h gui.cpp
	$(CC) $(CFLAGS) gui.cpp

player.o: player.h player.cpp
	$(CC) $(CFLAGS) player.cpp

clean:
	rm -rf $(OBJS) $(EXECUTABLE)
