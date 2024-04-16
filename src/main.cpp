//main.cpp - the main entrypoint of the application

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <iomanip>
#include <csignal>

#include "input.h"
#include "app.h"
#include "gl_renderer.h"
#include "util.h"
#include "OpticalObject.h"
#include "Scene.h"

// Function declarations
void setWindowHints();
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
    // return myApp.exec();

    
    myApp.init();
    // Assuming myApp.getViewportScale() returns a float or double
    std::cout << "Viewport Scale: " << std::fixed << std::setprecision(1) << myApp.getViewportScale() << std::endl;


    Scene scene;
    scene.addObject(OpticalObject(100, 100));
    scene.addObject(OpticalObject(200, 300));
    scene.addObject(OpticalObject(400, 200));

    scene.printObjects();



    // Set up signal handler
    std::signal(SIGINT, signalHandler);

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    setWindowHints();
    GLFWwindow* window = createWindow(screenWidth, screenHeight, "GraphicsApp");
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    initializeGLAD();
    loadShaders();
    printMonitorInfo();
    initBuffers();

    // doTextureThing();

    // Set input callback functions
    glfwSetMouseButtonCallback(window, mouse_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);


    // Variables for FPS calculation
    double lastTime = glfwGetTime();
    int nbFrames = 0;

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Measure time
        double currentTime = glfwGetTime();
        nbFrames++;

        // If 1 second has passed
        if (currentTime - lastTime >= 1.0) {
            // Display FPS
            std::cout << "FPS: " << nbFrames << std::endl;
            nbFrames = 0;
            lastTime += 1.0;
        }

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
    std::cout << "\nCtrl+C pressed, shutting down..." << std::endl;
    glfwTerminate(); // Terminate GLFW
    exit(signum);    // Terminate the program
}

void setWindowHints() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif


    glfwWindowHint(GLFW_SAMPLES, 8);
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