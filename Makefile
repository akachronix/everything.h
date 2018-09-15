CC=g++
CXXFLAGS=-std=c++11 -Iinclude -Llib -Wall -pedantic -g
CXXLDFLAGS=-leverything -static

TARGET=test

all: clean libeverything.a test.o
	mkdir bin obj lib
	mv *.o obj
	mv *.a lib
	$(CC) $(CXXFLAGS) -s obj/test.o -o bin/$(TARGET) $(CXXLDFLAGS)

libeverything.a: libinput.o liblog.o libmath.o librandom.o
	ar rcs $@ $^

test.o: src/test.cpp
	$(CC) $(CXXFLAGS) -c $^

libinput.o: src/libinput.cpp
	$(CC) $(CXXFLAGS) -c $^

liblog.o: src/liblog.cpp
	$(CC) $(CXXFLAGS) -c $^

libmath.o: src/libmath.cpp
	$(CC) $(CXXFLAGS) -c $^

librandom.o: src/librandom.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	if [ -d bin ]; then rm -rf bin; fi
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d lib ]; then rm -rf lib; fi
