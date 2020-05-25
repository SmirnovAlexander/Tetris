CC=g++
CFLAGS=-lncurses
SOURCES=main.cpp
EXECUTABLE=tetris

all: 
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)
