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
//    cout << "in sphere:: intersect" << endl;
    
    // QUESTION: how to translate??
   Vector3f Ro = r.getOrigin() - center_point;
   Vector3f Rd = r.getDirection();
   // explicit equation of ray => P(t) = Ro + t*Rd
   
   // implicit eqn of sphere => H(P) = ||P||^2 - r^2 = 0
   
   //(Ro + t*Rd)^2 - r^2 = 0;
   
   
   // we need to check that the parameterized eqn of t is on surface
   
   // Note, eqn of sphere is (x-x0)^2+(y-y0)^2+(z-z0)^2 = r^2
   
   float a = 1.0; // remember ||Rd|| = 1
   float b = 2*Vector3f::dot(Ro,Rd);
   float c = Vector3f::dot(Ro,Ro) - radius*radius;
   
   float d = sqrt(b*b - 4*a*c); // discriminant
   if (isnan(d))
   {
       return false;
       
   }
   else
   {
//       cout << "NOT NAN!!" << endl;
   }
   
//   cout << "a =" << a << ", b=" << b << ", c=" << c << ", d=" << d << endl;
   // Three cases depending on sign of d
   // d = 0 : grazing the surface
   // d > 0 : 2 different points - just use closest positive, unless eye in center of sphere
   
   //solutions
   float t1 = (-b + d)/(2*a);
   float t2 = (-b - d)/(2*a);
   
      
//   cout << "    t1 =" << t1 << ", t2 = " << t2 << endl;
   // get the closest positive (smaller of the two)
   float t_curr = tmin;
   if (t1 > t2)
   {
       t_curr = t2;
   }
   else if (t1 < t2)
   {
       t_curr = t1;
   }
   else if (t1 == t2) // d = 0, grazing the surface (could both be neg?)
   {
       t_curr = t1;
   }
   //else if () // are there other cases, like if both negative?
   else{}
   
   // implement for perspective (both t values positive) 
   // for orthographic camera have to deal with negatives...
   
   
//   cout << "t_curr = " << t_curr << endl;
//   cout << "t_curr < h.getT()? " << (t_curr < h.getT()) << endl;
//   cout << "t_curr > tmin?" << (t_curr > tmin) << endl;
   // Now, hit should have the t of the last hit it encountered
   // and if this intersection is less than the last one, then
   // we want to update hit, otherwise we do nothing
   if (t_curr > tmin && t_curr < h.getT()) {
       // calculate normal = Q/||Q||
       Vector3f Q = Ro + t_curr*Rd;
       Q -= center_point;
       Vector3f normal = Q/Q.abs();
       
       // update Hit and Material
       h.set(t_curr, mat, normal);
//       cout << "returning true" << endl;
       return true;
   }
   else{}
   
//   cout << "returning false: " << endl;
   return false; // don't change hit at all
   
}

