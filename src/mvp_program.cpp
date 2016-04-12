#include "mvp_program.h"


MvpProgram::MvpProgram() :
    Program("shaders/mvp_vertex.glsl", "shaders/color_fragment.glsl") { }


void MvpProgram::set_mvp(glm::mat4 mvp) {
    set_uniform("mvp", mvp);
}
