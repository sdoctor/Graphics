/* 
 * File:   Camera.h
 * Author: Sara Drakeley
 *
 */

#ifndef CAMERA_H
#define	CAMERA_H

#include "vecmath.h"
#include "Ray.h"
#include "float.h"
#include <vector>

class Camera {
public:
    
   Camera(){}
   ~Camera(){}
   
   float tmin;
   
   virtual Ray generateRay( const Vector2f& point ) = 0;
   virtual float getTMin() const = 0;
   
   void print_initialized()
   {
       cout << "intialized camera:" << this << "WIth tmin=" << tmin << endl;
   }
};


#endif	/* CAMERA_H */

