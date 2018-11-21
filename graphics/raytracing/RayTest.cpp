#include <gtest/gtest.h>
#include "Ray.h"
#include "Vec3.h"

TEST(RayTest, whenConstructedTheOriginComponentCanBeAccessed){
  Vec3 origin = Vec3(1.0, 2.0, 3.0);
  Vec3 direction = Vec3(3.0, 2.0, 1.0);

  Ray ray(origin, direction); // ray ray's rules

  EXPECT_EQ(origin.x(), ray.origin().x());
  EXPECT_EQ(origin.y(), ray.origin().y());
  EXPECT_EQ(origin.z(), ray.origin().z());
}

TEST(RayTest, whenConstructedTheDirectionComponentCanBeAccessed){
  Vec3 origin = Vec3(1.0, 2.0, 3.0);
  Vec3 direction = Vec3(3.0, 2.0, 1.0);

  Ray ray(origin, direction); 

  EXPECT_EQ(direction.x(), ray.direction().x());
  EXPECT_EQ(direction.y(), ray.direction().y());
  EXPECT_EQ(direction.z(), ray.direction().z());
}

TEST(RayTest, pointAtParameter){
  Vec3 origin = Vec3(1.0, 2.0, 3.0);
  Vec3 direction = Vec3(3.0, 2.0, 1.0);

  Ray ray(origin, direction); 

  Vec3 point = ray.point_at_parameter(42);

  EXPECT_EQ(point.x(), 127);
  EXPECT_EQ(point.y(), 86);
  EXPECT_EQ(point.z(), 45);
}
