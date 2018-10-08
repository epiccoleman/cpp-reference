#include "Vec3.h"

Vec3::Vec3(float x, float y, float z){
  v[0] = x;
  v[1] = y;
  v[2] = z;
}

float Vec3::x(){
  return v[0];
}

float Vec3::y(){
  return v[1];
}

float Vec3::z(){
  return v[2];
}

float Vec3::r(){
  return v[0];
}

float Vec3::g(){
  return v[1];
}

float Vec3::b(){
  return v[2];
}

const Vec3& Vec3::operator+() const {
  return *this;
}

Vec3 Vec3::operator-() const {
  return Vec3(-v[0], -v[1], -v[2]);
}
