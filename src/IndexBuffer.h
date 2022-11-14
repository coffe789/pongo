#pragma once

class IndexBuffer
{
private:
    IndexBuffer(const void *data, unsigned int size);

// Refers to OpenGL in case we want to use a different renderer ig?
    unsigned int m_RendererID;
    unsigned int m_Count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; }
};
