


#include "Triangle.h"

Triangle::Triangle(Vector3f v0, Vector3f v1, Vector3f v2, Material* current_material):Object3D(current_material)
{
    
}


bool Triangle::intersect(const Ray& r, Hit& h, float tmin)
{
    return false;
}