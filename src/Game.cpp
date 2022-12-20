#include "Game.h"

Game::Game(GLFWwindow *_window):
        paddle_shader("res/shaders/shader.shader"),
        ball_shader("res/shaders/ball_shader.shader"),
        player(paddle_shader, -1, 0),
        enemy(paddle_shader, 1, 0),
        ball(ball_shader, 0, 0),
        window(_window)
{
    paddle_shader.Bind();
    paddle_shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);
}

Game::~Game() {

}

void Game::Update(float deltaTime) {
    DoPhysics(deltaTime);
    if (DoCollisions(player, ball) || DoCollisions(enemy, ball)) {
        ball.position = ball.position - ball.velocity * deltaTime;
        ball.velocity.x *= -1;
}
    Render();

    // Clear bindings
    GLCall(glBindVertexArray(0));
    GLCall(glUseProgram(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void Game::DoPhysics(float deltaTime) {
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        enemy.velocity.y = 0.9f ;
    }
    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        enemy.velocity.y = -0.9f;
    }
    else
        enemy.velocity.y = 0;
    enemy.Move(deltaTime);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
        player.velocity.y = 0.9f;
    }
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        player.velocity.y = -0.9f;
    }
    else
        player.velocity.y = 0;
    player.Move(deltaTime);

    ball.Move(deltaTime);
}

void Game::Render() {
    ball.Render();
    player.Render();
    enemy.Render();
}

bool Game::DoCollisions(Paddle &p, Ball &b) {
    Vec2f diff = b.position - p.position;
    diff.x = std::max(-p.extent_x, std::min(p.extent_x, diff.x));
    diff.y = std::max(-p.extent_y, std::min(p.extent_y, diff.y));
    diff = diff + p.position - b.position;

    return ball.radius >= (sqrt(diff.x *  diff.x + diff.y * diff.y));
}