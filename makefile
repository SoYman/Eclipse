VERSION = 0.0.1
CXX = g++
CPPFLAGS = -Wall

BUILDDIR = build
SOURCEDIR = src

SOURCES = $(wildcard *.cpp) $(wildcard */*.cpp)
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

BINARY = eclipse

ECHO = echo
RM = rm -rf
MKDIR = mkdir

.PHONY: all clean setup

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CXX) $(CPPFLAGS) -I $(SOURCEDIR) $(OBJECTS) -o $(BINARY)

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -I $(SOURCEDIR) -c $^ -o $@

$(BUILDDIR)/%.o: $(SOURCEDIR)/utilities/%.cpp
	$(CXX) $(CPPFLAGS) -I $(SOURCEDIR) -c $^ -o $@

$(BUILDDIR)/main.o: $(SOURCEDIR)/main.cpp
	$(CXX) $(CPPFLAGS) -I $(SOURCEDIR) -c $^ -o $@

setup:
	$(MKDIR) -p $(BUILDDIR)

clean:
	$(RM) $(BINARY) $(OBJECTS)

distclean: clean
