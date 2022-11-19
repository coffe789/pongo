#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Renderer.h"
#include "Paddle.h"
#include "Shader.h"
#include "Ball.h"

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "PONGO", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSwapInterval(1); // Vsync/monitor refresh rate

    if (glewInit() != GLEW_OK)
        std::cout << "ERROR: Glew init failed!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    Shader shader("res/shaders/shader.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);
    Paddle paddle(shader, 1,0);
    Paddle paddle2(shader, -1, 0);

    Shader ball_shader("res/shaders/ball_shader.shader");
    Ball ball(ball_shader, 0, 0);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        paddle.Render();
        paddle2.Render();
        ball.Render();

        // Clear bindings
        GLCall(glBindVertexArray(0));
        GLCall(glUseProgram(0));
        GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
        GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}