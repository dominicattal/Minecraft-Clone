#ifndef PROGRAM_H
#define PROGRAM_H

#include "gfx.h"
#include "../util/util.h"
#include "renderer.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

struct Window
{
    GLFWwindow* handle;
    vec2i size;
    float dt, last_frame;
};

struct Mouse 
{
    vec2f position;
};

typedef struct Window Window;
typedef struct Mouse Mouse;

void window_init();
void window_loop();
void process_input();
void update_delta_time();
void print_delta_time();

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_button_callback(GLFWwindow* window, int button, int actions, int mods);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

#endif 