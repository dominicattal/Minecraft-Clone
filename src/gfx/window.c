#include "window.h"

Window window;
Mouse mouse;

void window_init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window.size.x = DEFAULT_WINDOW_WIDTH;
    window.size.y = DEFAULT_WINDOW_HEIGHT;
    window.handle = glfwCreateWindow(window.size.x, window.size.y, "Bad Minecraft", NULL, NULL);
    window.dt = 0;
    window.last_frame = glfwGetTime();

    mouse.position.x = DEFAULT_WINDOW_WIDTH / 2;
    mouse.position.y = DEFAULT_WINDOW_HEIGHT / 2;

    glfwMakeContextCurrent(window.handle);
    glfwSetInputMode(window.handle, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glfwSetFramebufferSizeCallback(window.handle, framebuffer_size_callback);
    glfwSetMouseButtonCallback(window.handle, mouse_button_callback);
    glfwSetCursorPosCallback(window.handle, mouse_callback);

    gladLoadGL(glfwGetProcAddress);
    glViewport(0, 0, window.size.x, window.size.y);
    glEnable(GL_DEPTH_TEST);

    renderer_init(window.size);
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
    vec3f moving;
    vec3f_init0(&moving);
    if (glfwGetKey(window.handle, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.handle, true);
    if (glfwGetKey(window.handle, GLFW_KEY_W) == GLFW_PRESS)
        moving.z += 1;
    if (glfwGetKey(window.handle, GLFW_KEY_S) == GLFW_PRESS)
        moving.z -= 1;
    if (glfwGetKey(window.handle, GLFW_KEY_A) == GLFW_PRESS)
        moving.x -= 1;
    if (glfwGetKey(window.handle, GLFW_KEY_D) == GLFW_PRESS)
        moving.x += 1;
    if (glfwGetKey(window.handle, GLFW_KEY_Q) == GLFW_PRESS)
        moving.y -= 1;
    if (glfwGetKey(window.handle, GLFW_KEY_E) == GLFW_PRESS)
        moving.y += 1;
    if (glfwGetKey(window.handle, GLFW_KEY_R) == GLFW_PRESS)
        print_delta_time();
    if (glfwGetKey(window.handle, GLFW_KEY_T) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    if (glfwGetKey(window.handle, GLFW_KEY_Y) == GLFW_PRESS)
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    vec3f_norm_scale_ip(&moving, window.dt);
    renderer_camera_move(moving);
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
    vec2f offset;
    vec2f_init(&offset, mouse.position.x - xpos, mouse.position.y - ypos);
    mouse.position.x = xpos;
    mouse.position.y = ypos;
    renderer_camera_turn(offset);
}