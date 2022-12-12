cmake_minimum_required(VERSION 3.23)
project(pongo)

set(CMAKE_CXX_STANDARD 14)

add_executable(pongo src/main.cpp src/Graphics/Renderer.cpp src/Graphics/Renderer.h src/Graphics/VertexBuffer.cpp src/Graphics/VertexBuffer.h src/Graphics/IndexBuffer.cpp src/Graphics/IndexBuffer.h src/Graphics/VertexArray.cpp src/Graphics/VertexArray.h src/Graphics/VertexBufferLayout.cpp src/Graphics/VertexBufferLayout.h src/Paddle.cpp src/Paddle.h src/Ball.cpp src/Ball.h src/Graphics/Shader.cpp src/Graphics/Shader.h src/vec2.cpp src/vec2.h src/Game.cpp src/Game.h)

#find_package(OpenGL)

add_subdirectory(deps/glfw)
add_subdirectory(deps/glew/build/cmake)
target_link_libraries(pongo glfw GL glew)
