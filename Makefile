CC=g++
CXXFLAGS=-Iinclude -Llib -std=c++11 -Wall -pedantic -g -s

all: clean everything_lib test.o liblog.o libmath.o
	mkdir bin obj lib
	mv *.o obj
	mv *.a lib
	$(CC) $(CXXFLAGS) -s obj/test.o -o bin/test -leverything -static

everything_lib: liblog.o libmath.o libinput.o
	ar rcs libeverything.a liblog.o libmath.o libinput.o

test.o: src/test.cpp
	$(CC) $(CXXFLAGS) -c src/test.cpp

liblog.o: src/liblog.cpp
	$(CC) $(CXXFLAGS) -c src/liblog.cpp

libmath.o: src/libmath.cpp
	$(CC) $(CXXFLAGS) -c src/libmath.cpp

libinput.o: src/libinput.cpp
	$(CC) $(CXXFLAGS) -c src/libinput.cpp

clean:
	if [ -d bin ]; then rm -rf bin; fi
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d lib ]; then rm -rf lib; fi
