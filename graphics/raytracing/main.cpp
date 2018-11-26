#include <iostream>
#include "Vec3.h"
#include "Ray.h"

float hit_sphere(const Vec3& center, float radius, const Ray& ray){
  Vec3 oc = ray.origin() - center;
  float a = dot(ray.direction(), ray.direction());
  float b = 2.0 * dot(oc, ray.direction());
  float c = dot(oc, oc) - radius * radius;
  float discriminant = b * b - 4 * a * c;

  if (discriminant < 0){
    return -1.0;
  } else {
    return ( -b - sqrt(discriminant)) / (2.0 * a);
  }
}

Vec3 color_at_ray(const Ray& ray){

  float t = hit_sphere(Vec3(0, 0, -1), 0.5, ray);
  if (t > 0.0){
    Vec3 N = unit_vector(ray.point_at_parameter(t) - Vec3(0, 0, -1));
    return 0.5 * Vec3(N.x() + 1, N.y() + 1, N.z() + 1);
  }

  Vec3 unit_direction = unit_vector(ray.direction());
  t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0); // here we're lerping white (1, 1, 1) to "blue" (.5, .7, 1)
}

int main(){
  int nx = 200;
  int ny = 100;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";
  Vec3 lower_left_corner(-2.0, -1.0, -1.0);
  Vec3 horizontal(4.0, 0.0, 0.0);
  Vec3 vertical(0.0, 2.0, 0.0);
  Vec3 origin(0.0, 0.0, 0.0);

  for(int j = ny - 1; j >= 0; j--){
    for(int i = 0; i < nx; i++){

      float u = float(i) / float(nx);
      float v = float(j) / float(ny);

      Ray ray(origin, lower_left_corner + (horizontal * u ) + (vertical * v));
      Vec3 color = color_at_ray(ray);

      int ir = int(255.99 * color[0]);
      int ig = int(255.99 * color[1]);
      int ib = int(255.99 * color[2]);
      std::cout << ir << " " <<  ig << " " << ib << "\n";
    }
  }
}
