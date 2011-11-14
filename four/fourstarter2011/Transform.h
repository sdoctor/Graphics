/* 
 * File:   Transform.h
 * Author: sdrakeley
 *
 * Created on November 8, 2011, 4:27 PM
 */

#ifndef TRANSFORM_H
#define	TRANSFORM_H

#include "Object3D.h"


class Transform //: public Object3D
{
public:
    Transform(Matrix4f matrix, Object3D* object)
    {}
//    Matrix4f matrix;
//    Object3D* object;
//    
//    bool intersect(const Ray& r, Hit& h, float tmin);
};

#endif	/* TRANSFORM_H */

