#include "Plane.h"


Plane::Plane(Vector3f normal, float offset, Material* current_material) : Object3D(current_material)
{
    this->normal = normal;
    this->offset = offset;
}

bool Plane::intersect(const Ray& r, Hit& h, float tMin) {
    
    Vector3f R0 = r.getOrigin(); 
    Vector3f Rd = r.getDirection();
    
    
    float a = Vector3f::dot(normal, R0);
    float b = Vector3f::dot(normal, Rd);
    float num = (offset + a);
    float den = b;
    
//    return true;
    
    if (isnan(den) || den == 0) {
        
	return false;
    }
    float t = num/den;
 
    if (t < h.getT() && t > tMin) {
	h.set(t, mat, normal);
	return true;
    }
    
    
    return false;
}