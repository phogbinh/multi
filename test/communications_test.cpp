#include <gtest/gtest.h>
#include "test.h"
#include "../communications.h"

TEST(CommunicationsTest, GetSubcarrierSpacingTest) {
  EXPECT_EQ(GetSubcarrierSpacing(2), 60);
  EXPECT_EQ(GetSubcarrierSpacing(3), 120);
}

TEST(CommunicationsTest, GetSubchannelBandwidthTest) {
  EXPECT_EQ(GetSubchannelBandwidth(60), 720000);
  EXPECT_EQ(GetSubchannelBandwidth(15), 180000);
}

TEST(CommunicationsTest, GetTimeSlotDurationTest) {
  EXPECT_NEAR(GetTimeSlotDuration(2), 2.5 * 1E-4, DELTA);
}

TEST(CommunicationsTest, GetTimeMinislotDurationTest) {
  EXPECT_NEAR(GetTimeMinislotDuration(2.5 * 1E-4, 7), 1E-3 / 28.0, DELTA);
}

TEST(CommunicationsTest, GetSubchannelFrequencyTest) {
  EXPECT_EQ(GetSubchannelFrequency(28000000000, 0, 720000), 28000000000);
  EXPECT_EQ(GetSubchannelFrequency(28000000000, 50, 720000), 28036000000);
}

TEST(CommunicationsTest, GetPathLossShadowingTest) {
  EXPECT_THROW(double pathLossShadowing = GetPathLossShadowing(28000000000, 0.9), std::runtime_error);
  EXPECT_THROW(double pathLossShadowing = GetPathLossShadowing(23000000, 1.0), std::runtime_error);
  EXPECT_NEAR(GetPathLossShadowing(28000000000, 10.0), 85.98493281, DELTA);
}

TEST(CommunicationsTest, GetReceivedPowerTest) {
  EXPECT_NEAR(GetReceivedPower(20, 100.0), -80.0, DELTA);
}

TEST(CommunicationsTest, GetSubchannelThermalNoiseTest) {
  EXPECT_EQ(GetSubchannelThermalNoise(-204, 720000), -145);
}

TEST(CommunicationsTest, GetShannonRateTest) {
  EXPECT_NEAR(GetShannonRate(720000, -80.0, -145), 15546623.812551368, DELTA);
}

TEST(CommunicationsTest, GetTimeSlotPeakRateTest) {
  int peakRate = GetTimeSlotPeakRate(720000, -80.0, -145, 0.00025);
  EXPECT_EQ(peakRate % TIME_SLOT_SYMBOLS_NUM, 0);
  EXPECT_EQ(peakRate, 3864);
}

TEST(CommunicationsTest, GetTimeMinislotPeakRateTest) {
  int peakRate = GetTimeMinislotPeakRate(720000, -80.0, -145, 1E-3 / 28.0, 7);
  EXPECT_EQ(peakRate % (TIME_SLOT_SYMBOLS_NUM / 7), 0); // 24 symbols
  EXPECT_EQ(peakRate, 552);
}

TEST(CommunicationsTest, GetTimeSlotPeakRateEqualToTimeMinislotNumMultipleOfGetTimeMinislotPeakRateTest) {
  EXPECT_EQ(GetTimeSlotPeakRate(720000, -100.0, -145, 0.00025), 7 * GetTimeMinislotPeakRate(720000, -100.0, -145, 1E-3 / 28.0, 7));
}
