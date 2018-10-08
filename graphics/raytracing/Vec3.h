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
    float r();
    float g();
    float b();

    //TODO - not sure what this is for.
    inline const Vec3& operator+() const { return *this; }
    inline Vec3 operator-() const { return Vec3(-v[0], -v[1], -v[2]); }


};

#endif //VEC3H
