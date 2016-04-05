#include "mvp_simple_color_program.h"

MvpSimpleColorProgram::MvpSimpleColorProgram() :
        MvpProgram("shaders/mvp_vertex.glsl", "shaders/color_fragment.glsl") { }


void MvpSimpleColorProgram::set_color(float r, float g, float b, float a) {
    set_uniform("color", glm::vec4(r, g, b, a));
}


void MvpSimpleColorProgram::set_color(const glm::vec4 &color) {
    set_uniform("color", color);
}


void MvpSimpleColorProgram::set_mvp(glm::mat4 mvp) {
    set_uniform("mvp", mvp);
}
