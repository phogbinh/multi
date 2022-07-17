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
      if (!delta[urllcUserIdx][baseStationIdx]) continue;
      punctureSubchannelsNum += GetUrllcUserPunctureSubchannelsNum(urllcUsersDemands[urllcUserIdx], urllcUsersPeakRates[urllcUserIdx][baseStationIdx]);
    }
    return punctureSubchannelsNum;
  }
  // input @ embbUsersPeakRates[bits/slot], embbUsersMovingAverageRates[bits/slot], alpha
  // output @
  void GetPunctureCosts(const vector<vector<vector<int>>>& embbUsersPeakRates, const vector<double>& embbUsersMovingAverageRates, const vector<vector<vector<int>>>& alpha, vector<vector<double>>& punctureCosts) {
    const size_t BASE_STATIONS_NUM = embbUsersPeakRates[0].size();
    const size_t SUBCHANNELS_NUM = embbUsersPeakRates[0][0].size();
    punctureCosts.resize(BASE_STATIONS_NUM, vector<double>(SUBCHANNELS_NUM));
    for (size_t baseStationIdx = 0; baseStationIdx < BASE_STATIONS_NUM; ++baseStationIdx) {
      for (size_t subchannelIdx = 0; subchannelIdx < SUBCHANNELS_NUM; ++subchannelIdx) {
        for (size_t embbUserIdx = 0; embbUserIdx < embbUsersPeakRates.size(); ++embbUserIdx) {
          punctureCosts[baseStationIdx][subchannelIdx] += (double)alpha[embbUserIdx][baseStationIdx][subchannelIdx] * (double)embbUsersPeakRates[embbUserIdx][baseStationIdx][subchannelIdx] / embbUsersMovingAverageRates[embbUserIdx];
        }
      }
    }
  }
  // input @ baseStationPunctureSubchannelsNum, baseStationPunctureCosts
  // output @ baseStationPunctureSubchannels
  void GetBaseStationPunctureSubchannels(const int baseStationPunctureSubchannelsNum, const vector<double>& baseStationPunctureCosts, vector<size_t>& baseStationPunctureSubchannels) {
    const int SUBCHANNELS_NUM = baseStationPunctureCosts.size();
    vector<pair<double, size_t>> costIndex(SUBCHANNELS_NUM);
    for (size_t subchannelIdx = 0; subchannelIdx < SUBCHANNELS_NUM; ++subchannelIdx) {
      costIndex[subchannelIdx] = {baseStationPunctureCosts[subchannelIdx], subchannelIdx};
    }
    sort(costIndex.begin(), costIndex.end(), [](const pair<double, size_t>& a, const pair<double, size_t>& b) {
      return a.first < b.first || (a.first == b.first && a.second < b.second);
    });
    baseStationPunctureSubchannels.resize(baseStationPunctureSubchannelsNum);
    for (size_t i = 0; i < baseStationPunctureSubchannelsNum; ++i) {
      baseStationPunctureSubchannels[i] = costIndex[i].second;
    }
  }
  // input @ baseStationIdx, urllcUsersDemands[bits/minislot], urllcUsersPeakRates[bits/minislot], delta
  // output @ punctureUrllcUserSubchannelsNum
  void GetBaseStationPunctureUrllcUserSubchannelsNum(const size_t baseStationIdx, const vector<int>& urllcUsersDemands, const vector<vector<int>>& urllcUsersPeakRates, const vector<vector<int>>& delta, unordered_map<size_t, size_t>& punctureUrllcUserSubchannelsNum) {
    punctureUrllcUserSubchannelsNum.clear();
    for (size_t urllcUserIdx = 0; urllcUserIdx < urllcUsersDemands.size(); ++urllcUserIdx) {
      if (!delta[urllcUserIdx][baseStationIdx]) continue;
      punctureUrllcUserSubchannelsNum[urllcUserIdx] = GetUrllcUserPunctureSubchannelsNum(urllcUsersDemands[urllcUserIdx], urllcUsersPeakRates[urllcUserIdx][baseStationIdx]);
    }
  }
  // input @ urllcUserDemand[bits/minislot], urllcUserPeakRate[bits/minislot]
  // output @
  size_t GetUrllcUserPunctureSubchannelsNum(const int urllcUserDemand, const int urllcUserPeakRate) {
    return (int)ceil((double)urllcUserDemand / (double)urllcUserPeakRate);
  }
  // input @ baseStationPunctureSubchannels, baseStationPunctureUrllcUserSubchannelsNum
  // output @ baseStationPunctureUrllcUserSubchannels
  void GetBaseStationPunctureUrllcUserSubchannels(const vector<size_t>& baseStationPunctureSubchannels, const unordered_map<size_t, size_t>& baseStationPunctureUrllcUserSubchannelsNum, unordered_map<size_t, vector<size_t>>& baseStationPunctureUrllcUserSubchannels) {
    size_t idx = 0;
    for (auto iterator = baseStationPunctureUrllcUserSubchannelsNum.begin(); iterator != baseStationPunctureUrllcUserSubchannelsNum.end(); ++iterator) {
      size_t punctureSubchannelsNum = iterator->second;
      baseStationPunctureUrllcUserSubchannels[iterator->first] = vector<size_t>();
      while (punctureSubchannelsNum--) {
        baseStationPunctureUrllcUserSubchannels[iterator->first].push_back(baseStationPunctureSubchannels[idx]);
        ++idx;
      }
    }
  }
  // input @ urllcUsersNum, baseStationsPunctureUrllcUserSubchannels, alpha
  // output @ beta
  void GetBeta(const int urllcUsersNum, const vector<unordered_map<size_t, vector<size_t>>>& baseStationsPunctureUrllcUserSubchannels, const vector<vector<vector<int>>>& alpha, vector<vector<vector<vector<int>>>>& beta) {
    const int EMBB_USERS_NUM = alpha.size();
    const int BASE_STATIONS_NUM = alpha[0].size();
    const int SUBCHANNELS_NUM = alpha[0][0].size();
    beta.resize(urllcUsersNum, vector<vector<vector<int>>>(EMBB_USERS_NUM, vector<vector<int>>(BASE_STATIONS_NUM, vector<int>(SUBCHANNELS_NUM))));
    for (size_t baseStationIdx = 0; baseStationIdx < BASE_STATIONS_NUM; ++baseStationIdx) {
      for (auto iterator = baseStationsPunctureUrllcUserSubchannels[baseStationIdx].begin(); iterator != baseStationsPunctureUrllcUserSubchannels[baseStationIdx].end(); ++iterator) {
        for (size_t subchannelIdx : iterator->second) {
          beta[iterator->first][GetEmbbUserIndex(baseStationIdx, subchannelIdx, alpha)][baseStationIdx][subchannelIdx] = 1;
        }
      }
    }
  }
  // input @ baseStationIdx, subchannelIdx, alpha
  // output @
  size_t GetEmbbUserIndex(const size_t baseStationIdx, const size_t subchannelIdx, const vector<vector<vector<int>>>& alpha) {
    for (size_t embbUserIdx = 0; embbUserIdx < alpha.size(); ++embbUserIdx) {
      if (alpha[embbUserIdx][baseStationIdx][subchannelIdx]) {
        return embbUserIdx;
      }
    }
    throw runtime_error("(" + to_string(baseStationIdx) + ", " + to_string(subchannelIdx) + ") is not allocated to any eMBB users");
  }
  // input @ embbUsersPeakRates[bits/slot], embbUsersMovingAverageRates[bits/slot], alpha, urllcUsersDemands[bits/minislot], urllcUsersPeakRates[bits/minislot]
  // output @ beta, delta
  void GetPolicy(const vector<vector<vector<int>>>& embbUsersPeakRates,
                 const vector<double>& embbUsersMovingAverageRates,
                 const vector<vector<vector<int>>>& alpha,
                 const vector<int>& urllcUsersDemands,
                 const vector<vector<int>>& urllcUsersPeakRates,
                 vector<vector<vector<vector<int>>>>& beta,
                 vector<vector<int>>& delta) {
    const int BASE_STATIONS_NUM = embbUsersPeakRates[0].size();
    vector<vector<double>> punctureCosts;
    GetPunctureCosts(embbUsersPeakRates, embbUsersMovingAverageRates, alpha, punctureCosts);
    GetDelta(urllcUsersPeakRates, delta);
    vector<unordered_map<size_t, vector<size_t>>> baseStationsPunctureUrllcUserSubchannels(BASE_STATIONS_NUM);
    for (size_t baseStationIdx = 0; baseStationIdx < BASE_STATIONS_NUM; ++baseStationIdx) {
      vector<size_t> baseStationPunctureSubchannels;
      GetBaseStationPunctureSubchannels(GetBaseStationPunctureSubchannelsNum(baseStationIdx, urllcUsersDemands, urllcUsersPeakRates, delta), punctureCosts[baseStationIdx], baseStationPunctureSubchannels);
      unordered_map<size_t, size_t> baseStationPunctureUrllcUserSubchannelsNum;
      GetBaseStationPunctureUrllcUserSubchannelsNum(baseStationIdx, urllcUsersDemands, urllcUsersPeakRates, delta, baseStationPunctureUrllcUserSubchannelsNum);
      unordered_map<size_t, vector<size_t>> baseStationPunctureUrllcUserSubchannels;
      GetBaseStationPunctureUrllcUserSubchannels(baseStationPunctureSubchannels, baseStationPunctureUrllcUserSubchannelsNum, baseStationPunctureUrllcUserSubchannels);
      baseStationsPunctureUrllcUserSubchannels[baseStationIdx] = baseStationPunctureUrllcUserSubchannels;
    }
    GetBeta(urllcUsersDemands.size(), baseStationsPunctureUrllcUserSubchannels, alpha, beta);
  }
private:
};
