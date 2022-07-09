#include <gtest/gtest.h>
#include "test.h"
#include "../Vector3Int.h"

TEST(Vector3IntTest, ConstructorTest) {
  Vector3Int vector(2, 1, 3);
  EXPECT_EQ(vector.GetX(), 2);
  EXPECT_EQ(vector.GetY(), 1);
  EXPECT_EQ(vector.GetZ(), 3);
}

TEST(Vector3IntTest, GetDistanceToTest) {
  Vector3Int vector(1, 2, 3);
  EXPECT_NEAR(vector.GetDistanceTo(Vector3Int(1, -5, 1000)), 997.024573418, DELTA);
}
