#include <gtest/gtest.h>
#include "../parser.h"
#include "../UrllcUsersDemandsGenerator.h"

TEST(UrllcUsersDemandsGeneratorTest, GetDemandsTest) {
  Parameters parameters;
  GetParameters(parameters);
  UrllcUsersDemandsGenerator generator(parameters.TIME_SLOTS_NUM, parameters.TIME_MINISLOTS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_URLLC_USER_DEMAND, parameters.MAXIMUM_URLLC_USER_DEMAND);
  vector<vector<vector<int>>> demands;
  generator.GetDemands(demands);
  EXPECT_EQ(demands.size(), 200);
  EXPECT_EQ(demands[0].size(), 7);
  EXPECT_EQ(demands[0][0].size(), 10);
  // seed of demand is 1
  EXPECT_EQ(demands[0][0][0], 0);
  EXPECT_EQ(demands[150][5][9], 185);
}
