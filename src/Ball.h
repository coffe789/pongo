#pragma once

#include <glm/vec2.hpp>
#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"
#include "Paddle.h"

class Ball {
public:
    Ball(Shader& _shader, float _x, float _y);
    ~Ball();
    glm::vec2 position;
    glm::vec2 velocity;
    float radius;
    void Render();
    void Move(float deltaTime);
private:
    float positions[8] = {
            -1.0f, 1.0f,
            1.0f, 1.0f,
            1.0f, -1.0f,
            -1.0f, -1.0f,
    };
    unsigned int indices[6] = {
            0,1,3, 1, 2, 3
    };
    VertexArray va;
    VertexBuffer vb;
    VertexBufferLayout vb_layout;
    IndexBuffer ib;
    Shader shader;

};