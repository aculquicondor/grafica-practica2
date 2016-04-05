#include "drawable.h"


Drawable::Drawable(MvpProgram *program, Geometry *geometry, GLenum draw_mode, Drawable *parent) :
        program(program), geometry(geometry), draw_mode(draw_mode), parent(parent) { }


Drawable::~Drawable() {
}


void Drawable::set_parent(Drawable *parent) {
    this->parent = parent;
}


void Drawable::draw(Camera *camera, float time) {
    geometry->activate();
    program->activate();
    glm::mat4 mvp = camera != nullptr ?
                    camera->get_vp() * get_model(time) :
                    get_model(time);
    program->set_mvp(mvp);
    draw_set(time);
    draw_geometry();
}


void Drawable::draw_set(float time) {
}


void Drawable::draw_geometry() {
    glDrawArrays(draw_mode, 0, geometry->size());
}


glm::mat4 Drawable::get_model(float time) {
    return parent != nullptr ? parent->get_model(time) : glm::mat4(1.0f);
}
