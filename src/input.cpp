#include <iostream>
#include <GLFW/glfw3.h>
#include "input.h"

bool mouseIsDown = false;

void mouse_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        mouseIsDown = true;
        std::cout << "Mouse down at position: (" << xpos << ", " << ypos << ")" << std::endl;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        mouseIsDown = false;
        std::cout << "Mouse up at position: (" << xpos << ", " << ypos << ")" << std::endl;
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (mouseIsDown) {
        std::cout << "Mouse moved to position: (" << xpos << ", " << ypos << ")" << std::endl;
    }
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS || 
        (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)) {
        glfwSetWindowShouldClose(window, true);
    }
}