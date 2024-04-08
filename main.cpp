// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>

// int main(void) {
// 	printf("Hello, world!\n");

//     // Initialize GLFW
//     if (!glfwInit()) {
//         return -1;
//     }

//     // Create a windowed mode window and its OpenGL context
//     GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Window", NULL, NULL);
//     if (!window) {
//         glfwTerminate();
//         return -1;
//     }

//     // Make the window's context current
//     glfwMakeContextCurrent(window);

//     // Loop until the user closes the window
//     while (!glfwWindowShouldClose(window)) {
//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT);

//         // Render OpenGL here

//         // Swap front and back buffers
//         glfwSwapBuffers(window);

//         // Poll for and process events
//         glfwPollEvents();
//     }

//     // Terminate GLFW
//     glfwTerminate();
//     return 0;
// }



#include <iostream>
#include <cstdlib>
#include "message.h"

using namespace std;

// Function declaration
int add(int a, int b);

int main() {
    int num1 = 5;
    int num2 = 7;

    // Function call
    int result = add(num1, num2);

    std::cout << "The sum of " << num1 << " and " << num2 << " is: " << result << std::endl;


    message message;
    message.printMessage();


    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}