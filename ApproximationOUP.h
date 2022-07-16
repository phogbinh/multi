#include <bits/stdc++.h>

using namespace std;

class ApproximationOUP {
public:
  // input @ urllcUsersPeakRates[bits/minislot]
  // output @ delta
  void GetDelta(const vector<vector<int>>& urllcUsersPeakRates, vector<vector<int>>& delta) {
    const int URLLC_USERS_NUM = urllcUsersPeakRates.size();
    const int BASE_STATIONS_NUM = urllcUsersPeakRates[0].size();
    delta.resize(URLLC_USERS_NUM, vector<int>(BASE_STATIONS_NUM));
    for (size_t urllcUserIdx = 0; urllcUserIdx < URLLC_USERS_NUM; ++urllcUserIdx) {
      int highestPeakRate = INT_MIN;
      size_t linkBaseStationIdx;
      for (size_t baseStationIdx = 0; baseStationIdx < BASE_STATIONS_NUM; ++baseStationIdx) {
        if (urllcUsersPeakRates[urllcUserIdx][baseStationIdx] > highestPeakRate) {
          highestPeakRate = urllcUsersPeakRates[urllcUserIdx][baseStationIdx];
          linkBaseStationIdx = baseStationIdx;
        }
      }
      delta[urllcUserIdx][linkBaseStationIdx] = 1;
    }
  }
  // input @ baseStationIdx, urllcUsersDemands[bits/minislot], urllcUsersPeakRates[bits/minislot], delta
  // output @
  int GetBaseStationPunctureSubchannelsNum(const size_t baseStationIdx, const vector<int>& urllcUsersDemands, const vector<vector<int>>& urllcUsersPeakRates, const vector<vector<int>>& delta) {
    int punctureSubchannelsNum = 0;
    for (size_t urllcUserIdx = 0; urllcUserIdx < urllcUsersDemands.size(); ++urllcUserIdx) {
      if (delta[urllcUserIdx][baseStationIdx] == 0) continue;
      punctureSubchannelsNum += (int)ceil((double)urllcUsersDemands[urllcUserIdx] / (double)urllcUsersPeakRates[urllcUserIdx][baseStationIdx]);
    }
    return punctureSubchannelsNum;
  }
private:
};
