#ifndef HELLO_OPENGL_GIZMO_H
#define HELLO_OPENGL_GIZMO_H

#include "drawable.h"
#include "mvp_simple_color_program.h"


class Gizmo : public Geometry, public Drawable {
private:
    static const GLfloat _data[12];
    MvpSimpleColorProgram *program;

    virtual GLvoid *data() const;
    virtual GLsizeiptr data_size() const;
    virtual GLsizei size() const;
public:
    Gizmo(MvpSimpleColorProgram *program);
    virtual ~Gizmo();

    void draw_geometry();
};

#endif //HELLO_OPENGL_GIZMO_H
