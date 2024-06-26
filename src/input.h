//input.h - header file for input

#ifndef input_h
#define input_h

#include <GLFW/glfw3.h>

void mouse_callback(GLFWwindow* window, int button, int action, int mods);
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

void processInput(GLFWwindow *window);

#endif