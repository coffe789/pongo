#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/Renderer.h"
#include "Paddle.h"
#include "Graphics/Shader.h"
#include "Ball.h"

class Game {
public:
    Game();
    ~Game();
    void Update();
    void DoPhysics();
    void Render();
    void DoCollisions();
private:
    Shader paddle_shader;
    Shader ball_shader;
    Paddle player;
    Paddle enemy;
    Ball ball;
};
