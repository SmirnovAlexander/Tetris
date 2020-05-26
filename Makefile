CC=g++
CFLAGS=-std=c++11 -lncurses
CTFLAGS=-std=c++11
SOURCES=src/main.cpp src/functions.cpp
SOURCES_TEST=src/functions.cpp test/tests.cpp
BIN=bin
EXECUTABLE=tetris
EXECUTABLE_TESTS=tests

all: 
	mkdir -p $(BIN)
	$(CC) -o $(BIN)/$(EXECUTABLE) $(SOURCES) $(CFLAGS) 

test:
	mkdir -p $(BIN)
	$(CC) -o $(BIN)/$(EXECUTABLE_TESTS) $(SOURCES_TEST) $(CTFLAGS) && ./$(BIN)/$(EXECUTABLE_TESTS)

clean:
	rm -rf $(BIN)

.PHONY: all test clean
