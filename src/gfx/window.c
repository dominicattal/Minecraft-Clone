#include "window.h"

int window_width = DEFAULT_WINDOW_WIDTH;
int window_height = DEFAULT_WINDOW_HEIGHT;
GLFWwindow* window;

void initalizeWindow()
{
    if (!glfwInit())
        printf("failed to initalize GLFW");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(window_width, window_height, "Name", NULL, NULL);
    if (window == NULL)
        printf("failed to create window");
    glfwMakeContextCurrent(window);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, mouseCallback);

    if (!gladLoadGL(glfwGetProcAddress))
        printf("failed to initalize GLAD");
    glViewport(0, 0, window_width, window_height);
    glEnable(GL_DEPTH_TEST);
}

void loopWindow()
{
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window);
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