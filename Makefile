CC=g++
CFLAGS=-lncurses
SOURCES=src/main.cpp src/functions.cpp
SOURCES_TEST=src/functions.cpp test/tests.cpp
EXECUTABLE=bin/tetris
EXECUTABLE_TESTS=bin/tests

all: 
	$(CC) -o $(EXECUTABLE) $(SOURCES) $(CFLAGS) 

test:
	$(CC) -o $(EXECUTABLE_TESTS) $(SOURCES_TEST) && ./$(EXECUTABLE_TESTS)

.PHONY: all test clean
