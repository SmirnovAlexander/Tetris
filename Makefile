CC=g++
CFLAGS=-lncurses
SOURCES=src/main.cpp src/functions.cpp
SOURCES_TEST=src/functions.cpp test/tests.cpp
BIN=bin
EXECUTABLE=tetris
EXECUTABLE_TESTS=tests

all: 
	mkdir -p $(BIN)
	$(CC) -o $(BIN)/$(EXECUTABLE) $(SOURCES) $(CFLAGS) 

test:
	$(CC) -o $(BIN)/$(EXECUTABLE_TESTS) $(SOURCES_TEST) && ./$(BIN)/$(EXECUTABLE_TESTS)

.PHONY: all test clean
