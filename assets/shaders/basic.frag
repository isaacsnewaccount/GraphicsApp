#version 330 core
out vec4 FragColor;

//uniform float green;

uniform vec4 ourColor; // we set this variable in the OpenGL code.
uniform float iTime;

void main()
{
    // Calculate the green value using sine function
    float greenValue = sin(3.0 * iTime) / 2.0 + 0.5;

    // Create a new color using the calculated green value
    vec4 newColor = vec4(0.0, greenValue, 0.0, 1.0);

    // Output the color
    FragColor = newColor;
}