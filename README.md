# Lookdraw

Dependencies:

glm

glad

glfw 3.4. Other versions such as 3.3 may work.

Tested on Ubuntu/Kubuntu 22.04

The dependencies are local to the project and statically linked for greater portability.

## License
All copyright and intellectual property rights pertaining to the materials, content, and any associated creations herein are owned by Isaacsnewaccount under jurisdiction of U.S copyright law. Noncommercial personal use is permitted.

## Build setup
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

sudo apt install xorg-dev

sudo apt install libwayland-dev libxkbcommon-dev wayland-protocols extra-cmake-modules

#### Generating build files
cd into the glfw directory, which is the one with "docs", "tests", "src", "include", and more files. In my case the directory is named glfw-3.4 after unzipping.

run:

cmake -S . -B build


then cd into the "build" folder and run "make":

cd build

make

get the glfw3.h and glfw3native.h files and put them in lookdraw's deps/GLFW/include folder.

on linux, get the libglfw3.a file and put it in lookdraw's deps/GLFW/lib folder.


## Building
type "make" at the terminal

to run, type "./lookdraw"
