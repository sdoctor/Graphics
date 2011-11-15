#include "OrthoCamera.h"




OrthographicCamera::OrthographicCamera(Vector3f img_center, Vector3f direction, Vector3f up_vec, float img_size):Camera()
{
    this->img_size = img_size;
    
//    Vector3f ortho_up = getUpVec(direction, up_vec);
//    Vector3f horiz_vec = ortho_up * direction;
//    OrthoBasis basis = OrthoBasis(img_center, ortho_up, horiz_vec, direction);
//    
    
    Vector3f horiz_vec = Vector3f::cross(up_vec, direction);
    Vector3f ortho_up = Vector3f::cross(direction, horiz_vec);
    
    //this->basis = basis;
    this->img_center = img_center;
    this->up = ortho_up.normalized();
    this->horiz = horiz_vec.normalized();
    this->direction = direction.normalized();
    
    this->tmin = -FLT_MAX;
            
    
}



Ray OrthographicCamera::generateRay(const Vector2f& point )
// Used to generate rays for each screen-space coordinate
{
    // for ortho camera, it's just direction coming out of the 2d point
    // just need to translate direction
    
    // screen coordinates vary from (-1, -1) to (1, 1)
    // the origin of the ray coordinates should vary from:
    //img_center - (img_size*up)/2.0 - (img_size*horiz)/2.0;
    //img_center + (img_size*up)/2.0 + (img_size*horiz)/2.0;
    
    // Point is going to range from 0, screen width, to 0, screen height
    // need to map that onto -1, -1 -> 1, 1
              
        
    Vector3f ray_point =  img_center + point.x()*(img_size/2.0)*horiz + point.y()*(img_size/2.0)*up;
    Ray r = Ray(ray_point, -direction);
    return r;
    
}
    


float OrthographicCamera::getTMin() const
// useful when tracing rays through the scene
{
    return tmin;
}



