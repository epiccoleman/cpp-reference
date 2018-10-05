#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vec3 {
    float v[3];
 public:
    Vec3(float x, float y, float z);
    float x();
    float y();
    float z();
};

#endif //VEC3H
