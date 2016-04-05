#include "scene.h"


Scene::Scene(const char *title, int width, int height, Camera *camera) :
        camera(camera) {
    if (!glfwInit()) {
        std::cerr << "ERROR: could not start GLFW3\n";
        exit(1);
    }

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cerr << "ERROR: could not open window with GLFW3\n";
        glfwTerminate();
        exit(2);
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        exit(3);
    }

    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    std::cerr << "Renderer: " << renderer << std::endl;
    std::cerr << "OpenGL version supported " << version << std::endl;

    glGenVertexArrays(1, &vertex_array_id);
    glBindVertexArray(vertex_array_id);
}


Scene::~Scene() {
    glfwTerminate();
}


void Scene::before_iteration(float time) {
}


void Scene::run() {
    auto initial_time = std::chrono::high_resolution_clock::now();
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    do {
        /* drawing */
        glfwSwapBuffers(window);
        glEnableVertexAttribArray(0);

        std::chrono::duration<float> elapsed = std::chrono::high_resolution_clock::now() - initial_time;
        float time = elapsed.count();

        before_iteration(time);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (std::size_t i = 0; i < drawables.size(); ++i)
            drawables[i]->draw(camera, time);

        glDisableVertexAttribArray(0);
        /* end drawing */

        glfwPollEvents();
    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
}

void Scene::add(Drawable *drawable) {
    drawables.push_back(drawable);
}
