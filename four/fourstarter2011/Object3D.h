/* 
 * File:   Object3D.h
 * Author: drakeley
 *
 * Created on November 6, 2011, 9:32 PM
 */

#ifndef OBJECT3D_H
#define	OBJECT3D_H

#include "Hit.h"
#include "float.h"
#include <vector> 

//extern float EPSILON;// = 0.000001; // is this a good epsilon? -- do we even need epsilon??

class Object3D
{
public:
    Object3D(Material* mat)// constructor
    {
        this->mat = mat;
    }
    Object3D() // dummy constructor to be used by Group, then 
    {
        this->mat = NULL;
    }
    ~Object3D() // destructor
    {
        
    }
    Material* mat;
    
    virtual bool intersect( const Ray& r, Hit& h, float tmin ) = 0;
    
};

#endif	/* OBJECT3D_H */

