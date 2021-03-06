#ifndef VEC3H
#define VEC3H

#include <math.h>
#include <stdlib.h>
#include <iostream>

class Vec3 {
 public:
    float v[3];

    Vec3() {};  // you need the empty constructor if you want to use this as a member elsewhere
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

bool operator==(const Vec3 &v1, const Vec3 &v2);
bool operator!=(const Vec3 &v1, const Vec3 &v2);
Vec3 operator+(const Vec3 &v1, const Vec3 &v2);
Vec3 operator-(const Vec3 &v1, const Vec3 &v2);
Vec3 operator*(const Vec3 &v1, const Vec3 &v2);
Vec3 operator*(const Vec3 &v1, float t);
Vec3 operator*(float t, const Vec3 &v1);
Vec3 operator/(const Vec3 &v1, const Vec3 &v2);
Vec3 operator/(Vec3 v, float t);

float dot(const Vec3 &v1, const Vec3 &v2);
Vec3 cross(const Vec3 &v1, const Vec3 &v2);
Vec3 unit_vector(Vec3 v);

#endif //VEC3H
