#include <gtest/gtest.h>
#include "../parser.h"
#include <bits/stdc++.h>
#include "../Vector3Int.h"
#include "../UsersBeginEndPositionsGenerator.h"

class UsersBeginEndPositionsGeneratorTest : public ::testing::Test {
protected:
  void SetUp() override {
    Parameters parameters;
    GetParameters(parameters);
    _generatorPtr = new UsersBeginEndPositionsGenerator(parameters.EMBB_USERS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_X, parameters.MAXIMUM_X, parameters.MINIMUM_Y, parameters.MAXIMUM_Y, parameters.USER_Z);
  }

  UsersBeginEndPositionsGenerator* _generatorPtr;
};

TEST_F(UsersBeginEndPositionsGeneratorTest, GetEmbbUsersBeginPositionsTest) {
  vector<Vector3Int> positions;
  _generatorPtr->GetEmbbUsersBeginPositions(positions);
  EXPECT_EQ(positions.size(), 100);
  // seed of (x, y) is (1, 50000)
  EXPECT_EQ(positions[0].GetX(), 0);
  EXPECT_EQ(positions[0].GetY(), 391);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[50].GetX(), 767);
  EXPECT_EQ(positions[50].GetY(), 739);
  EXPECT_EQ(positions[50].GetZ(), 0);
}

TEST_F(UsersBeginEndPositionsGeneratorTest, GetEmbbUsersEndPositionsTest) {
  vector<Vector3Int> positions;
  _generatorPtr->GetEmbbUsersEndPositions(positions);
  EXPECT_EQ(positions.size(), 100);
  // seed of (x, y) is (1, 50000)
  EXPECT_EQ(positions[0].GetX(), 537);
  EXPECT_EQ(positions[0].GetY(), 198);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[50].GetX(), 464);
  EXPECT_EQ(positions[50].GetY(), 526);
  EXPECT_EQ(positions[50].GetZ(), 0);
}

TEST_F(UsersBeginEndPositionsGeneratorTest, GetUrllcUsersBeginPositionsTest) {
  vector<Vector3Int> positions;
  _generatorPtr->GetUrllcUsersBeginPositions(positions);
  EXPECT_EQ(positions.size(), 10);
  // seed of (x, y) is (1, 50000)
  EXPECT_EQ(positions[0].GetX(), 689);
  EXPECT_EQ(positions[0].GetY(), 45);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[6].GetX(), 537);
  EXPECT_EQ(positions[6].GetY(), 287);
  EXPECT_EQ(positions[6].GetZ(), 0);
}

TEST_F(UsersBeginEndPositionsGeneratorTest, GetUrllcUsersEndPositionsTest) {
  vector<Vector3Int> positions;
  _generatorPtr->GetUrllcUsersEndPositions(positions);
  EXPECT_EQ(positions.size(), 10);
  // seed of (x, y) is (1, 50000)
  EXPECT_EQ(positions[0].GetX(), 577);
  EXPECT_EQ(positions[0].GetY(), 832);
  EXPECT_EQ(positions[0].GetZ(), 0);
  EXPECT_EQ(positions[6].GetX(), 801);
  EXPECT_EQ(positions[6].GetY(), 16);
  EXPECT_EQ(positions[6].GetZ(), 0);
}
