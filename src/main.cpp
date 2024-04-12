//main.cpp - the main entrypoint of the application

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <iomanip>
#include <csignal>

#include "input.h"
#include "app.h"
#include "graphics.h"
#include "util.h"

// Function declarations
void initializeGLFW();
GLFWwindow* createWindow(int width, int height, const char* title);

// settings
const unsigned int screenWidth = 800;
const unsigned int screenHeight = 600;

const unsigned int minimumWidth = 420;
const unsigned int minimumHeight = 211;

// Signal handler function
void signalHandler(int signum);

int main(void) {
    App myApp;
    myApp.init();
    // Assuming myApp.getViewportScale() returns a float or double
    std::cout << "Viewport Scale: " << std::fixed << std::setprecision(1) << myApp.getViewportScale() << std::endl;

    // Set up signal handler
    std::signal(SIGINT, signalHandler);

    initializeGLFW();
    GLFWwindow* window = createWindow(screenWidth, screenHeight, "Lookdraw");
    initializeGLAD();
    loadShaders();
    printMonitorInfo();
    initBuffers();

    // doTextureThing();

    // Set input callback functions
    glfwSetMouseButtonCallback(window, mouse_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        draw();
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void signalHandler(int signum) {
    std::cout << "\nCtrl+C pressed, shutting down gracefully..." << std::endl;
    glfwTerminate(); // Terminate GLFW
    exit(signum);    // Terminate the program
}

void initializeGLFW() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
}

GLFWwindow* createWindow(int width, int height, const char* title) {
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(-1);
    }

    // Set minimum window size
    glfwSetWindowSizeLimits(window, minimumWidth, minimumHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}