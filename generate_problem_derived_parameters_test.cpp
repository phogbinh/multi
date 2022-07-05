#include <gtest/gtest.h>
#include "generate_problem_derived_parameters.h"

TEST(GenerateProblemDerivedParametersTest, GetSubcarrierSpacingTest) {
  EXPECT_EQ(GetSubcarrierSpacing(2), 60);
  EXPECT_EQ(GetSubcarrierSpacing(3), 120);
}

TEST(GenerateProblemDerivedParametersTest, GetSubchannelBandwidthTest) {
  EXPECT_EQ(GetSubchannelBandwidth(60), 720000);
  EXPECT_EQ(GetSubchannelBandwidth(15), 180000);
}
