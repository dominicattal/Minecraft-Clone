#include "window.h"

struct Window window;

void initalizeWindow()
{
    if (!glfwInit())
        fprintf(stderr, "failed to initalize GLFW");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window.width  = DEFAULT_WINDOW_WIDTH;
    window.height = DEFAULT_WINDOW_HEIGHT;
    window.window = glfwCreateWindow(window.width, window.height, "Name", NULL, NULL);
    if (window.window == NULL)
        fprintf(stderr, "failed to create window");
    glfwMakeContextCurrent(window.window);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetFramebufferSizeCallback(window.window, framebufferSizeCallback);
    glfwSetMouseButtonCallback(window.window, mouseButtonCallback);
    glfwSetCursorPosCallback(window.window, mouseCallback);

    if (!gladLoadGL(glfwGetProcAddress))
        fprintf(stderr, "failed to initalize GLAD");
    glViewport(0, 0, window.width, window.height);
    glEnable(GL_DEPTH_TEST);
}

void loopWindow()
{
    while (!glfwWindowShouldClose(window.window))
    {
        processInput(window.window);
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window.window);
    }
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) 
{

}
void mouseButtonCallback(GLFWwindow* window, int button, int actions, int mods)
{

}
void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{

}