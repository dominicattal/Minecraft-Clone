#include "camera.h"
#include <glad.h>
#define PI 3.141592653589

void camera_init(Camera* camera, float aspect_ratio)
{
    camera->yaw = 0;
    camera->pitch = 0;
    camera->speed = 1;
    camera->sensitivity = 1;
    camera->aspect_ratio = aspect_ratio; 
    camera->fov = PI / 4;
    camera->view = mat4f_init();
    camera->proj = mat4f_init();
    vec3f_init(&(camera->position), 0.5, 0, 0);
    vec3f_init(&(camera->facing), 0, 0, 1);
    vec3f_init(&(camera->right), 1, 0, 0);
    vec3f_init(&(camera->up), 0, 1, 0);
    camera->viewID = 0;
    camera->projID = 0;
}

void camera_set_aspect_ratio(Camera* camera, float aspect_ratio)
{
    camera->aspect_ratio = aspect_ratio;
}
void camera_turn(Camera* camera, vec2f offset) {}
void camera_move(Camera* camera, vec3f direction) {}
void camera_update_view(Camera* camera)
{
    mat4f_view_matrix(camera->view, camera->right, camera->up, camera->facing, camera->position);
    glUniformMatrix4fv(camera->viewID, 1, GL_FALSE, camera->view);
}
void camera_update_proj(Camera* camera)
{
    glUniformMatrix4fv(camera->projID, 1, GL_FALSE, camera->proj);
}