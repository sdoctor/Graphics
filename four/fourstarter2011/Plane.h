/* 
 * File:   Plane.h
 * Author: sdrakeley
 *
 * Created on November 8, 2011, 4:26 PM
 */

#ifndef PLANE_H
#define	PLANE_H

#include "Object3D.h"


class Plane : public Object3D 
{
    public:
    Plane(Vector3f normal, float offset, Material* current_material);
    Vector3f normal;
    float offset;
    
    bool intersect( const Ray& r, Hit& h, float tmin );
};



#endif	/* PLANE_H */

