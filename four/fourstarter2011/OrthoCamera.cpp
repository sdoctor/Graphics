#include "OrthoCamera.h"



OrthoBasis::OrthoBasis(Vector3f point, Vector3f up, Vector3f horiz, Vector3f direction)
{
    
    this->point = point;
    this->up = up;
    this->horiz = horiz;
    this->direction = direction;
    
}

OrthographicCamera::OrthographicCamera(Vector3f img_center, Vector3f direction, Vector3f up_vec, float img_size):Camera()
{
    this->img_size = img_size;
    
    Vector3f ortho_up = getUpVec(direction, up_vec);
    Vector3f horiz_vec = ortho_up * direction;
    OrthoBasis basis = OrthoBasis(img_center, ortho_up, horiz_vec, direction);
    
    //this->basis = basis;
    this->point = img_center;
    this->up = ortho_up;
    this->horiz = horiz_vec;
    this->direction = direction;
    
    this->tmin = FLT_MIN;
    
}



Ray OrthographicCamera::generateRay(const Vector2f& point )
// Used to generate rays for each screen-space coordinate
{
    Vector3f ray_point = Vector3f(point[0], point[1], 100.0); // HELP! WHAT IS THE z?
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

