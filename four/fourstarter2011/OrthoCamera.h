/* 
 * File:   OrthoCamera.h
 * Author: drakeley
 *
 * Created on November 7, 2011, 6:28 PM
 */

#ifndef ORTHOCAMERA_H
#define	ORTHOCAMERA_H

#include "Camera.h"

class OrthoBasis
{
public:
    OrthoBasis(Vector3f img_center, Vector3f up, Vector3f horiz, Vector3f direction);
    
    Vector3f img_center;
    Vector3f up;
    Vector3f horiz;
    Vector3f direction;
    
};

class OrthographicCamera : public Camera
{
    public:
        
    OrthographicCamera(Vector3f img_center, Vector3f direction, Vector3f up_vec, float img_size);
    
    
    //OrthoBasis basis;
    Vector3f img_center;
    float img_size;
    
    // Note these used to all be an orthobasis
    Vector3f point;
    Vector3f up;
    Vector3f horiz;
    Vector3f direction;
    
    
    Ray generateRay(const Vector2f& point );
    float getTMin() const;
    
    
    Vector3f proj(Vector3f u, Vector3f v);
    Vector3f getUpVec(Vector3f direction, Vector3f orig_up);
    
};



#endif	/* ORTHOCAMERA_H */

