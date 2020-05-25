CC=g++
CFLAGS=-lncurses
SOURCES=src/main.cpp src/functions.cpp
EXECUTABLE=bin/tetris

all: 
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
