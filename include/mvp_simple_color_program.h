#ifndef HELLO_OPENGL_MVP_SIMPLE_COLOR_PROGRAM_H
#define HELLO_OPENGL_MVP_SIMPLE_COLOR_PROGRAM_H

#include "mvp_program.h"


class MvpSimpleColorProgram : public MvpProgram {
public:
    MvpSimpleColorProgram();
    void set_color(float r, float g, float b, float a=1.f);
    void set_color(const glm::vec4 &color);
    void set_mvp(glm::mat4 mvp);
};

#endif //HELLO_OPENGL_MVP_SIMPLE_COLOR_PROGRAM_H
