#include "Game.h"

Game::Game():
        paddle_shader("res/shaders/shader.shader"),
        ball_shader("res/shaders/ball_shader.shader"),
        player(paddle_shader, -1, 0),
        enemy(paddle_shader, 1, 0),
        ball(ball_shader, 0, 0)
{
    paddle_shader.Bind();
    paddle_shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);

}

Game::~Game() {

}

void Game::Update() {
    DoPhysics();
    DoCollisions();
    Render();

    // Clear bindings
    GLCall(glBindVertexArray(0));
    GLCall(glUseProgram(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void Game::DoPhysics() {
    ball.Move();
}

void Game::Render() {
    ball.Render();
    player.Render();
    enemy.Render();
}

void Game::DoCollisions() {

}
