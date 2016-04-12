#include "uniform_color.h"


UniformColor::UniformColor(const glm::vec3 &color, GLsizei size) :
        Buffer(1), _size(size) {
    _data = new glm::vec3[size];
    for (GLuint i = 0; i < size; ++i)
        _data[i] = color;
}


UniformColor::~UniformColor() {
    delete _data;
}


GLvoid *UniformColor::data() const {
    return _data;
}


GLsizeiptr UniformColor::data_size() const {
    return _size * sizeof(glm::vec3);
}


GLsizei UniformColor::size() const {
    return _size;
}
