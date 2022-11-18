cmake_minimum_required(VERSION 3.23)
project(pongo)

set(CMAKE_CXX_STANDARD 14)

add_executable(pongo src/main.cpp src/Renderer.cpp src/Renderer.h src/VertexBuffer.cpp src/VertexBuffer.h src/IndexBuffer.cpp src/IndexBuffer.h src/VertexArray.cpp src/VertexArray.h src/VertexBufferLayout.cpp src/VertexBufferLayout.h src/Paddle.cpp src/Paddle.h src/Ball.cpp src/Ball.h src/Shader.cpp src/Shader.h)

#find_package(OpenGL)

add_subdirectory(deps/glfw)
add_subdirectory(deps/glew/build/cmake)
target_link_libraries(pongo glfw GL glew)
