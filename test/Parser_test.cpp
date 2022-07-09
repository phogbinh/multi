#include <gtest/gtest.h>
#include "../Parser.h"

TEST(ParserTest, GetParametersTest) {
  Parser parser;
  Parameters parameters;
  parser.GetParameters(parameters);
  EXPECT_EQ(parameters.BASE_FREQUENCY, 28);
  EXPECT_EQ(parameters.TIME_SLOTS_NUM, 200);
  EXPECT_EQ(parameters.TIME_MINISLOTS_NUM, 7);
  EXPECT_EQ(parameters.BASE_STATIONS_NUM, 3);
  EXPECT_EQ(parameters.EMBB_USERS_NUM, 100);
  EXPECT_EQ(parameters.URLLC_USERS_NUM, 10);
  EXPECT_EQ(parameters.MAXIMUM_URLLC_DEMAND_RATE, 4000);
  EXPECT_EQ(parameters.CHANNEL_BANDWIDTH, 40000000);
  EXPECT_EQ(parameters.NUMEROLOGY, 2);
  EXPECT_EQ(parameters.SUBCHANNELS_NUM, 51);
  EXPECT_EQ(parameters.TRANSMISSION_POWER, 20);
  EXPECT_EQ(parameters.THERMAL_NOISE_DENSITY, -204);
  EXPECT_EQ(parameters.MINIMUM_X, 0);
  EXPECT_EQ(parameters.MAXIMUM_X, 1000);
  EXPECT_EQ(parameters.MINIMUM_Y, 0);
  EXPECT_EQ(parameters.MAXIMUM_Y, 1000);
  EXPECT_EQ(parameters.BASE_STATION_Z, 100);
  EXPECT_EQ(parameters.USER_Z, 0);
}
