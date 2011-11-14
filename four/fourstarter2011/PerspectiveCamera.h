/* 
 * File:   PerspectiveCamera.h
 * Author: sdrakeley
 *
 * Created on November 8, 2011, 4:41 PM
 */

#ifndef PERSPECTIVECAMERA_H
#define	PERSPECTIVECAMERA_H

#include "Camera.h"

class PerspectiveCamera : public Camera
{
    public:
    PerspectiveCamera(Vector3f center, Vector3f direction, Vector3f up, float angle_radians);
    Vector3f center;
    Vector3f direction;
    Vector3f up;
    Vector3f horiz;
    float angle;
    Vector3f img_center;

    Ray generateRay(const Vector2f& point );
    float getTMin() const;
};

#endif	/* PERSPECTIVECAMERA_H */

