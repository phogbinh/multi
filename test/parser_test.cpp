#include <gtest/gtest.h>
#include "../parser.h"
#include "../Vector3Int.h"

TEST(ParserTest, GetParametersTest) {
  Parameters parameters;
  GetParameters(parameters);
  EXPECT_EQ(parameters.BASE_FREQUENCY, 28000000000);
  EXPECT_EQ(parameters.TIME_SLOTS_NUM, 200);
  EXPECT_EQ(parameters.TIME_MINISLOTS_NUM, 7);
  EXPECT_EQ(parameters.BASE_STATIONS_NUM, 3);
  EXPECT_EQ(parameters.EMBB_USERS_NUM, 100);
  EXPECT_EQ(parameters.URLLC_USERS_NUM, 10);
  EXPECT_EQ(parameters.MAXIMUM_URLLC_DEMAND_RATE, 4000);
  EXPECT_EQ(parameters.CHANNEL_BANDWIDTH, 40000000);
  EXPECT_EQ(parameters.NUMEROLOGY, 2);
  EXPECT_EQ(parameters.SUBCHANNELS_NUM, 51);
  EXPECT_EQ(parameters.TRANSMITTED_POWER, 20);
  EXPECT_EQ(parameters.THERMAL_NOISE_DENSITY, -204);
  EXPECT_EQ(parameters.MINIMUM_X, 0);
  EXPECT_EQ(parameters.MAXIMUM_X, 1000);
  EXPECT_EQ(parameters.MINIMUM_Y, 0);
  EXPECT_EQ(parameters.MAXIMUM_Y, 1000);
  EXPECT_EQ(parameters.BASE_STATION_Z, 100);
  EXPECT_EQ(parameters.USER_Z, 0);
  EXPECT_EQ(parameters.MINIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY, 1);
  EXPECT_EQ(parameters.MAXIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY, 5);
  EXPECT_EQ(parameters.MINIMUM_URLLC_USER_DEMAND, 0);
  EXPECT_EQ(parameters.MAXIMUM_URLLC_USER_DEMAND, 4000);
}

TEST(ParserTest, GetUsersPositionsTest) {
  vector<Vector3Int> positions;
  GetPositions(string(getenv("MULTI_DIR")) + "test/positions_mock.txt", positions);
  EXPECT_EQ(positions.size(), 3);
  EXPECT_EQ(positions[0].GetX(), 0);
  EXPECT_EQ(positions[0].GetY(), -2147483648);
  EXPECT_EQ(positions[0].GetZ(), 2147483647);
  EXPECT_EQ(positions[1].GetX(), 1);
  EXPECT_EQ(positions[1].GetY(), 1);
  EXPECT_EQ(positions[1].GetZ(), 1);
  EXPECT_EQ(positions[2].GetX(), 2);
  EXPECT_EQ(positions[2].GetY(), 3);
  EXPECT_EQ(positions[2].GetZ(), 4);
}
