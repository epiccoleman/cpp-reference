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

    const Vec3& operator+() const;
    Vec3 operator-() const;
    float operator[](int i) const;
    float& operator[](int i){ return v[i]; } // not sure what this is for yet

    //skipping math assignment operators for now...
    /* Vec3& operator+=(const Vec3 &v2); */
    /* Vec3& operator-=(const Vec3 &v2); */
    /* Vec3& operator*=(const Vec3 &v2); */
    /* Vec3& operator/=(const Vec3 &v2); */
    /* Vec3& operator*=(const float t); */
    /* Vec3& operator/=(const float t); */

    float length() const;
    float squared_length() const;
    void make_unit_vector();
};

Vec3 operator+(const Vec3 &v1, const Vec3 &v2);
Vec3 operator-(const Vec3 &v1, const Vec3 &v2);
Vec3 operator*(const Vec3 &v1, const Vec3 &v2);
Vec3 operator/(const Vec3 &v1, const Vec3 &v2);

float dot(const Vec3 &v1, const Vec3 &v2);
Vec3 cross(const Vec3 &v1, const Vec3 &v2);

#endif //VEC3H
