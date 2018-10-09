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

float Vec3::operator[](int i) const {
  return v[i];
}

float Vec3::length() const {
  return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

float Vec3::squared_length() const {
  return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

void Vec3::make_unit_vector() {
  float k = 1.0 / this->length();
  v[0] *= k;
  v[1] *= k;
  v[2] *= k;
}

Vec3 operator+(const Vec3 &v1, const Vec3 &v2){
  return Vec3(v1[0] + v2[0],
              v1[1] + v2[1],
              v1[2] + v2[2]);
}

Vec3 operator-(const Vec3 &v1, const Vec3 &v2){
  return Vec3(v1[0] - v2[0],
              v1[1] - v2[1],
              v1[2] - v2[2]);
}

Vec3 operator*(const Vec3 &v1, const Vec3 &v2){
  return Vec3(v1[0] * v2[0],
              v1[1] * v2[1],
              v1[2] * v2[2]);
}

Vec3 operator/(const Vec3 &v1, const Vec3 &v2){
  return Vec3(v1[0] / v2[0],
              v1[1] / v2[1],
              v1[2] / v2[2]);
}

float dot(const Vec3 &v1, const Vec3 &v2){
  return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}
