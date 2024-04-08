#include <iostream>
#include <cstdlib>
// #include <GL/glew.h>
//#include <GL/gl.h> //include system GL (on linux: /usr/include/GL)

#include <GLFW/glfw3.h>

#include "message.h"

using namespace std;

// Function declaration
int add(int a, int b);

int main(void) {
    message message;
    message.printMessage();

    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }


    // GLenum err = glewInit();
    // if (GLEW_OK != err) {
    //     // Problem: glewInit failed, something is seriously wrong.
    //     std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
    // }



    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}



// Function definition
int add(int a, int b) {
    return a + b;
}