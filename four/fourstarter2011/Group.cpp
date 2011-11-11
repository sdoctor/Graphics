#include "Group.h"

Group::Group(int numObjects):Object3D()
{
   this->numObjects = numObjects;
   //this->objects = new Object3D*[numObjects];
}
   
bool Group::intersect(const Ray& r, Hit& h, float tmin) {
//   for (int i = 0; i < sizeof(objects); i++) {
//       Object3D* obj = objects[i];
//       if (obj.intersect(r, h, tmin))
//       {
//           return true;
//       }
//   }
   return false;  
}

void Group::addObject(int index, Object3D* obj) 
{
//   numObjects += 1;
//   Object3D* temp[] = new Object3D[numObjects];
//   for (int i = 0; i < sizeof(objects); i++) {
//       temp[i] = objects[i];
//   }
//   temp[numObjects - 1] = obj;
//   objects = temp;
}
