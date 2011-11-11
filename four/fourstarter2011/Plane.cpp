


#include "Plane.h"
Plane::Plane(Vector3f normal, float offset, Material* current_material):Object3D(current_material)
{
    
}

bool Plane::intersect(const Ray& r, Hit& h, float tmin)
{
    return false;
}