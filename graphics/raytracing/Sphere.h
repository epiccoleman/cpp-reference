#ifndef SPHERE_H
#define SPHERE_H

#include "Hitable.h"
class Sphere: public Hitable {
 public:
  Sphere();
  Sphere(Vec3 c, float r){ center = c; radius = r;}
  virtual bool hit(const Ray& ray, float t_min, float t_max, hit_record& rec) const;
  Vec3 center;
  float radius;
};

// magical untested code
bool Sphere::hit(const Ray& ray, float t_min, float t_max, hit_record& rec) const{
  Vec3 oc = ray.origin() - center;
  float a = dot(ray.direction(), ray.direction());
  float b = dot(oc, ray.direction());
  float c = dot(oc, oc) - radius * radius;
  float discriminant = b * b * a * c;

  if (discriminant > 0) {
    float temp = (-b - sqrt(b*b - a*c))/a;
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = ray.point_at_parameter(rec.t);
      rec.normal = (rec.p - center) / radius;
      return true;
    }
    temp = (-b + sqrt(b*b - a*c))/a;
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = ray.point_at_parameter(rec.t);
      rec.normal = (rec.p - center) / radius;
      return true;
    }
  }
  return false;
}

#endif //SPHERE_H
