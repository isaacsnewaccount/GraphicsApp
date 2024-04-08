# Lookdraw

Dependencies:

glm

glad

glfw 3.4. Other versions such as 3.3 may work.


Tested on Ubuntu/Kubuntu 22.04


## Build setup
### Download GLAD and GLFW

GLAD example link (Download API gl version 4.6 for example):
https://glad.dav1d.de/

https://glad.dav1d.de/#language=c&specification=gl&api=gl%3D4.6&api=gles1%3Dnone&api=gles2%3Dnone&api=glsc2%3Dnone&profile=compatibility&loader=on


GLFW example link:
https://github.com/glfw/glfw/releases/download/3.4/glfw-3.4.zipd


unzip the GLFW download.

make the include folders in the include directory:

sudo mkdir -p /usr/include/GLFW

sudo mkdir -p /usr/include/glad

put glfw3.h and glfw3native.h into the /usr/include/GLFW folder

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


## Building
type "make" at the terminal

to run, type "./lookdraw"