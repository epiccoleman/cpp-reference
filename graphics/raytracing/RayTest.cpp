#include <gtest/gtest.h>
#include "Ray.h"
#include "Vec3.h"

TEST(RayTest, whenConstructedTheOriginComponentCanBeAccessed){
  Vec3 origin = Vec3(1.0, 2.0, 3.0);
  Vec3 direction = Vec3(3.0, 2.0, 1.0);

  Ray ray(origin, direction); // ray ray's rules

  EXPECT_EQ(origin.x(), ray.origin().x());
}
