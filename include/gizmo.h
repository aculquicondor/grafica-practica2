#ifndef HELLO_OPENGL_GIZMO_H
#define HELLO_OPENGL_GIZMO_H

#include "drawable.h"
#include "mvp_program.h"
#include "uniform_color.h"


class Gizmo : public Buffer, public Drawable {
private:
    static const GLfloat _data[12];

    virtual GLvoid *data() const;
    virtual GLsizeiptr data_size() const;
    virtual GLsizei size() const;
public:
    Gizmo(MvpProgram *program);
    virtual ~Gizmo();
};


class GizmoColor : public Buffer {
private:
    static const GLfloat _data[12];

    virtual GLvoid *data() const;
    virtual GLsizeiptr data_size() const;
    virtual GLsizei size() const;
public:
    GizmoColor();
    virtual ~GizmoColor();
};

#endif //HELLO_OPENGL_GIZMO_H
