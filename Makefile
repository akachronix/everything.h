CC=g++
CXXFLAGS=-Wall -pedantic
CXXLDFLAGS=

STD=c++17

BINDIR=bin
INCLUDEDIR=include
LIBDIR=lib
OBJDIR=obj

TARGET=test

all: $(TARGET)

$(TARGET): clean test.o
	mkdir $(BINDIR) $(OBJDIR)
	mv *.o $(OBJDIR)
	$(CC) -std=$(STD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -g -s $(OBJDIR)/test.o -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)

test.o: src/test.cpp
	$(CC) -std=$(STD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log
