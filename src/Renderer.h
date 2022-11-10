#ifndef PONGO_RENDERER_H
#define PONGO_RENDERER_H

#endif //PONGO_RENDERER_H

#include <GL/glew.h>
#include <cstdlib>

#define ASSERT(x) if (!(x)) exit(1)
#define GLCall(x) GLClearError(); \
    x;                            \
    ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);

