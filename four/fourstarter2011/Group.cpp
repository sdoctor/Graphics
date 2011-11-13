#include "Group.h"

Group::Group(int numObjects) : Object3D() 
{
   this->numObjects = numObjects;
   this->objects = new Object3D*[numObjects];
}
   
bool Group::intersect(const Ray& r, Hit& h, float tMin) 
{
    
   for (int i = 0; i < sizeof(objects); i++) 
   {
       if (objects[i]->intersect(r, h, tMin)) 
       {
	   return true; // To improve: Could somehow organize objects by distance, then binary search?
       }
   }
   return false;  
}

void Group::addObject(int index, Object3D* obj) 
{
    objects[index] = obj;
}
