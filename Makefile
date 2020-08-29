CC=g++
CXXFLAGS=-Wall -pedantic -O2
CXXLDFLAGS=
CXXSTD=-std=c++14

BINDIR=bin
INCLUDEDIR=include
LIBDIR=lib
OBJDIR=obj
SRCDIR=src

.PHONY: clean

all: clean test.o calc.o
	mkdir $(BINDIR) $(OBJDIR)
	mv *.o $(OBJDIR)
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) $(OBJDIR)/$(word 2, $^) -o $(BINDIR)/brisk-test $(CXXLDFLAGS)
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) $(OBJDIR)/$(word 3, $^) -o $(BINDIR)/brisk-calc $(CXXLDFLAGS)

test.o: $(SRCDIR)/test.cpp
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

calc.o: $(SRCDIR)/calc.cpp
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log build/
