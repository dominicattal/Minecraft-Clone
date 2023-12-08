#include "camera.h"
#include <glad.h>
#define PI 3.141592653589

void camera_init(Camera* camera, float aspect_ratio)
{
    camera->yaw = 0;
    camera->pitch = 0;
    camera->speed = 150;
    camera->sensitivity = 0.001;
    camera->aspect_ratio = aspect_ratio; 
    camera->fov = PI / 4;
    camera->view = mat4f_init();
    camera->proj = mat4f_init();
    vec3f_init(&camera->position, 3, -3, -3);
}

void camera_set_aspect_ratio(Camera* camera, float aspect_ratio)
{
    camera->aspect_ratio = aspect_ratio;
}

void camera_turn(Camera* camera, vec2f offset) 
{
    vec2f_scale_ip(&offset, camera->sensitivity);
    camera->yaw += offset.x;
    camera->pitch += offset.y;
    if (camera->pitch > PI / 2)
        camera->pitch = PI / 2;
    if (camera->pitch < -PI / 2)
        camera->pitch = -PI / 2;
    camera->facing.x = cos(camera->yaw) * cos(camera->pitch);
    camera->facing.y = sin(camera->pitch);
    camera->facing.z = sin(camera->yaw) * cos(camera->pitch);
    vec3f_normalize_ip(&camera->facing);
    vec3f y_axis;
    vec3f_init(&y_axis, 0, 1, 0);
    camera->right = vec3f_cross(y_axis, camera->facing);
    vec3f_normalize_ip(&camera->right);
    camera->up = vec3f_cross(camera->facing, camera->right);
    camera_update_view(camera);
}

void camera_move(Camera* camera, vec3f moving, float dt) 
{
    vec3f direction;
    vec3f_init0(&direction);
    vec3f_add_ip(&direction, vec3f_scale(camera->right, moving.x));
    vec3f_add_ip(&direction, vec3f_scale(camera->up, moving.y));
    vec3f_add_ip(&direction, vec3f_scale(camera->facing, moving.z));
    vec3f_norm_scale_ip(&direction, camera->speed * dt);
    vec3f_add_ip(&camera->position, direction);
    camera_update_view(camera);
}

void camera_update_view(Camera* camera)
{
    mat4f_view_matrix(camera->view, camera->right, camera->up, camera->facing, camera->position);
    glUniformMatrix4fv(camera->viewID, 1, GL_FALSE, camera->view);
}

void camera_update_proj(Camera* camera)
{
    mat4f_proj_matrix(camera->proj, camera->aspect_ratio, camera->fov, NEAR_CLIP_DISTANCE, FAR_CLIP_DISTANCE);
    glUniformMatrix4fv(camera->projID, 1, GL_FALSE, camera->proj);
}