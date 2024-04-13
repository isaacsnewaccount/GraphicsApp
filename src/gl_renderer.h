//gl_renderer.h - header file for opengl graphics

#ifndef gl_renderer_h
#define gl_renderer_h

#include <GLFW/glfw3.h>

//Public
void initializeGLAD();
void initBuffers();
void loadShaders();
void draw();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);


//Internal
unsigned int createVertexBuffer(float* vertices, int size);
unsigned int createVertexArray();
void setupVertexArray(unsigned int VAO, unsigned int VBO);

#endif