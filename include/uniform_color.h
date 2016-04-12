#ifndef HELLO_OPENGL_UNIFORM_COLOR_H
#define HELLO_OPENGL_UNIFORM_COLOR_H


#include <glm/vec3.hpp>

#include "buffer.h"


class UniformColor : public Buffer {
private:
    glm::vec3 *_data;
    GLsizei _size;

    virtual GLvoid *data() const;
    virtual GLsizeiptr data_size() const;
public:
    UniformColor(const glm::vec3 &color, GLsizei size);
    virtual ~UniformColor();

    virtual GLsizei size() const;
};

#endif //HELLO_OPENGL_UNIFORM_COLOR_H
