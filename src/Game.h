#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include "Graphics/Renderer.h"
#include "Paddle.h"
#include "Graphics/Shader.h"
#include "Ball.h"

class Game {
public:
    Game(GLFWwindow *window);
    ~Game();
    void Update(float deltaTime);
    void DoPhysics(float deltaTime);
    void Render();
    bool DoCollisions(Paddle &p, Ball &b);
private:
    Shader paddle_shader;
    Shader ball_shader;
    Paddle player;
    Paddle enemy;
    Ball ball;
    GLFWwindow *window;
};
