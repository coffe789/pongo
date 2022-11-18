#include "Paddle.h"
// Has a position
// Renders at its position

Paddle::Paddle(float _x, float _y) : ib(indices, 6), x(_x), y(_y){
    vb_layout.Push(GL_FLOAT, 2);

    va.AddBuffer(vb, vb_layout);
}

Paddle::~Paddle() {

}

void Paddle::AddToScene() {

}

void Paddle::Render() {
    va.Bind();
    ib.Bind();
    float r_positions[PADDLE_ATTRIBUTES_N];
    for (int i = 0; i < PADDLE_ATTRIBUTES_N; ++i){
        if (i % 2 == 0) r_positions[i] = positions[i] + x;
        else r_positions[i] = positions[i] + y;
    }
    vb.BufferData(r_positions,PADDLE_ATTRIBUTES_N * sizeof(float));
    GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
}
