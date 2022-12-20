#pragma once
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexBufferLayout.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"
#include "vec2.h"

#define PADDLE_ATTRIBUTES_N 8

class Paddle {
public:
    Vec2f position;
    Vec2f velocity;
    Paddle(Shader& _shader, float _x, float _y);
    ~Paddle();
    void Render();
    void Move(float deltaTime);

    const float extent_x = 0.1f;
    const float extent_y = 0.4f;

private:

    float positions[PADDLE_ATTRIBUTES_N] = {
            -extent_x, extent_y,
            extent_x, extent_y,
            extent_x, -extent_y,
            -extent_x, -extent_y,
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