#ifndef graphics_h
#define graphics_h

#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void initializeGLAD();

void initBuffers();
void loadShaders();
unsigned int createVertexBuffer(float* vertices, int size);
unsigned int createVertexArray();
void setupVertexArray(unsigned int VAO, unsigned int VBO);
void draw();

// void doTextureThing();

#endif