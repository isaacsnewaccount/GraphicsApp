#pragma once

//#include <GLFW/glfw3.h>

void printMonitorInfo();
unsigned int createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
unsigned int compileShader(unsigned int type, const char* source);

extern const char *vertexShaderSource;
extern const char *fragmentShaderSource;