#ifndef HELLO_OPENGL_GLFW_APPLICATION_H
#define HELLO_OPENGL_GLFW_APPLICATION_H

#include <iostream>
#include <vector>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "drawable.h"
#include "camera.h"

class Scene {
private:
    GLuint vertex_array_id;
    GLFWwindow *window;
    std::vector<Drawable *> drawables;
    Camera* camera;

protected:
    virtual void before_iteration(float time);

public:
    Scene(const char *title, int width, int height, Camera *camera);
    virtual ~Scene();
    void run();
    void add(Drawable *drawable);
};

#endif //HELLO_OPENGL_GLFW_APPLICATION_H
