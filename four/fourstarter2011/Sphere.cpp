#include "Sphere.h"

Sphere::Sphere(Vector3f center_point, float radius, Material* mat):Object3D(mat)
{
    this->center_point = center_point;
    this->radius = radius;
}

    
bool Sphere::intersect(const Ray& r, Hit& h, float tmin)
{
    // looking for the closest intersection along a Ray, parameterized by t. 
    // tmin restricts range of intersection
    
    // if intersection found with t > tmin and t < current_t in Hit:
    //          update Hit as necessary
    
    // Note that if new intersection is closer than the previous one,
    //         then both t and Material must be modified
    
    // Important to verify that t >= tmin
    
    // tmin depends on the type of camera, and is not modified by the intersection routine
    
    
    
   Vector3f Ro = r.getOrigin();
   Vector3f Rd = r.getDirection();
   float a = 1.0;
   float b = 2*Vector3f::dot(Ro,Rd);
   float c = Vector3f::dot(Ro,Ro) - radius*radius;
   float d = sqrt(b*b - 4*a*c);
   float t1 = (-b + d)/(2*a);
   float t2 = (-b - d)/(2*a);
   
   // get the closest positive
   float t = 0;
   
   
   // implement for perspective (both t values positive) - othographic can have negatives
   if (t1 <= t2)
   {
       t = t1;
   }
   // for orthographic camera have to deal with negatives...
   
   
           
   if (t >= tmin && t < h.getT()) {
       // update Hit and Material
       h.set(t, mat, h.getNormal());
   }
   
   return false; // placeholder
   
}
