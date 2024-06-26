//gl_renderer.cpp - OpenGL functions and the main draw function

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <glm/glm.hpp>


#include "gl_renderer.h"
#include "shader.h"

// Declare ourShader as a pointer globally
Shader* ourShader = nullptr;


// ////rectangle
// float vertices[] = {
//      0.5f,  0.5f, 0.0f,  // top right
//      0.5f, -0.5f, 0.0f,  // bottom right
//     -0.5f, -0.5f, 0.0f,  // bottom left
//     -0.5f,  0.5f, 0.0f   // top left 
// };
// unsigned int indices[] = {  // note that we start from 0!
//     0, 1, 3,   // first triangle
//     1, 2, 3    // second triangle
// };  


//basic triangle
float vertices[] = {
    // First triangle
    -0.2f,  0.15f, 0.0f,   // top center
   -0.3f, -0.05f, 0.0f,   // bottom left
    0.0f, -0.05f, 0.0f,   // bottom right

    // Second triangle
    -0.05f, -0.2f, 0.0f,   // top center
   -0.35f, -0.35f, 0.0f, // bottom left
   -0.05f, -0.35f, 0.0f, // bottom right

    // Third triangle
    0.2f, -0.2f, 0.0f,   // top center
   -0.05f, -0.35f, 0.0f, // bottom left
    0.35f, -0.35f, 0.0f  // bottom right
};



// unsigned int indices[] = {  // note that we start from 0!
//     0, 1, 2,   // first triangle
// };  



float texCoords[] = {
    0.0f, 0.0f,  // lower-left corner  
    1.0f, 0.0f,  // lower-right corner
    0.5f, 1.0f   // top-center corner
};


unsigned int VBO, VAO, EBO;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    std::cout << "Window resized to width: " << width << " and height: " << height << std::endl;
    glViewport(0, 0, width, height);
}

void loadShaders() {
    // Create new shader called basic
    ourShader = new Shader("assets/shaders/basic.vert", "assets/shaders/basic.frag");
}

void draw() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //enable wireframe mode
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    ourShader->use();
    // update the shader inputs
    double timeValue = glfwGetTime();
    ourShader->setFloat("iTime", timeValue);


    glBindVertexArray(VAO);

    int vertexCount = sizeof(vertices) / sizeof(vertices[0]);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


//Unused
// void setupEBO() {
//     glGenBuffers(1, &EBO);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
// }

void initBuffers() {
    VBO = createVertexBuffer(vertices, sizeof(vertices));
    VAO = createVertexArray();

    // setupEBO();

    // set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);  
}

unsigned int createVertexBuffer(float* vertices, int size) {
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_DYNAMIC_DRAW);
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

void initializeGLAD() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
}