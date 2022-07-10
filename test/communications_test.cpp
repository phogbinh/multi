#include <gtest/gtest.h>
#include "test.h"
#include "../communications.h"

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

TEST(GenerateProblemDerivedParametersTest, GetPathLossShadowingTest) {
  EXPECT_THROW(double pathLossShadowing = GetPathLossShadowing(28000000000, 0.9), std::runtime_error);
  EXPECT_THROW(double pathLossShadowing = GetPathLossShadowing(23000000, 1.0), std::runtime_error);
  EXPECT_NEAR(GetPathLossShadowing(28000000000, 10.0), 85.98493281, DELTA);
}

TEST(GenerateProblemDerivedParametersTest, GetReceivedPowerTest) {
  EXPECT_NEAR(GetReceivedPower(20, 100.0), -80.0, DELTA);
}

TEST(GenerateProblemDerivedParametersTest, GetSubchannelThermalNoiseTest) {
  EXPECT_EQ(GetSubchannelThermalNoise(-204, 720000), -145);
}

TEST(GenerateProblemDerivedParametersTest, GetShannonRateTest) {
  EXPECT_NEAR(GetShannonRate(720000, -80.0, -145), 15546623.812551368, DELTA);
}

TEST(GenerateProblemDerivedParametersTest, GetTimeSlotPeakRateTest) {
  int peakRate = GetTimeSlotPeakRate(720000, -80.0, -145, 0.00025);
  EXPECT_EQ(peakRate % TIME_SLOT_SYMBOLS_NUM, 0);
  EXPECT_EQ(peakRate, 3864);
}

TEST(GenerateProblemDerivedParametersTest, GetTimeMinislotPeakRateTest) {
  int peakRate = GetTimeMinislotPeakRate(720000, -80.0, -145, 1E-3 / 28.0, 7);
  EXPECT_EQ(peakRate % (TIME_SLOT_SYMBOLS_NUM / 7), 0); // 24 symbols
  EXPECT_EQ(peakRate, 552);
}
