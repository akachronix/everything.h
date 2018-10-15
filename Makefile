CC=g++
CXXFLAGS=-std=c++11 -Iinclude -Llib -Wall -Werror -pedantic
CXXLDFLAGS=-static

TARGET=test

all: clean test.o
	mkdir bin obj
	$(CC) $(CXXFLAGS) -g -s test.o -o bin/$(TARGET) $(CXXLDFLAGS)
	mv *.o obj

test.o: src/test.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	rm -rf bin obj *.log
