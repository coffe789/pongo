#include "Ball.h"

Ball::Ball(Shader &_shader, float _x, float _y)
    : shader(_shader), ib(indices, 6),
         position(_x, _y), velocity(1.0f,1.0f),
         radius(0.1)
{
    vb_layout.Push(GL_FLOAT, 2);

    va.AddBuffer(vb, vb_layout);

    shader.Bind();
    shader.SetUniform1f("radius", radius);
}

Ball::~Ball() {

}

void Ball::Render() {
    va.Bind(); ib.Bind(); shader.Bind();
    shader.SetUniform2f("ball_center", position.x, position.y);

    float r_positions[8];
    for (int i = 0; i < 8; ++i){
        if (i % 2 == 0) r_positions[i] = positions[i] + position.x;
        else r_positions[i] = positions[i] + position.y;
    }
    vb.BufferData(r_positions,8 * sizeof(float));
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    va.Unbind(); ib.Unbind(); shader.Unbind();
}

void Ball::Move(float deltaTime) {
    position = position + velocity * deltaTime;
    if (position.x < -1 || position.x > 1)
    {
        velocity.x *= -1;
    }
    if (position.y - radius <= -1 || position.y + radius >= 1)
    {
      velocity.y *= -1;
    }
}