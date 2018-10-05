#include <gtest/gtest.h>
#include "vec3.h"

TEST(Vec3Test, xReturnsXComponentOfVector)
{
  Vec3* vec3 = new Vec3(1.0, 2.0, 3.0);
  EXPECT_EQ(1.0, vec3->x());
  delete vec3;
}

TEST(Vec3Test, yReturnsYComponentOfVector)
{
  Vec3* vec3 = new Vec3(1.0, 2.0, 3.0);
  EXPECT_EQ(2.0, vec3->y());
  delete vec3;
}

TEST(Vec3Test, zReturnsZComponentOfVector)
{
  Vec3* vec3 = new Vec3(1.0, 2.0, 3.0);
  EXPECT_EQ(3.0, vec3->z());
  delete vec3;
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
