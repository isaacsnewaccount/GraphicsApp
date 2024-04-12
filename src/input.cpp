#include <iostream>
#include <GLFW/glfw3.h>
#include "input.h"

bool leftMouseIsDown = false;

void mouse_callback(GLFWwindow* window, int button, int action, int mods) {
    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);
    
    switch (action) {
        case GLFW_PRESS:
            if (button == GLFW_MOUSE_BUTTON_LEFT) {
                leftMouseIsDown = true;
                std::cout << "Left mouse down at position: (" << xpos << ", " << ypos << ")" << std::endl;
            } else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
                //mouseIsDown = true;
                std::cout << "Right mouse down at position: (" << xpos << ", " << ypos << ")" << std::endl;
            }
            break;
        case GLFW_RELEASE:
            if (button == GLFW_MOUSE_BUTTON_LEFT) {
                leftMouseIsDown = false;
                std::cout << "Left mouse up at position: (" << xpos << ", " << ypos << ")" << std::endl;
            } else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
                //mouseIsDown = false;
                std::cout << "Right mouse up at position: (" << xpos << ", " << ypos << ")" << std::endl;
            }
            break;
        default:
            break;
    }
}


void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (leftMouseIsDown) {
        std::cout << "Mouse moved to position: (" << xpos << ", " << ypos << ")" << std::endl;
    }
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    std::cout << "Scrolled: x offset = " << xoffset << ", y offset = " << yoffset << std::endl;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || 
        (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)) {
        glfwSetWindowShouldClose(window, true);
    }
}