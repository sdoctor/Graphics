#include "Group.h"

Group::Group(int numObjects) : Object3D() 
{
   this->numObjects = numObjects;
   this->objects = new Object3D*[numObjects];
}
   
bool Group::intersect(const Ray& r, Hit& h, float tmin) 
{
    // Note - modifies hit! so that hit has the smallest intersection time
    //cout << "checking intersection - numObjects = " << numObjects << endl;
    vector<float> intersection_times;
    for (int i = 0; i < numObjects; i++) 
    {    
//        cout << "testing for object " << i << endl;
       if (objects[i]->intersect(r, h, tmin)) 
       {
           // for debugging - see if it is keeping track of smallest t's
           cout << "intersection for object " << i << endl;
           intersection_times.push_back(h.getT());
       }
       else
       {
//           cout << "no intersection for object " << i << endl;
       }
    }
    if (intersection_times.size() > 0)
    {
        cout << "number of intersections for the ray =" << intersection_times.size() << endl;
        float min_time = -FLT_MAX;
        for (size_t k = 0; k < intersection_times.size(); k++)
        {
            if (intersection_times[k] < min_time)
            {
                min_time = intersection_times[k];
            }
        }
        
        //assert (min_time == h.getT() && "the minimum of intersection times should be h.getT...");
        return true;
    }
    return false;  
}

void Group::addObject(int index, Object3D* obj) 
{
    objects[index] = obj;
}
