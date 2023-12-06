#include "window.h"
#include "shader.h"

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
}

void window_loop()
{
    Shader shader = shader_init("src/shaders/vertex.sl", "src/shaders/fragment.sl");
    shader_use(shader);
    float vertices[] = {
    // first triangle
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f,  0.5f, 0.0f,  // top left 
    // second triangle
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left
    };
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    glBindVertexArray(VAO);  
    while (!glfwWindowShouldClose(window.handle))
    {
        process_input();
        glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
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