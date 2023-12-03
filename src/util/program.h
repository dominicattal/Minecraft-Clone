#ifndef PROGRAM_H
#define PROGRAM_H
#include <glad.h>
#include <glfw.h>
#include <stdio.h>
#include <stdbool.h>

void initalizeProgram();
void loopProgram();
void processInput(GLFWwindow* window);
void framebufferSizeCallback(GLFWwindow* window, int width, int height);
void mouseButtonCallback(GLFWwindow* window, int button, int actions, int mods);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);

#endif /* PROGRAM_H */