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
    window.handle = glfwCreateWindow(window.width, window.height, "Name", NULL, NULL);
    window.dt = 0;
    window.last_frame = glfwGetTime();

    if (window.handle == NULL)
        fprintf(stderr, "failed to create window");
    glfwMakeContextCurrent(window.handle);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetFramebufferSizeCallback(window.handle, framebufferSizeCallback);
    glfwSetMouseButtonCallback(window.handle, mouseButtonCallback);
    glfwSetCursorPosCallback(window.handle, mouseCallback);

    if (!gladLoadGL(glfwGetProcAddress))
        fprintf(stderr, "failed to initalize GLAD");
    glViewport(0, 0, window.width, window.height);
    glEnable(GL_DEPTH_TEST);
}

void loopWindow()
{
    int i = 0;
    while (!glfwWindowShouldClose(window.handle))
    {
        if (i % 1000 == 1)
        {
            char buffer[50];
            snprintf(buffer, sizeof buffer, "%f\n", 1 / window.dt);
            printf(buffer);
        }
        i++;
        processInput();
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
        glfwSwapBuffers(window.handle);
        updateDeltaTime();
    }
}

void processInput()
{
    if (glfwGetKey(window.handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.handle, true);
}

void updateDeltaTime()
{
    float this_frame = glfwGetTime();
    window.dt = this_frame - window.last_frame;
    window.last_frame = this_frame;
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