cxx=g++
cc=gcc

#Includes
glfwIncludeFolder = deps/GLFW/include
#glewIncludeFolder = deps/glew-2.1.0/include
gladIncludeFolder = deps/glad/include

#Static binary inclusions
glfwLibraryFolder = deps/GLFW/lib
#glewLibraryFolder = deps/glew-2.1.0/lib


cxxFlags=-Wall -std=c++11 -I$(glfwIncludeFolder) -I$(gladIncludeFolder)
LDflags=-L$(glfwLibraryFolder) -lglfw3 -lGL -lGLU

ccFlags=-Wall -I$(glfwIncludeFolder) -I$(gladIncludeFolder)
#-lGL -lGLU is for openGL


lookdraw: main.o message.o glad.o
	$(cxx) main.o message.o glad.o $(LDflags) -o lookdraw

main.o: src/main.cpp
	$(cxx) -c src/main.cpp $(cxxFlags)

message.o: src/message.cpp src/message.h
	$(cxx) -c src/message.cpp $(cxxFlags)

glad.o: deps/glad/src/glad.c
	$(cc) -c deps/glad/src/glad.c $(ccFlags)

clean:
	rm -f main.o message.o glad.o lookdraw