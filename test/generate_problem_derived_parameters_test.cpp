#include <gtest/gtest.h>
#include "test.h"
#include "../generate_problem_derived_parameters.h"

TEST(GenerateProblemDerivedParametersTest, GetSubcarrierSpacingTest) {
  EXPECT_EQ(GetSubcarrierSpacing(2), 60);
  EXPECT_EQ(GetSubcarrierSpacing(3), 120);
}

TEST(GenerateProblemDerivedParametersTest, GetSubchannelBandwidthTest) {
  EXPECT_EQ(GetSubchannelBandwidth(60), 720000);
  EXPECT_EQ(GetSubchannelBandwidth(15), 180000);
}

TEST(GenerateProblemDerivedParametersTest, GetTimeSlotDurationTest) {
  EXPECT_NEAR(GetTimeSlotDuration(2), 2.5 * 1E-4, DELTA);
}

TEST(GenerateProblemDerivedParametersTest, GetTimeMinislotDurationTest) {
  EXPECT_NEAR(GetTimeMinislotDuration(2.5 * 1E-4, 7), 1E-3 / 28.0, DELTA);
}

TEST(GenerateProblemDerivedParametersTest, GetSubchannelFrequencyTest) {
  EXPECT_EQ(GetSubchannelFrequency(28000000000, 0, 720000), 28000000000);
  EXPECT_EQ(GetSubchannelFrequency(28000000000, 50, 720000), 28036000000);
}
