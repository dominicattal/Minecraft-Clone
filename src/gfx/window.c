#include "window.h"


Window window;

void window_init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window.width  = DEFAULT_WINDOW_WIDTH;
    window.height = DEFAULT_WINDOW_HEIGHT;
    window.handle = glfwCreateWindow(window.width, window.height, "Name", NULL, NULL);
    window.dt = 0;
    window.last_frame = glfwGetTime();

    glfwMakeContextCurrent(window.handle);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetFramebufferSizeCallback(window.handle, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window.handle, mouse_button_callback);
    glfwSetCursorPosCallback(window.handle, mouse_callback);

    gladLoadGL(glfwGetProcAddress);
    glViewport(0, 0, window.width, window.height);
    glEnable(GL_DEPTH_TEST);

    renderer_init();
}

void window_loop()
{
    while (!glfwWindowShouldClose(window.handle))
    {
        process_input();
        render();
        glfwPollEvents();
        glfwSwapBuffers(window.handle);
        update_delta_time();
    }
}

void process_input()
{
    if (glfwGetKey(window.handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.handle, true);
}

void update_delta_time()
{
    float this_frame = glfwGetTime();
    window.dt = this_frame - window.last_frame;
    window.last_frame = this_frame;
}

void print_delta_time()
{
    if (window.dt != 0)
    {
        char buffer[50];
        snprintf(buffer, sizeof buffer, "%f\n", 1 / window.dt);
        printf(buffer);  
    }  
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{

}
void mouse_button_callback(GLFWwindow* window, int button, int actions, int mods)
{

}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

}