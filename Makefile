CC=g++
CXXFLAGS=-Iinclude -Llib -std=c++11 -Wall -pedantic -g

all: clean libeverything.a test.o
	mv *.o obj
	mv *.a lib
	$(CC) $(CXXFLAGS) -s obj/test.o -o bin/test -leverything -static

libeverything.a: liblog.o libmath.o libinput.o
	ar rcs $@ liblog.o libmath.o libinput.o

test.o: src/test.cpp
	$(CC) $(CXXFLAGS) -c $^

liblog.o: src/liblog.cpp
	$(CC) $(CXXFLAGS) -c $^

libmath.o: src/libmath.cpp
	$(CC) $(CXXFLAGS) -c $^

libinput.o: src/libinput.cpp
	$(CC) $(CXXFLAGS) -c $^

clean:
	if [ -d bin ]; then rm -rf bin; fi
	if [ -d obj ]; then rm -rf obj; fi
	if [ -d lib ]; then rm -rf lib; fi
	mkdir bin obj lib
