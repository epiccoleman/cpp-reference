#include "Ray.h"

Ray::Ray(const Vec3& a, const Vec3& b){
  A = a;
  B = b;
}

Vec3 Ray::origin() const {
  return A;
}
