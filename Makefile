#
# 'make'	build executable file 'GUI'
# 'make clean'	removes all object and executable files
#



CC = g++
CFLAGS = -Wall -c
INCLUDES =
LFLAGS =
LIBS =
OBJS = obj/main.o obj/gui.o obj/inventory.o obj/items.o obj/character.o obj/player.o obj/wolf.o

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

obj/gui.o: src/gui.cpp src/gui.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/inventory.o: src/inventory.cpp src/inventory.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/items.o: src/items.cpp src/items.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/character.o: src/character.cpp src/character.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/player.o: src/player.cpp src/player.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/wolf.o: src/wolf.cpp src/wolf.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS) $(EXECUTABLE)
	@echo -= Objects files and executable successfully removed. =-
