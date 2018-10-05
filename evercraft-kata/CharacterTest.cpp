#include <gtest/gtest.h>
#include "Character.h"

TEST(CharacterTest, WhenNameIsCalledThenNameIsReturn)
{
  Character* character = new Character();
  EXPECT_EQ("Eric", character->getName());
  delete character;
}

int main(int argc, char* argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
