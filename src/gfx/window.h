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
    f32 dt, last_frame, num_frames, avg_fps;
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
void print_fps();
void compute_fps();
void print_avg_fps();

void framebuffer_size_callback(GLFWwindow* window, s32 width, s32 height);
void mouse_button_callback(GLFWwindow* window, s32 button, s32 actions, s32 mods);
void mouse_callback(GLFWwindow* window, f64 xpos, f64 ypos);

#endif 