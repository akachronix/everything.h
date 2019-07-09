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

.PHONY: clean meson-build

all: $(TARGET)

$(TARGET): clean test.o
	mkdir $(BINDIR) $(OBJDIR)
	mv *.o $(OBJDIR)
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -g -s $(OBJDIR)/$(word 2, $^) -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)

test.o: $(SRCDIR)/test.cpp
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

meson-build: clean $(SRCDIR)/test.cpp
	mkdir build; \
	meson build; \
	cd build; \
	ninja; \

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log build/
