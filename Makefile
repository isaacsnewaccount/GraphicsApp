cxx=g++
srcDir=src
cxxFlags=-Wall -std=c++11 

# Source files
sources = src/main.cpp src/message.cpp

#Object files
objects = $(sources:.cpp=.o)

executableName=lookdraw



#Includes and static binary inclusions

glfwIncludeDirectory = deps/GLFW/include
glfwLibraryDirectory = deps/GLFW/lib
gladIncludeFolder = deps/glad/include




cxxFlags=-Wall -std=c++11 -I$(glfwIncludeDirectory) -I$(gladIncludeFolder)
LDflags=-L$(glfwLibraryDirectory) -lglfw3


# #Main rule
# all: $(sources) $(executableName)


# # $@ is a special automatic variable in Makefiles that represents the target of the rule. In this case, it represents the executable target specified by $(EXECUTABLE).
# $(executableName): $(objects)
# 	$(cxx) $(objects) $(LDflags) -o $@

# #This is a suffix rule which will apply to all in "sources???"
# .cpp.o:
# 	$(cxx) $(cxxFlags) -c $< -o $@



lookdraw: main.o message.o
	$(cxx) main.o message.o $(LDflags) -o lookdraw

main.o: src/main.cpp
	$(cxx) -c src/main.cpp $(cxxFlags)

message.o: src/message.cpp src/message.h
	$(cxx) -c src/message.cpp $(cxxFlags)

clean:
	rm -f main.o message.o lookdraw