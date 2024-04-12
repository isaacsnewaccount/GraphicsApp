#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "message.h"
#include "input.h"
#include "app.h"
#include "graphics.h"

// Function declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void initializeGLFW();
GLFWwindow* createWindow(int width, int height, const char* title);
void initializeGLAD();
unsigned int createVertexBuffer(float* vertices, int size);
unsigned int createVertexArray();
void setupVertexArray(unsigned int VAO, unsigned int VBO);
void draw();
void initShaders();

// settings
const unsigned int screenWidth = 800;
const unsigned int screenHeight = 600;

float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

unsigned int VBO, VAO, shaderProgram;

int main(void) {
    App app;
    app.init();

    initializeGLFW();
    GLFWwindow* window = createWindow(screenWidth, screenHeight, "Lookdraw");
    initializeGLAD();
    printMonitorInfo();
    initShaders();

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

    glfwTerminate();
    return 0;
}

void initShaders() {
    VBO = createVertexBuffer(vertices, sizeof(vertices));
    VAO = createVertexArray();
    setupVertexArray(VAO, VBO);
    shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);
}

void draw() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //enable wireframe mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
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
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}

void initializeGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
}

unsigned int createVertexBuffer(float* vertices, int size) {
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    return VBO;
}

unsigned int createVertexArray() {
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    return VAO;
}

void setupVertexArray(unsigned int VAO, unsigned int VBO) {
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}