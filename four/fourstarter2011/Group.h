/* 
 * File:   Group.h
 * Author: sdrakeley
 *
 * Created on November 8, 2011, 9:12 AM
 */

#ifndef GROUP_H
#define	GROUP_H

#include "Object3D.h"

class Group : public Object3D
{

public:
   Group(int numObjects);
   int numObjects;
   Object3D *objects; // ARRAY SOMEHOW
   
   void addObject(int index, Object3D* obj);
   bool intersect(const Ray& r, Hit& h, float tmin);
   
};

#endif	/* GROUP_H */

