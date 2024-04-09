#include <iostream>
#include <cstdlib>
// #include <GL/glew.h>
//#include <GL/gl.h> //include system GL (on linux: /usr/include/GL)

#include <GLFW/glfw3.h>

#include "message.h"

using namespace std;

// Function declaration
int add(int a, int b);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && action == GLFW_PRESS && mods == GLFW_MOD_CONTROL) {
        std::cout << "Control+W pressed" << std::endl;
    }
}


int main(void) {
    message message;
    message.printMessage();


    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Window", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    // Set key callback
    glfwSetKeyCallback(window, key_callback);

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

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