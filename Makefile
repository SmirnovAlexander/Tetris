CC=g++
CFLAGS=-std=c++11 -lncurses -ltinfo
SOURCES=src/main.cpp src/functions.cpp
SOURCES_TEST=src/functions.cpp test/tests.cpp
EXECUTABLE=bin/tetris
EXECUTABLE_TESTS=bin/tests

all: 
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

test:
	$(CC) $(SOURCES_TEST) -o $(EXECUTABLE_TESTS) && ./$(EXECUTABLE_TESTS)

.PHONY: all test clean
