CC=g++
CXXFLAGS=-Wall -pedantic
CXXLDFLAGS=-pthread

BINDIR=bin
INCLUDEDIR=include
LIBDIR=lib
OBJDIR=obj

TARGET=test

all: $(TARGET)

$(TARGET): clean test.o
	mkdir $(BINDIR) $(OBJDIR)
	mv *.o $(OBJDIR)
	$(CC) -std=c++17 -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -g -s $(OBJDIR)/$(word 2, $^) -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)

test.o: src/test.cpp
	$(CC) -std=c++17 -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log
