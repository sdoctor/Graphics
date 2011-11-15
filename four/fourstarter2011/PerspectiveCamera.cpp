#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(Vector3f center, Vector3f direction, Vector3f up, float angle):Camera()
{
    this->tmin = 0; //TODO what should it actually be
    
    this->center = center;
    
    Vector3f horiz_vec = Vector3f::cross(direction, up);
    Vector3f ortho_up = Vector3f::cross(horiz_vec, direction);
    
    this->direction = direction.normalized();
    this->up = ortho_up.normalized();
    this->horiz = horiz_vec.normalized();
    this->angle = angle;
    
//    float height_of_screen = 2.00; // from -1 to 1
//    float distance_to_screen = (height_of_screen/2.0)/tan(angle/2.0);
//    Vector3f img_center = distance_to_screen*direction;
    Vector3f img_center = direction/tan(angle/2.0);
    this->img_center = img_center;
//    cout << "img_center = " << img_center[0] << "," << img_center[1] << "," << img_center[2] << endl;
}

Ray PerspectiveCamera::generateRay(const Vector2f& point)
{
    Vector3f ray_direction =  img_center + point.x()*horiz + point.y()*up;
//    cout << "raypoint = " << ray_point[0] << "," << ray_point[1] << "," << ray_point[2] << endl;
    
//    Vector3f dir = ray_direction + img_center*direction;
//    dir = dir.normalized();
    
//    cout << "dir = " << dir[0] << "," << dir[1] << "," << dir[2] << endl;
    
    Ray r = Ray(center, ray_direction.normalized());
    return r;
}

float PerspectiveCamera::getTMin() const
{
    return 0;
}