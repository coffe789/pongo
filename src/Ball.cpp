#include "Ball.h"

Ball::Ball(Shader &_shader, float _x, float _y)
    : shader(_shader), ib(indices, 6), x(_x), y(_y)
{
    vb_layout.Push(GL_FLOAT, 2);

    va.AddBuffer(vb, vb_layout);
}

Ball::~Ball() {

}

void Ball::Render() {
    va.Bind(); ib.Bind(); shader.Bind();

    float r_positions[8];
    for (int i = 0; i < 8; ++i){
        if (i % 2 == 0) r_positions[i] = positions[i] + x;
        else r_positions[i] = positions[i] + y;
    }
    vb.BufferData(r_positions,8 * sizeof(float));
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    va.Unbind(); ib.Unbind(); shader.Unbind();
}
