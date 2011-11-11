/* 
 * File:   Sphere.h
 * Author: drakeley
 *
 * Created on November 6, 2011, 9:37 PM
 */

#ifndef SPHERE_H
#define	SPHERE_H

#include "Object3D.h"

class Sphere : public Object3D
{
public:
    Sphere(Vector3f center_point, float radius, Material* mat);
    Vector3f center_point;
    float radius;
    
    bool intersect(const Ray& r, Hit& h, float tmin);
};

#endif	/* SPHERE_H */

