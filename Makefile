
#LDFLAGS is also called linkerFlags

cxx=g++
glfwIncludeDirectory = deps/GLFW/include
glfwLibraryDirectory = deps/GLFW/lib

cxxFlags=-Wall -I$(glfwIncludeDirectory)
linkerFlags=-L$(glfwLibraryDirectory) -lglfw3

output: main.o message.o
	$(cxx) main.o message.o $(linkerFlags) -o lookdraw

main.o: main.cpp
	$(cxx) -c main.cpp $(cxxFlags)

message.o: message.cpp message.h
	$(cxx) -c message.cpp $(cxxFlags)

clean:
	rm -f main.o message.o lookdraw







