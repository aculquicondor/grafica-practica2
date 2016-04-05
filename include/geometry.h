#ifndef HELLO_OPENGL_GEOMETRY_H
#define HELLO_OPENGL_GEOMETRY_H

#include "GL/glew.h"


class Geometry {
private:
    void load_data() const;

protected:
    GLuint buffer_id;
    bool data_loaded;

    virtual GLvoid *data() const = 0;
    virtual GLsizeiptr data_size() const = 0;

public:
    Geometry();
    virtual ~Geometry();
    void activate() const;

    virtual GLint dimension() const;
    virtual GLenum data_type() const;
    virtual GLsizei size() const = 0;
};

#endif //HELLO_OPENGL_GEOMETRY_H
