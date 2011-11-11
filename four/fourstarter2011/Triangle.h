/* 
 * File:   Triangle.h
 * Author: sdrakeley
 *
 * Created on November 8, 2011, 4:26 PM
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "Object3D.h"

class Triangle : public Object3D
{
    public:
        Triangle(Vector3f v0, Vector3f v1, Vector3f v2, Material* current_material);
        Vector3f v0;
        Vector3f v1; 
        Vector3f v2;
        Material* current_material;
        
        bool intersect( const Ray& r, Hit& h, float tmin );
};

#endif	/* TRIANGLE_H */

