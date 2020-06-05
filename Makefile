CC=g++
CXXFLAGS=-Wall -pedantic -O2
CXXLDFLAGS=-pthread
CXXSTD=-std=c++14

BINDIR=bin
INCLUDEDIR=include
LIBDIR=lib
OBJDIR=obj
SRCDIR=src

TARGET=brisk-test

.PHONY: clean meson-build

all: $(TARGET)

$(TARGET): clean test.o
	mkdir $(BINDIR) $(OBJDIR)
	mv *.o $(OBJDIR)
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) $(OBJDIR)/$(word 2, $^) -o $(BINDIR)/$(TARGET) $(CXXLDFLAGS)
	strip -s $(BINDIR)/$(TARGET)

test.o: $(SRCDIR)/test.cpp
	$(CC) $(CXXSTD) -I$(INCLUDEDIR) -L$(LIBDIR) $(CXXFLAGS) -c $^

meson-build: clean $(SRCDIR)/test.cpp
	mkdir build; \
	meson build; \
	cd build; \
	ninja; \

clean:
	rm -rf $(BINDIR) $(OBJDIR) *.log build/
