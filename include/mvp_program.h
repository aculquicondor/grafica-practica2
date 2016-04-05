#ifndef HELLO_OPENGL_MVP_PROGRAM_H
#define HELLO_OPENGL_MVP_PROGRAM_H

#include "program.h"


class MvpProgram : public Program {
protected:
    MvpProgram *program;
public:
    MvpProgram(const char *vertex_shader, const char *fragment_shader);
    virtual void set_mvp(glm::mat4 mvp) = 0;
};

#endif //HELLO_OPENGL_MVP_PROGRAM_H
