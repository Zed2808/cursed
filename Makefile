#
# 'make'	build executable file 'GUI'
# 'make clean'	removes all object and executable files
#



CC = g++
CFLAGS = -Wall -c
INCLUDES =
LFLAGS =
LIBS =
OBJS = obj/main.o obj/gui.o obj/player.o obj/enemy.o obj/wolf.o

ifeq ($(OS),Windows_NT)
	LFLAGS += -static-libgcc -static-libstdc++
	LIBS += -lpdcurses
	EXECUTABLE += cursed.exe
else
	LIBS += -lncurses
	EXECUTABLE += cursed
endif

all:	$(EXECUTABLE)
	@echo -= Executable $(EXECUTABLE) has been successfully compiled. =-

$(EXECUTABLE): $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS) $(LIBS)

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/gui.o: src/gui.cpp src/gui.h
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/player.o: src/player.cpp src/player.h
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/enemy.o: src/enemy.cpp src/enemy.h
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/wolf.o: src/wolf.cpp src/wolf.h
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS) $(EXECUTABLE)
	@echo -= Objects files and executable successfully removed. =-
