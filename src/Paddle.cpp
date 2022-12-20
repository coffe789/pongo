#include "Paddle.h"

Paddle::Paddle(Shader& _shader, float x, float y) : ib(indices, 6), position(x,y), shader(_shader){
    vb_layout.Push(GL_FLOAT, 2);

    va.AddBuffer(vb, vb_layout);
}

Paddle::~Paddle() {

}

void Paddle::Render() {
    va.Bind(); ib.Bind(); shader.Bind();

    float r_positions[PADDLE_ATTRIBUTES_N];
    for (int i = 0; i < PADDLE_ATTRIBUTES_N; ++i){
        if (i % 2 == 0) r_positions[i] = positions[i] + position.x;
        else r_positions[i] = positions[i] + position.y;
    }
    vb.BufferData(r_positions,PADDLE_ATTRIBUTES_N * sizeof(float));
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

    va.Unbind(); ib.Unbind(); shader.Unbind();

}

void Paddle::Move(float deltaTime) {
//    if (position.y < -1 || position.y > 1)
//        position = position - velocity;
    position = position + velocity * deltaTime;
}
