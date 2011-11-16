#include "Transform.h"

Transform::Transform(const Matrix4f& m, Object3D* o) : Object3D()
{
    this->matrix = m;
    this->object = o;
}

bool Transform::intersect(const Ray& r, Hit& h, float tMin) {
    Vector4f ori = Vector4f(r.getOrigin()[0], r.getOrigin()[1], r.getOrigin()[2], 1);
    Vector4f dir = Vector4f(r.getDirection()[0], r.getDirection()[1], r.getDirection()[2], 0);
    Vector4f oriT = matrix.inverse() * ori;
    Vector4f dirT = matrix.inverse() * dir;
    Vector3f origin = Vector3f(oriT[0], oriT[1], oriT[2]);
    Vector3f direction = Vector3f(dirT[0], dirT[1], dirT[2]);
    
    Ray rT = Ray(origin, direction);
    
    bool hit = object->intersect(rT, h, tMin);
    
    Vector4f norm = Vector4f(h.getNormal()[0], h.getNormal()[1], h.getNormal()[2], 0);
    Matrix4f inv = matrix.inverse();
    Matrix4f invT = inv.transposed();
    Vector4f nws = invT * norm;
    Vector3f normal = Vector3f(nws[0], nws[1], nws[2]).normalized();
    h.set(h.getT(), h.getMaterial(), normal);
		
    return hit;
    
}