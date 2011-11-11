#ifndef MATERIAL_H
#define MATERIAL_H

#include <cassert>
#include <vecmath.h>

#include "Ray.h"
#include "Hit.h"

class Material
{
public:

    Material( const Vector3f& d_color )
    {
        diffuseColor = d_color;
    }

    virtual ~Material()
    {

    }

    virtual Vector3f getDiffuseColor()
    {
    	return diffuseColor;
    }

protected:

    Vector3f diffuseColor;
     
};

#endif // MATERIAL_H
