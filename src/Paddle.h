#pragma once
#include "Graphics/VertexArray.h"
#include "Graphics/VertexBuffer.h"
#include "Graphics/VertexBufferLayout.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"

#define PADDLE_ATTRIBUTES_N 8

class Paddle {
public:
    float x, y;
    Paddle(Shader& _shader, float _x, float _y);
    ~Paddle();
    void AddToScene();
    void Render();

private:
    const float extent_x = 0.1f;
    const float extent_y = 0.4f;

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