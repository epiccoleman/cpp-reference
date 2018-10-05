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
