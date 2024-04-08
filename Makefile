#LDFLAGS is also called linkerFlags
cxx=g++
srcDir=src
#includedFolders=-I.
#optimization=-O0


#cppFiles=main.cpp message.cpp
#objects=main.o message.o
#program=lookdraw



glfwIncludeDirectory = deps/GLFW/include
glfwLibraryDirectory = deps/GLFW/lib

cxxFlags=-Wall -I$(glfwIncludeDirectory)
linkerFlags=-L$(glfwLibraryDirectory) -lglfw3


default: lookdraw

lookdraw: main.o message.o
	$(cxx) main.o message.o $(linkerFlags) -o lookdraw

main.o: src/main.cpp
	$(cxx) -c src/main.cpp $(cxxFlags)

message.o: src/message.cpp src/message.h
	$(cxx) -c src/message.cpp $(cxxFlags)

clean:
	rm -f main.o message.o lookdraw