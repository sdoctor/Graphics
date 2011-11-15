#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(Vector3f center, Vector3f direction, Vector3f up, float angle):Camera()
{
    this->tmin = 0; //TODO what should it actually be
    
    this->center = center;
    
    Vector3f horiz_vec = Vector3f::cross(up, direction);
    Vector3f ortho_up = Vector3f::cross(horiz_vec, direction);
    
    this->direction = direction.normalized();
    this->up = -ortho_up.normalized();
    this->horiz = -horiz_vec.normalized();
    this->angle = angle;
    
    float height_of_screen = 2.00; // from -1 to 1
    float distance_to_screen = (height_of_screen/2.0)/tan(angle/2.0);
    Vector3f img_center = distance_to_screen*direction;
    this->img_center = img_center;
}

Ray PerspectiveCamera::generateRay(const Vector2f& point)
{
    Vector3f ray_point =  img_center + point.x()*horiz*4.0 + point.y()*up*4.0;
    
    Vector3f dir = center - ray_point;
    dir = dir.normalized();
    
    Ray r = Ray(ray_point, dir);
    return r;
}

float PerspectiveCamera::getTMin() const
{
    return tmin;
}