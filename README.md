# GraphicsApp
A graphical application.

Dependencies:

glm, version 1.0.0. Other versions may work.

glad

glfw 3.4. Other versions such as 3.3 may work.

FreeType, testing version 2.10.0

The projct uses CMake to build. Tested with version 3.22.1. Other versions may work. The project originally used Unix Make. The original unix makefiles are available as older git commits.

Tested on Ubuntu/Kubuntu 22.04. Compilers tested for the main program and dependencies are g++ and gcc version 11.40 (Ubuntu 11.4.0-1ubuntu1~22.04).

The dependencies are local to the project and statically linked for greater portability.

A computer capable of running OpenGL 3.3 applications. (The OpenGL 3.3 2010 standard)

## Legal Notice
The authors of this software include the operator of the "Isaacsnewaccount" GitHub account.

All copyright and intellectual property rights pertaining to the materials, content, and any associated creations herein are owned by the authors under jurisdiction of U.S copyright law. Noncommercial personal use and distribution are permitted. Commercial use and distribution are prohibited.

## Build setup
To setup the dependencies from their originally distributed files
### Download GLAD and GLFW

GLAD example link (Download API gl version 4.6 for example):
https://glad.dav1d.de/

https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=compatibility&loader=on


GLFW example link:
https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.zipd


unzip the GLFW download.


optionally build GLFW to replace the .a file for linux development.
GLFW is statically linked in this application.


### Build and install GLFW
#### Dependencies
GLFW requires CMake. Install it.

other deps:
```
sudo apt install xorg-dev

sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules
```
#### Generating build files
cd into the glfw directory, which is the one with "docs", "tests", "src", "include", and more files. In my case the directory is named glfw-3.4 after unzipping.

run:
```
cmake -S . -B build
```
then cd into the "build" folder and run "make":
```
cd build

make
```
get the glfw3.h and glfw3native.h files and put them in GraphicsApp's third-party/include/GLFW/ folder.

on linux, get the libglfw3.a file and put it in GraphicsApp's third-party/lib/ folder.


## Building
Building uses cmake.

make a build folder and cd into it:
```
mkdir build && cd build
```

Then configure the build system using cmake:

```
cmake ..
```

Then type "make" at the terminal

to run, type "./lookdraw"
