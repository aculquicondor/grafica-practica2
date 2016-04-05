#include "geometry.h"


Geometry::Geometry() : data_loaded(false) {
    glGenBuffers(1, &buffer_id);
}


Geometry::~Geometry() {
}


void Geometry::load_data() const {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, data_size(), data(), GL_STATIC_DRAW);
}


void Geometry::activate() const {
    if (!data_loaded)
        load_data();
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glVertexAttribPointer(0, dimension(), data_type(), GL_FALSE, 0, nullptr);
}

GLint Geometry::dimension() const {
    return 3;
}

GLenum Geometry::data_type() const {
    return GL_FLOAT;
}
