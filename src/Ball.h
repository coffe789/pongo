#pragma once

#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"
#include "vec2.h"
#include "Paddle.h"

class Ball {
public:
    Ball(Shader& _shader, float _x, float _y);
    ~Ball();
    Vec2f position;
    Vec2f velocity;
    void Render();
    void Move();
    void Collide(Paddle collider);
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