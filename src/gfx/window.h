#ifndef PROGRAM_H
#define PROGRAM_H
#include <glad.h>
#include <glfw.h>
#include <stdio.h>
#include <stdbool.h>

#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 600

void initalizeWindow();
void loopWindow();
void processInput(GLFWwindow* window);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void mouseButtonCallback(GLFWwindow* window, int button, int actions, int mods);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

#endif 