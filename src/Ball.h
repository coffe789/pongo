#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Ball {
public:
    Ball(Shader& _shader, float _x, float _y);
    ~Ball();
    float x, y;
    void Render();
private:
    float positions[8] = {
            -0.1f, 0.1f,
            0.1f, 0.1f,
            0.1f, -0.1f,
            -0.1f, -0.1f,
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