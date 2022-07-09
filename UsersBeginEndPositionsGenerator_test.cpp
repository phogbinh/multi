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

TEST(UsersBeginEndPositionsGeneratorTest, GetEmbbUsersEndPositionsTest) {
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  UsersPositionsGenerator generator(parameters.EMBB_USERS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_X, parameters.MAXIMUM_X, parameters.MINIMUM_Y, parameters.MAXIMUM_Y, parameters.USER_Z);
  vector<Vector3Int> positions;
  generator.GetEmbbUsersEndPositions(positions);
  EXPECT_EQ(positions.size(), 100);
  // seed of (x, y) is (1, 2)
  EXPECT_EQ(positions[0].GetX(), 537);
  EXPECT_EQ(positions[0].GetY(), 74);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[50].GetX(), 464);
  EXPECT_EQ(positions[50].GetY(), 928);
  EXPECT_EQ(positions[50].GetZ(), 0);
}

TEST(UsersBeginEndPositionsGeneratorTest, GetUrllcUsersBeginPositionsTest) {
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  UsersPositionsGenerator generator(parameters.EMBB_USERS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_X, parameters.MAXIMUM_X, parameters.MINIMUM_Y, parameters.MAXIMUM_Y, parameters.USER_Z);
  vector<Vector3Int> positions;
  generator.GetUrllcUsersBeginPositions(positions);
  EXPECT_EQ(positions.size(), 10);
  // seed of (x, y) is (1, 2)
  EXPECT_EQ(positions[0].GetX(), 689);
  EXPECT_EQ(positions[0].GetY(), 378);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[6].GetX(), 537);
  EXPECT_EQ(positions[6].GetY(), 74);
  EXPECT_EQ(positions[6].GetZ(), 0);
}

TEST(UsersBeginEndPositionsGeneratorTest, GetUrllcUsersEndPositionsTest) {
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  UsersPositionsGenerator generator(parameters.EMBB_USERS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_X, parameters.MAXIMUM_X, parameters.MINIMUM_Y, parameters.MAXIMUM_Y, parameters.USER_Z);
  vector<Vector3Int> positions;
  generator.GetUrllcUsersEndPositions(positions);
  EXPECT_EQ(positions.size(), 10);
  // seed of (x, y) is (1, 2)
  EXPECT_EQ(positions[0].GetX(), 577);
  EXPECT_EQ(positions[0].GetY(), 153);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[6].GetX(), 801);
  EXPECT_EQ(positions[6].GetY(), 602);
  EXPECT_EQ(positions[6].GetZ(), 0);
}
