#include <gtest/gtest.h>
#include "Parser.h"
#include <bits/stdc++.h>
#include "Vector3Int.h"
#include "UsersBeginEndPositionsGenerator.h"

TEST(UsersBeginEndPositionsGeneratorTest, GetEmbbUsersBeginPositionsTest) {
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  UsersPositionsGenerator generator(parameters.EMBB_USERS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_X, parameters.MAXIMUM_X, parameters.MINIMUM_Y, parameters.MAXIMUM_Y, parameters.USER_Z);
  vector<Vector3Int> positions;
  generator.GetEmbbUsersBeginPositions(positions);
  EXPECT_EQ(positions.size(), 100);
  // seed of (x, y) is (1, 2)
  EXPECT_EQ(positions[0].GetX(), 0);
  EXPECT_EQ(positions[0].GetY(), 0);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[50].GetX(), 767);
  EXPECT_EQ(positions[50].GetY(), 533);
  EXPECT_EQ(positions[50].GetZ(), 0);
}
