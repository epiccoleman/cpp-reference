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

TEST(Vec3Test, arraySubscriptOperatorReturnsNthValueInVector)
{
  Vec3 vec3 = Vec3(1.0, 2.0, 3.0);

  EXPECT_EQ(vec3[0], 1.0);
  EXPECT_EQ(vec3[1], 2.0);
  EXPECT_EQ(vec3[2], 3.0);
}

TEST(Vec3Test, lengthReturnsTheVectorsLength)
{
  Vec3 vec3 = Vec3(1.0, 2.0, 3.0);

  EXPECT_NEAR(vec3.length(), 3.74166, .00001);
}

TEST(Vec3Test, squaredLengthReturnsTheVectorsLengthSquared)
{
  Vec3 vec3 = Vec3(1.0, 2.0, 3.0);

  EXPECT_NEAR(vec3.squared_length(), 14, .00001);
}

TEST(Vec3Test, makeUnitVectorProducesAVectorWithLength1)
{
  Vec3 vec3 = Vec3(1.0, 2.0, 3.0);

  vec3.make_unit_vector();

  EXPECT_NEAR(vec3.length(), 1, .00001);
}

TEST(Vec3Test, vectorsCanBeAddedTogether)
{
  Vec3 vec_a = Vec3(1.0, 2.0, 3.0);
  Vec3 vec_b = Vec3(3.0, 2.0, 1.0);
  Vec3 vec_sum = vec_a + vec_b;

  EXPECT_EQ(vec_sum[0], 4.0);
  EXPECT_EQ(vec_sum[1], 4.0);
  EXPECT_EQ(vec_sum[2], 4.0);
}

TEST(Vec3Test, vectorsCanBeSubtracted)
{
  Vec3 vec_a = Vec3(1.0, 2.0, 3.0);
  Vec3 vec_b = Vec3(3.0, 2.0, 1.0);
  Vec3 vec_subtract = vec_a - vec_b;

  EXPECT_EQ(vec_subtract[0], -2.0);
  EXPECT_EQ(vec_subtract[1], 0.0);
  EXPECT_EQ(vec_subtract[2], 2.0);
}

TEST(Vec3Test, vectorsCanBeMultipliedElementwise)
{
  Vec3 vec_a = Vec3(1.0, 2.0, 3.0);
  Vec3 vec_b = Vec3(3.0, 2.0, 1.0);
  Vec3 vec_product = vec_a * vec_b;

  EXPECT_EQ(vec_product[0], 3.0);
  EXPECT_EQ(vec_product[1], 4.0);
  EXPECT_EQ(vec_product[2], 3.0);
}

TEST(Vec3Test, vectorsCanBeDividedElementwise)
{
  Vec3 vec_a = Vec3(8.0, 16.0, 24.0);
  Vec3 vec_b = Vec3(1.0, 2.0, 3.0);
  Vec3 vec_quotient = vec_a / vec_b;

  EXPECT_EQ(vec_quotient[0], 8.0);
  EXPECT_EQ(vec_quotient[1], 8.0);
  EXPECT_EQ(vec_quotient[2], 8.0);
}

TEST(Vec3Test, canTakeDotProductOfTwoVectors)
{
  Vec3 vec_a = Vec3(8.0, 16.0, 24.0);
  Vec3 vec_b = Vec3(1.0, 2.0, 3.0);

  EXPECT_EQ(dot(vec_a, vec_b), 112.0);
}

TEST(Vec3Test, canTakeCrossProductOfTwoVectors)
{
  Vec3 vec_a = Vec3(8.0, 16.0, 24.0);
  Vec3 vec_b = Vec3(1.0, 2.0, 3.0);
  Vec3 cross_product = cross(vec_a, vec_b);

  EXPECT_EQ(cross_product[0], 0);
  EXPECT_EQ(cross_product[1], 0);
  EXPECT_EQ(cross_product[2], 0);
}


int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
