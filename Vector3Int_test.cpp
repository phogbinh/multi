#include <gtest/gtest.h>
#include "Vector3Int.h"

TEST(Vector3IntTest, ConstructorTest) {
  Vector3Int vector(2, 1, 3);
  EXPECT_EQ(vector.GetX(), 2);
  EXPECT_EQ(vector.GetY(), 1);
  EXPECT_EQ(vector.GetZ(), 3);
}
