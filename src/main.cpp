#include <iostream>

#include <glm/gtx/transform.hpp>

#include "scene.h"
#include "ortho_camera.h"
#include "gizmo.h"
#include "regular_polygon.h"
#include "uniform_color.h"


using namespace std;


MvpProgram *program = nullptr;
Scene *scene = nullptr;


class MyScene : public Scene {
private:
    virtual void before_iteration(float time) {
        //::program->set_color(1, 1, 1);
    }
public:
    MyScene() : Scene("2da práctica", 800, 600, new OrthoCamera(800, 600, .1, 10)) { }
};


class RotatingSquare : public Drawable {
public:
    RotatingSquare() : Drawable(::program, new RegularPolygon(4, .8f), GL_TRIANGLE_FAN, nullptr, nullptr) { }
    virtual glm::mat4 get_model(float time) {
        return Drawable::get_model(time) *
                glm::rotate(time, glm::vec3(0.f, 0.f, 1.f)) * glm::translate(glm::vec3(4, 0, 0));
    }
};


class OscilatingCircle : public Drawable {
public:
    OscilatingCircle() : Drawable(::program, new RegularPolygon(10, .2), GL_TRIANGLE_FAN, nullptr, nullptr) { }
    virtual glm::mat4 get_model(float time) {
        return glm::translate(glm::vec3(8 * sin(time), 0, 0));
    }
};


class OrbitingTriangle : public Drawable {
public:
    OrbitingTriangle() : Drawable(::program, new RegularPolygon(3, .5), GL_TRIANGLE_FAN, nullptr, nullptr) { }
    virtual glm::mat4 get_model(float time) {
        return Drawable::get_model(time) *
                glm::rotate(3 * time, glm::vec3(0.f, 1.f, 0.f)) *
                glm::translate(glm::vec3(3, 0, 0));
    }
};


class OrbitingSquare : public Drawable {
public:
    OrbitingSquare() : Drawable(::program, new RegularPolygon(4, .5), GL_TRIANGLE_FAN, nullptr, nullptr) { }
    virtual glm::mat4 get_model(float time) {
        return Drawable::get_model(time) *
               glm::rotate(time, glm::vec3(1.f, 0.f, 0.f)) *
               glm::translate(glm::vec3(0, 4, 0));
    }
};


class PlanetOrbit : public Drawable {
private:
    float speed, orbit;
public:
    PlanetOrbit(float speed, float orbit, Drawable *parent = nullptr) :
            Drawable(::program, nullptr, GL_TRIANGLE_FAN, nullptr, parent),
            speed(speed), orbit(orbit) { }
    virtual glm::mat4 get_model(float time) {
        return Drawable::get_model(time) *
                glm::rotate(time * speed, glm::vec3(0.f, 0.f, 1.f)) *
                glm::translate(glm::vec3(orbit, 0, 0)) *
                glm::rotate(-time * speed, glm::vec3(0.f, 0.f, 1.f));
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


void exercise1() {
    scene->add(new RotatingSquare);
}


void exercise2() {
    Drawable *square = new RotatingSquare,
            *circle = new OscilatingCircle;
    square->set_parent(circle);
    scene->add(square);
    scene->add(circle);
}


void exercise3() {
    Drawable *square = new RotatingSquare,
            *circle = new OscilatingCircle,
            *hexa = new OrbitingTriangle,
            *square2 = new OrbitingSquare;
    square->set_parent(circle);
    hexa->set_parent(square);
    square2->set_parent(circle);

    scene->add(square);
    scene->add(circle);
    scene->add(hexa);
    scene->add(square2);
}


void exercise4() {
    float vt = .5, vs = .3;
    Drawable *sun = new Planet(4, vs, glm::vec3(1.f, 1.f, 0.f)),
            *earth_orbit = new PlanetOrbit(vt, 10, sun),
            *earth = new Planet(2, 3 * vs, glm::vec3(0.f, 0.f, 1.f), earth_orbit),
            *moon_orbit = new PlanetOrbit(2 * vt, 3, earth_orbit),
            *moon = new Planet(.5, 1.5f * vs, glm::vec3(1.f, 1.f, 1.f), moon_orbit),
            *mars_orbit = new PlanetOrbit(vt, 18, sun),
            *mars = new Planet(1.5, vs, glm::vec3(1.f, 0.f, 0.f), mars_orbit);

    scene->add(sun);
    scene->add(earth);
    scene->add(moon);
    scene->add(mars);
}


int main() {
    scene = new MyScene;
    program = new MvpProgram;
    Drawable *gizmo = new Gizmo(program);

    // exercise1();
    // exercise2();
    // exercise3();
    exercise4();

    scene->add(gizmo);
    scene->run();

    delete scene;
    delete gizmo;
    delete program;
    return 0;
}