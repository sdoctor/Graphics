#include "OrthoCamera.h"



OrthoBasis::OrthoBasis(Vector3f point, Vector3f up, Vector3f horiz, Vector3f direction)
{
    
    this->img_center = point;
    this->up = up;
    this->horiz = horiz;
    this->direction = direction;
    
}

OrthographicCamera::OrthographicCamera(Vector3f img_center, Vector3f direction, Vector3f up_vec, float img_size):Camera()
{
    this->img_size = img_size;
    
//    Vector3f ortho_up = getUpVec(direction, up_vec);
//    Vector3f horiz_vec = ortho_up * direction;
//    OrthoBasis basis = OrthoBasis(img_center, ortho_up, horiz_vec, direction);
//    
    
    Vector3f horiz_vec = Vector3f::cross(up_vec, direction);
    Vector3f ortho_up = Vector3f::cross(horiz_vec, direction);
    
    //this->basis = basis;
    this->img_center = img_center;
    this->up = ortho_up.normalized();
    this->horiz = horiz_vec.normalized();
    this->direction = direction;
    
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
              
        
    Vector3f ray_point =  img_center + point[0]*img_size*up + point[1]*img_size*horiz;
    Ray r = Ray(ray_point, direction);
    return r;
    
}
    


float OrthographicCamera::getTMin() const
// useful when tracing rays through the scene
{
    return tmin;
}


Vector3f OrthographicCamera::proj(Vector3f u, Vector3f v)
// gets the projection of v onto u
{
    float numer = Vector3f::dot(u, v);
    float denom = Vector3f::dot(u, u);
    float multiply = numer/denom;
    return multiply*u;
}

Vector3f OrthographicCamera::getUpVec(Vector3f direction, Vector3f orig_up) 
{
   Vector3f ortho_up = orig_up - proj(direction, orig_up);
   return ortho_up.normalized();
}

