#include <gtest/gtest.h>
#include "test.h"
#include "../ApproximationOUP.h"

TEST(ApproximationOUPTest, GetDeltaTest) {
  ApproximationOUP policymaker;
  vector<vector<int>> delta;
  policymaker.GetDelta({{1, 3, 2}, {10, 10, 0}}, delta);
  EXPECT_EQ(delta.size(), 2);
  EXPECT_EQ(delta[0].size(), 3);
  EXPECT_EQ(delta[0][0], 0);
  EXPECT_EQ(delta[0][1], 1);
  EXPECT_EQ(delta[0][2], 0);
  EXPECT_EQ(delta[1][0], 1);
  EXPECT_EQ(delta[1][1], 0);
  EXPECT_EQ(delta[1][2], 0);
}

TEST(ApproximationOUPTest, GetBaseStationPunctureSubchannelsNumTest) {
  ApproximationOUP policymaker;
  EXPECT_EQ(policymaker.GetBaseStationPunctureSubchannelsNum(0, {5, 0}, {{1, 3, 2}, {10, 10, 0}}, {{0, 1, 0}, {1, 0, 0}}), 0);
  EXPECT_EQ(policymaker.GetBaseStationPunctureSubchannelsNum(1, {5, 0}, {{1, 3, 2}, {10, 10, 0}}, {{0, 1, 0}, {1, 0, 0}}), 2);
}

TEST(ApproximationOUPTest, GetPunctureCostsTest) {
  vector<vector<vector<int>>> embbUsersPeakRates = {
    {
      {0  },
      {100},
      {3  }
    },
    {
      {0  },
      {0  },
      {0  }
    }
  };
  vector<vector<vector<double>>> embbUsersMovingAverageRates = {
    {
      {100.0},
      {5.0  },
      {5.0  }
    },
    {
      {100.0},
      {100.0},
      {100.0}
    }
  };
  vector<vector<vector<int>>> alpha = {
    {
      {0},
      {1},
      {1}
    },
    {
      {1},
      {0},
      {0}
    }
  };
  ApproximationOUP policymaker;
  vector<vector<double>> punctureCosts;
  policymaker.GetPunctureCosts(embbUsersPeakRates, embbUsersMovingAverageRates, alpha, punctureCosts);
  EXPECT_EQ(punctureCosts.size(), 3);
  EXPECT_EQ(punctureCosts[0].size(), 1);
  EXPECT_NEAR(punctureCosts[0][0], 0.0, DELTA);
  EXPECT_NEAR(punctureCosts[1][0], 20.0, DELTA);
  EXPECT_NEAR(punctureCosts[2][0], 0.6, DELTA);
}

TEST(ApproximationOUPTest, GetBaseStationPunctureSubchannelsTest) {
  ApproximationOUP policymaker;
  vector<size_t> punctureSubchannels;
  policymaker.GetBaseStationPunctureSubchannels(3, {5.0, 0.0, 0.2, 5.0}, punctureSubchannels);
  EXPECT_EQ(punctureSubchannels.size(), 3);
  EXPECT_EQ(punctureSubchannels[0], 1);
  EXPECT_EQ(punctureSubchannels[1], 2);
  EXPECT_EQ(punctureSubchannels[2], 0);
}

TEST(ApproximationOUPTest, GetBaseStationPunctureUrllcUserSubchannelsNumTest) {
  ApproximationOUP policymaker;
  unordered_map<size_t, size_t> punctureUrllcUserSubchannelsNum;
  policymaker.GetBaseStationPunctureUrllcUserSubchannelsNum(0, {5, 0, 3}, {{0, 2, 0}, {2, 0, 0}, {0, 2, 0}}, {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}}, punctureUrllcUserSubchannelsNum);
  EXPECT_EQ(punctureUrllcUserSubchannelsNum.size(), 1);
  EXPECT_EQ(punctureUrllcUserSubchannelsNum[1], 0);
  policymaker.GetBaseStationPunctureUrllcUserSubchannelsNum(1, {5, 0, 3}, {{0, 2, 0}, {2, 0, 0}, {0, 2, 0}}, {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}}, punctureUrllcUserSubchannelsNum);
  EXPECT_EQ(punctureUrllcUserSubchannelsNum.size(), 2);
  EXPECT_EQ(punctureUrllcUserSubchannelsNum[0], 3);
  EXPECT_EQ(punctureUrllcUserSubchannelsNum[2], 2);
  policymaker.GetBaseStationPunctureUrllcUserSubchannelsNum(2, {5, 0, 3}, {{0, 2, 0}, {2, 0, 0}, {0, 2, 0}}, {{0, 1, 0}, {1, 0, 0}, {0, 1, 0}}, punctureUrllcUserSubchannelsNum);
  EXPECT_EQ(punctureUrllcUserSubchannelsNum.size(), 0);
}

TEST(ApproximationOUPTest, GetUrllcUserPunctureSubchannelsNumTest) {
  ApproximationOUP policymaker;
  EXPECT_EQ(policymaker.GetUrllcUserPunctureSubchannelsNum(5, 1), 5);
  EXPECT_EQ(policymaker.GetUrllcUserPunctureSubchannelsNum(5, 2), 3);
  EXPECT_EQ(policymaker.GetUrllcUserPunctureSubchannelsNum(2, 10), 1);
  EXPECT_EQ(policymaker.GetUrllcUserPunctureSubchannelsNum(0, 100), 0);
}

TEST(ApproximationOUPTest, GetBaseStationPunctureUrllcUserSubchannelsTest) {
  ApproximationOUP policymaker;
  unordered_map<size_t, vector<size_t>> punctureUrllcUserSubchannels;
  policymaker.GetBaseStationPunctureUrllcUserSubchannels({50, 0, 23}, {{2, 2}, {0, 1}}, punctureUrllcUserSubchannels);
  EXPECT_EQ(punctureUrllcUserSubchannels.size(), 2);
  EXPECT_EQ(punctureUrllcUserSubchannels[0].size(), 1);
  EXPECT_EQ(punctureUrllcUserSubchannels[0][0], 50);
  EXPECT_EQ(punctureUrllcUserSubchannels[2].size(), 2);
  EXPECT_EQ(punctureUrllcUserSubchannels[2][0], 0);
  EXPECT_EQ(punctureUrllcUserSubchannels[2][1], 23);
}

TEST(ApproximationOUPTest, GetBetaTest) {
  vector<unordered_map<size_t, vector<size_t>>> baseStationsPunctureUrllcSubchannels = {
    {
      {9, {1, 2}},
      {0, {}}
    },
    {
      {1, {4, 3, 2, 1, 0}}
    },
    {
      {5, {0}}
    }
  };
  vector<vector<vector<int>>> alpha = {
    {
      {0, 0, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {0, 0, 0, 0, 0}
    },
    {
      {1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0},
      {1, 1, 1, 1, 1}
    }
  };
  ApproximationOUP policymaker;
  vector<vector<vector<vector<int>>>> beta;
  policymaker.GetBeta(10, baseStationsPunctureUrllcSubchannels, alpha, beta);
  for (size_t subchannelIdx = 0; subchannelIdx < 5; ++subchannelIdx) {
    EXPECT_EQ(beta[1][0][1][subchannelIdx], 1);
  }
  EXPECT_EQ(beta[5][1][2][0], 1);
  EXPECT_EQ(beta[9][1][0][1], 1);
  EXPECT_EQ(beta[9][0][0][2], 1);
  size_t nonPunctureSubchannelsNum = 0;
  for (size_t urllcUserIdx = 0; urllcUserIdx < 10; ++urllcUserIdx) {
    for (size_t embbUserIdx = 0; embbUserIdx < 2; ++embbUserIdx) {
      for (size_t baseStationIdx = 0; baseStationIdx < 3; ++baseStationIdx) {
        for (size_t subchannelIdx = 0; subchannelIdx < 5; ++subchannelIdx) {
          if (!beta[urllcUserIdx][embbUserIdx][baseStationIdx][subchannelIdx]) {
            ++nonPunctureSubchannelsNum;
          }
        }
      }
    }
  }
  EXPECT_EQ(nonPunctureSubchannelsNum, 292);
}
