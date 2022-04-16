#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void ErrorCallback(int error, const char* description)
{
    std::cerr << "Error: " << description << "\n";
}

int main()
{
    glfwSetErrorCallback(ErrorCallback);

    // setup glfw
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Space Invaders", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // setup GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        std::cerr << "Error initializing GLEW.\n";
        glfwTerminate();
        return -1;
    }

    // get and print OpenGL version
    int glVersion[2] = {};
    glGetIntegerv(GL_MAJOR_VERSION, &glVersion[0]);
    glGetIntegerv(GL_MINOR_VERSION, &glVersion[1]);
    std::cout << "Using OpenGL version: " << glVersion[0] << "." << glVersion[1] << "\n";

    glClearColor(1.0, 0.0, 0.0, 1.0);
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
