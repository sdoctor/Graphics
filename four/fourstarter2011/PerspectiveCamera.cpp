#include "PerspectiveCamera.h"


PerspectiveCamera::PerspectiveCamera(Vector3f center, Vector3f direction, Vector3f up, float angle_radians):Camera()
{
    tmin = 0; //TODO what should it actually be
}

Ray PerspectiveCamera::generateRay(const Vector2f& point)
{
    Vector3f u = Vector3f(0,0,0); //placeholder
    Vector3f v = Vector3f(0,0,0); //place holder
    Ray r = Ray(u,v);
    return r;
}

float PerspectiveCamera::getTMin() const
{
    return tmin;
}