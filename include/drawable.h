#ifndef HELLO_OPENGL_DRAWABLE_H
#define HELLO_OPENGL_DRAWABLE_H

#include "buffer.h"
#include "camera.h"
#include "mvp_program.h"


class Drawable {
private:
    MvpProgram *program;
    Buffer *geometry, *color;
    GLenum draw_mode;
    Drawable *parent;

public:
    Drawable(MvpProgram *program, Buffer *geometry, GLenum draw_mode=GL_TRIANGLE_STRIP,
             Buffer *color = nullptr, Drawable *parent = nullptr);

    void set_parent(Drawable *parent);

    virtual ~Drawable();
    virtual void draw(Camera *camera, float time=0);
    virtual void draw_set(float time);
    virtual void draw_geometry();
    virtual glm::mat4 get_model(float time);
};


#endif //HELLO_OPENGL_DRAWABLE_H
