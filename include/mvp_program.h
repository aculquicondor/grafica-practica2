#ifndef HELLO_OPENGL_MVP_PROGRAM_H
#define HELLO_OPENGL_MVP_PROGRAM_H

#include "program.h"


class MvpProgram : public Program {
protected:
    MvpProgram *program;
public:
    MvpProgram();
    void set_mvp(glm::mat4 mvp);
};

#endif //HELLO_OPENGL_MVP_PROGRAM_H
