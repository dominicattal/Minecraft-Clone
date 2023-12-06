#ifndef PROGRAM_H
#define PROGRAM_H

#include "gfx.h"
#include "../util/util.h"

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

struct Window
{
    GLFWwindow* handle;
    int width, height;
    float dt, last_frame;
};

void initalizeWindow();
void loopWindow();
void processInput();
void updateDeltaTime();

void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void mouseButtonCallback(GLFWwindow* window, int button, int actions, int mods);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

#endif 