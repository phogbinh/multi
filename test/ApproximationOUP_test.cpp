#include <gtest/gtest.h>
#include "../ApproximationOUP.h"

TEST(ApproximationOUPTest, GetDeltaTest) {
  ApproximationOUP policymaker;
  vector<vector<int>> delta;
  policymaker.GetDelta({{1, 3, 2}, {10, 10, 0}}, delta);
  EXPECT_EQ(delta.size(), 2);
  EXPECT_EQ(delta[0].size(), 3);
  EXPECT_EQ(delta[0][0], 0);
  EXPECT_EQ(delta[0][1], 1);
  EXPECT_EQ(delta[0][2], 0);
  EXPECT_EQ(delta[1][0], 1);
  EXPECT_EQ(delta[1][1], 0);
  EXPECT_EQ(delta[1][2], 0);
}
