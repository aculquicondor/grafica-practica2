#include <iostream>

#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

#include "scene.h"
#include "perspective_camera.h"
#include "gizmo.h"
#include "regular_polygon.h"
#include "uniform_color.h"


using namespace std;


MvpProgram *program = nullptr;
Scene *scene = nullptr;
PerspectiveCamera *camera = nullptr;


class PlanetOrbit : public Drawable {
private:
    float speed, orbit;
public:
    PlanetOrbit(float speed, float orbit, Drawable *parent = nullptr) :
            Drawable(::program, nullptr, GL_TRIANGLE_FAN, nullptr, parent),
            speed(speed), orbit(orbit) { }
    virtual glm::mat4 get_model(float time) {
        glm::vec3 t = glm::rotateZ(glm::vec3(orbit, 0, 0), time * speed);
        return Drawable::get_model(time) * glm::translate(t);
    }
};


class Planet : public Drawable {
private:
    float spin;
public:
    Planet(float radius, float spin, const glm::vec3 &color, Drawable *parent = nullptr) :
            Drawable(::program, new RegularPolygon(8, radius), GL_TRIANGLE_FAN, new UniformColor(color, 8), parent),
            spin(spin) { }
    virtual glm::mat4 get_model(float time) {
        return Drawable::get_model(time) *
               glm::rotate(time * spin, glm::vec3(0.f, 0.f, 1.f));
    }
};


class Center : public Drawable {
public:
    Center() : Drawable(::program, nullptr), position(0, 0, -5), angle_x(0), angle_y(0) {}

    glm::vec3 position;
    float angle_x, angle_y;
    virtual glm::mat4 get_model(float time) {
        return Drawable::get_model(time) *
                glm::translate(position) *
                glm::rotate(angle_x, glm::vec3(0, 1, 0)) *
                glm::rotate(angle_y, glm::vec3(1, 0, 0));
    }
};


Center *center;


class MyScene : public Scene {
    float move_speed, angle_speed;
public:
    MyScene(Camera *camera) : Scene("3ra práctica", 1000, 700, camera),
                              move_speed(.2), angle_speed(.002) { }

    virtual void process_events() {
        if (key_state(GLFW_KEY_UP) == GLFW_PRESS)
            center->position += glm::vec3(0, 0, move_speed);
        if (key_state(GLFW_KEY_DOWN) == GLFW_PRESS)
            center->position -= glm::vec3(0, 0, move_speed);
        if (key_state(GLFW_KEY_LEFT) == GLFW_PRESS)
            center->position += glm::vec3(move_speed, 0, 0);
        if (key_state(GLFW_KEY_RIGHT) == GLFW_PRESS)
            center->position -= glm::vec3(move_speed, 0, 0);
        auto pos = cursor_pos();
        center->angle_x = float(pos.first - 500) * angle_speed;
        center->angle_y = float(pos.second - 350) * angle_speed;
    }
};


void exercise() {
    float vt = .5, vs = .3;
    Drawable *sun = new Planet(4, vs, glm::vec3(1, 1, 0), center),
            *earth_orbit = new PlanetOrbit(vt, 10, sun),
            *earth = new Planet(2, 3 * vs, glm::vec3(0, 0, 1), earth_orbit),
            *moon_orbit = new PlanetOrbit(2 * vt, 3, earth_orbit),
            *moon = new Planet(.5, 1.5f * vs, glm::vec3(1, 1, 1), moon_orbit),
            *mars_orbit = new PlanetOrbit(vt, 18, sun),
            *mars = new Planet(1.5, vs, glm::vec3(1, 0, 0), mars_orbit);

    scene->add(sun);
    scene->add(earth);
    scene->add(moon);
    scene->add(mars);
}


int main() {
    center = new Center;
    camera = new PerspectiveCamera(1000, 700, 1.5);
    scene = new MyScene(camera);
    program = new MvpProgram;
    Drawable *gizmo = new Gizmo(program, center);
    //camera->look_at(glm::vec3(15, 15, 15), glm::vec3(0, 0, 0), glm::vec3(-.3, -.3, 2.71));

    exercise();

    scene->add(gizmo);
    scene->run();

    delete scene;
    delete gizmo;
    delete program;
    return 0;
}