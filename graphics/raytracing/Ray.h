#ifndef RAY_H
#define RAY_H
#include "Vec3.h"

class Ray {
 public:
  Ray() {}
  Ray(const Vec3 &a, const Vec3 &b);

  Vec3 origin() const;
  Vec3 direction() const;
  Vec3 point_at_parameter(float t) const;

  Vec3 A;
  Vec3 B;
};

#endif //RAY_H
