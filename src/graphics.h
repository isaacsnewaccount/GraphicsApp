#pragma once

#include <GLFW/glfw3.h>
#include "shader.h"

extern const char *vertexShaderSource;
extern const char *fragmentShaderSource;

void printMonitorInfo();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void initializeGLAD();

void initShaders();
unsigned int createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
unsigned int compileShader(unsigned int type, const char* source);
unsigned int createVertexBuffer(float* vertices, int size);
unsigned int createVertexArray();
void setupVertexArray(unsigned int VAO, unsigned int VBO);
void draw();

void doTextureThing();