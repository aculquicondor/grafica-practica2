#include "gizmo.h"


Gizmo::Gizmo(MvpProgram *program) :
        Buffer(0), Drawable(program, this, GL_LINES, new GizmoColor, nullptr) {
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


const GLfloat GizmoColor::_data[12] = {
    .5f, 0.f, 0.f,
    1.f, 0.f, 0.f,
    0.f, .5f, 0.f,
    0.f, 1.f, 0.f,
};


GizmoColor::GizmoColor() : Buffer(1) {
}


GizmoColor::~GizmoColor() {
}


GLvoid *GizmoColor::data() const {
    return (GLvoid *)_data;
}


GLsizeiptr GizmoColor::data_size() const {
    return sizeof _data;
}


GLsizei GizmoColor::size() const {
    return 4;
}
