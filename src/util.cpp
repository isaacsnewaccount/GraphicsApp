#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include "graphics.h"
#include "shader.h"

void printMonitorInfo() {
    // Get the list of monitors
    int monitorCount;
    GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);

    if (monitorCount == 0) {
        std::cout << "No monitors found" << std::endl;
    } else {
        std::cout << "List of monitors:" << std::endl;
        for (int i = 0; i < monitorCount; ++i) {
            const GLFWvidmode* mode = glfwGetVideoMode(monitors[i]);
            if (mode != nullptr) {
                std::cout << "    Monitor " << i+1 << ": " << glfwGetMonitorName(monitors[i]) << std::endl;
            }
        }
    }
}