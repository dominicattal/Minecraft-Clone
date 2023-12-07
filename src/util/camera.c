#include "camera.h"
#define PI 3.141592653589

void camera_init(Camera* camera)
{
    camera->yaw = 0;
    camera->pitch = 0;
    camera->speed = 1;
    camera->sensitivity = 1;
    camera->aspect_ratio = 1; 
    camera->fov = PI / 4;
    camera->view = mat4f_init();
    camera->proj = mat4f_init();
    vec3f_init0(&(camera->position));
    vec3f_init0(&(camera->facing));
    vec3f_init0(&(camera->right));
    vec3f_init0(&(camera->up));
    camera->viewID = 0;
    camera->projID = 0;
}