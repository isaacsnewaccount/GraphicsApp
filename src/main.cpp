#include <iostream>
//#include <cstdlib>
#include <GLFW/glfw3.h>
#include "message.h"

using namespace std;

bool shouldClose = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_W && action == GLFW_PRESS && mods == GLFW_MOD_CONTROL) {
        shouldClose = true; //exit program flag
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

    // Enable MSAA with 4 samples
    //glfwWindowHint(GLFW_SAMPLES, 4);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Lookdraw", NULL, NULL);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);

    // Make the window's context current
    glfwMakeContextCurrent(window);





    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    //configure lines
    glEnable(GL_LINE_SMOOTH);

    // Querying the range of supported aliased line widths
    GLfloat lineWidthRange[2];
    glGetFloatv(GL_ALIASED_LINE_WIDTH_RANGE, lineWidthRange);

    // Output the retrieved range
    std::cout << "Supported Aliased Line Width Range: [" << lineWidthRange[0] << ", " << lineWidthRange[1] << "]" << std::endl;


    glLineWidth(0.1f); //make the lines thinner (unsupported?)

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window) && !shouldClose) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here
        glBegin(GL_LINES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(-0.5f, -0.5f);
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