#include "gizmo.h"


Gizmo::Gizmo(MvpSimpleColorProgram *program) :
        Geometry(), program(program), Drawable(program, this) {
}


Gizmo::~Gizmo() {

}


const GLfloat Gizmo::_data[12] = {
    0.f, 0.f, 0.f,
    1.f, 0.f, 0.f,
    0.f, 0.f, 0.f,
    0.f, 1.f, 0.f
};


GLvoid *Gizmo::data() const {
    return (GLvoid *)_data;
}


GLsizeiptr Gizmo::data_size() const {
    return sizeof _data;
}


GLsizei Gizmo::size() const {
    return 4;
}


void Gizmo::draw_geometry() {
    program->set_color(1, 0, 0);
    glDrawArrays(GL_LINES, 0, 2);

    program->set_color(0, 1, 0);
    glDrawArrays(GL_LINES, 2, 2);
}
