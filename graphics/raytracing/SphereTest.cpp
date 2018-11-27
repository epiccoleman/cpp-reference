#include <gtest/gtest.h>
#include "Sphere.h"

TEST(SphereTest, sphereCanBeConstructed){
  Vec3 center = Vec3(0, 0, 0);
  float radius = 10;
  Sphere sphere = Sphere(center, radius);

  EXPECT_TRUE(sphere.center == center);
  EXPECT_EQ(sphere.radius, radius);
}
