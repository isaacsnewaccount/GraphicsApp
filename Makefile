# Compiler and flags
CXX = g++
CC = gcc
CXXFLAGS = -Wall -std=c++11
CFLAGS = -Wall

# Directories
SRC_DIR = src
DEPS_DIR = deps
MAIN_INCLUDE_DIR = $(DEPS_DIR)/include
MAIN_LIB_DIR = $(DEPS_DIR)/lib

# Libraries
LDLIBS = -lglfw3 -lGL -lGLU
LDFLAGS = -L$(MAIN_LIB_DIR)

# Targets
EXECUTABLE = lookdraw
SOURCES = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(DEPS_DIR)/glad/src/glad.c)
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS := $(OBJECTS:.c=.o)

# Rules
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) -I$(MAIN_INCLUDE_DIR)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) -I$(MAIN_INCLUDE_DIR)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)