#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

float color_red = 0.0f;
double sum_time = 0.0;
std::chrono::time_point<std::chrono::steady_clock> start_time;
std::chrono::time_point<std::chrono::steady_clock> init_time;

double DeltaTime(std::chrono::time_point<std::chrono::steady_clock> &start) {
    const std::chrono::time_point<std::chrono::steady_clock> end_time = std::chrono::steady_clock::now();
    const std::chrono::duration<double> elapsed_seconds = end_time - start;
    start = end_time;
    return elapsed_seconds.count();
}

GLFWwindow* InitGLFW(int width, int height) {
    int glfwResult = glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(width, height, "Hello World", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    int glad_version =  gladLoadGL();
    if (glad_version == 0) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }

    return window;
}

int main() {
    GLFWwindow* window = InitGLFW(800, 600);

    start_time = std::chrono::steady_clock::now();
    init_time = start_time;

    while (!glfwWindowShouldClose(window)) {
        double delta_time = DeltaTime(init_time);
        color_red += 1 * delta_time;

        //Ciclo GLFW
        glfwPollEvents();

        glClearColor(color_red, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }
    return 0;
}


