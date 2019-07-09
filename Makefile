CC=g++
CXXFLAGS=-Wall -pedantic
CXXLDFLAGS=-pthread
CXXSTD=-std=c++14

BINDIR=bin
INCLUDEDIR=include
LIBDIR=lib
OBJDIR=obj
SRCDIR=src

TARGET=test

all: $(TARGET)

$(TARGET): clean test.o
	mkdir $(BINDIR) $(OBJDIR)
	mv *.o $(OBJDIR)
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -g -s $(OBJDIR)/$(word 2, $^) -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)

test.o: $(SRCDIR)/test.cpp
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log build/
