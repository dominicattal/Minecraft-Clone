#ifndef CAMERA_H
#define CAMERA_H

#include "vec.h"

struct Camera
{
    float yaw, pitch, speed, sensitivity, aspect_ratio, fov;
    vec3f position, facing, right, up;
    unsigned int viewID, projID;
};

typedef struct Camera Camera;

void camera_init(Camera* camera);
void camera_turn(Camera* camera, vec2f offset);
void camera_move(Camera* camera, vec3f direction);
void camera_update_view(Camera* camera);
void camera_update_proj(Camera* camera);

#endif