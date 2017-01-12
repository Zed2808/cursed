#
# 'make'        build executable file 'GUI'
# 'make clean'  removes all object and executable files
# 'make run'    make && ./cursed
# 'make fresh'  make clean && make && ./cursed
# 'make debug'  compile with -g flag
#



CC = g++
CFLAGS = -std=c++11 -Wall -c
INCLUDES =
LFLAGS =
LIBS =
OBJS = obj/attacks.o obj/character.o obj/flow.o obj/gui.o obj/interaction.o obj/inventory.o obj/items.o obj/log.o obj/main.o obj/maps.o obj/npcs.o obj/player.o obj/tile.o
ifeq ($(OS),Windows_NT)
	LFLAGS += -static-libgcc -static-libstdc++
	LIBS += -lpdcurses
	EXECUTABLE += cursed.exe
else
	LIBS += -lncurses
	EXECUTABLE += cursed
endif

all:	$(EXECUTABLE)
	@echo ===== Executable $(EXECUTABLE) has been successfully compiled. =====

$(EXECUTABLE): $(OBJS)
	$(CC) $(LFLAGS) -o $@ $(OBJS) $(LIBS)

obj/attacks.o: src/attacks.cpp src/attacks.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/character.o: src/character.cpp src/character.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/flow.o: src/flow.cpp src/flow.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/gui.o: src/gui.cpp src/gui.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/interaction.o: src/interaction.cpp src/interaction.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/inventory.o: src/inventory.cpp src/inventory.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/items.o: src/items.cpp src/items.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/log.o: src/log.cpp src/log.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/main.o: src/main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/maps.o: src/maps.cpp src/maps.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/npcs.o: src/npcs.cpp src/npcs.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/player.o: src/player.cpp src/player.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

obj/tile.o: src/tile.cpp src/tile.hpp
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJS) $(EXECUTABLE)
	@echo ===== Objects files and executable successfully removed. =====

run: all
	./cursed

fresh: clean all
	./cursed

debug: CFLAGS += -g
debug: clean all
