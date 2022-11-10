#pragma once

class VertexBuffer
{
private:
    // Refers to OpenGL in case we want to use a different renderer ig?
    unsigned int m_RendererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void Bind();
    void Unbind();

};