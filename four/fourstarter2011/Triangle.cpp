
#include "Triangle.h"

Triangle::Triangle(Vector3f v0, Vector3f v1, Vector3f v2, Material* current_material):Object3D(current_material)
{
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
}


bool Triangle::intersect(const Ray& r, Hit& h, float tmin)
{

    Vector3f R0 = r.getOrigin();
    Vector3f Rd = r.getDirection();
    
    Matrix3f A = Matrix3f(v0[0]-v1[0], v0[0]-v2[0], Rd[0],
		    v0[1]-v1[1], v0[1]-v2[1], Rd[1],
		    v0[2]-v1[2], v0[2]-v2[2], Rd[2]);

    Vector3f vec = A.inverse()*Vector3f(v0[0]-R0[0], v0[1]-R0[1], v0[2]-R0[2]);

    float b = vec[0];
    float g = vec[1];
    float t = vec[2];
    if(g+b > 1 || b < 0 || g < 0){
	return false;
    }

    
    if(t < tmin || t > h.getT()){
	return false;
    }
    if(t < h.getT()) {
	Vector3f normal = Vector3f::cross(v2-v1, v0-v1).normalized();
	h.set(t, mat, normal);
    }
    return true;

}