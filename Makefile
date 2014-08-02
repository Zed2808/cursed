CC = g++
CFLAGS = -Wall -c
LFLAGS = -lncurses
EXECUTABLE = GUI
OBJS = gui.o

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $@

gui.o: gui.h gui.cpp
	$(CC) $(CFLAGS) gui.cpp

clean:
	rm -rf $(OBJS) $(EXECUTABLE)
