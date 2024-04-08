cxx=g++
srcDir=src
cxxFlags=-Wall -std=c++11
#-lGL -lGLU is for openGL

# Source files
sources = src/main.cpp src/message.cpp

#Object files
objects = $(sources:.cpp=.o)

executableName=lookdraw



#Includes
glfwIncludeFolder = deps/GLFW/include
glewIncludeFolder = deps/glew-2.1.0/include

#Static binary inclusions
glfwLibraryFolder = deps/GLFW/lib
glewLibraryFolder = deps/glew-2.1.0/lib


cxxFlags=-Wall -std=c++11 -I$(glfwIncludeFolder) -I$(glewIncludeFolder)
LDflags=-L$(glfwLibraryFolder) -lglfw3 -L$(glewLibraryFolder) -lGLEW -lGL -lGLU


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