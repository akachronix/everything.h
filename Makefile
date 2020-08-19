CC=g++
CXXFLAGS=-Wall -pedantic -O2
CXXLDFLAGS=
CXXSTD=-std=c++14

BINDIR=bin
INCLUDEDIR=include
LIBDIR=lib
OBJDIR=obj
SRCDIR=src

TARGET=brisk-test

.PHONY: clean

all: $(TARGET)

$(TARGET): clean test.o
	mkdir $(BINDIR) $(OBJDIR)
	mv *.o $(OBJDIR)
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) $(OBJDIR)/$(word 2, $^) -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)
	strip -s $(BINDIR)/$(TARGET)

test.o: $(SRCDIR)/test.cpp
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log build/
