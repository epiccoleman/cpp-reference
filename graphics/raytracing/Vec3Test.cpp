#include <gtest/gtest.h>
#include "Vec3.h"

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

TEST(Vec3Test, rReturnsXComponentOfVector)
{
  Vec3* vec3 = new Vec3(1.0, 2.0, 3.0);
  EXPECT_EQ(1.0, vec3->r());
  delete vec3;
}

TEST(Vec3Test, gReturnsYComponentOfVector)
{
  Vec3* vec3 = new Vec3(1.0, 2.0, 3.0);
  EXPECT_EQ(2.0, vec3->g());
  delete vec3;
}

TEST(Vec3Test, bReturnsZComponentOfVector)
{
  Vec3* vec3 = new Vec3(1.0, 2.0, 3.0);
  EXPECT_EQ(3.0, vec3->b());
  delete vec3;
}

TEST(Vec3Test, vectorsCanBeNegated)
{
  Vec3 vec3 = Vec3(1.0, 2.0, 3.0);

  vec3 = -vec3;

  EXPECT_EQ(-1.0, vec3.x());
  EXPECT_EQ(-2.0, vec3.y());
  EXPECT_EQ(-3.0, vec3.z());
}

TEST(Vec3Test, unaryPlusReturnsTheSameVector)
{
  Vec3 vec3 = Vec3(1.0, 2.0, 3.0);

  Vec3 another_vec3 = +vec3;

  EXPECT_EQ(vec3.x(), another_vec3.x());
  EXPECT_EQ(vec3.y(), another_vec3.y());
  EXPECT_EQ(vec3.z(), another_vec3.z());
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
