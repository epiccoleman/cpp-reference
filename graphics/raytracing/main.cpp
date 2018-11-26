#include <iostream>
#include "Vec3.h"
#include "Ray.h"

Vec3 backgroundColor(const Ray& ray){
  Vec3 unit_direction = unit_vector(ray.direction());
  float t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);
}

int main(){
  int nx = 200;
  int ny = 100;

  std::cout << "P3\n" << nx << " " << ny << "\n255\n";
  Vec3 lower_left_corner(-2.0, -1.0, -1.0);
  Vec3 horizontal(4.0, 2.0, 0.0);
  Vec3 vertical(0.0, 2.0, 0.0);
  Vec3 origin(0.0, 0.0, 0.0);

  for(int j = ny - 1; j >= 0; j--){
    for(int i = 0; i < nx; i++){

      float u = float(i) / float(nx);
      float v = float(j) / float(ny);

      Ray ray(origin, lower_left_corner + (horizontal * u ) + (vertical * v));
      Vec3 color = backgroundColor(ray);

      int ir = int(255.99 * color[0]);
      int ig = int(255.99 * color[1]);
      int ib = int(255.99 * color[2]);
      std::cout << ir << " " <<  ig << " " << ib << "\n";
    }
  }
}
