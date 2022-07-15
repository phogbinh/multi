#include <bits/stdc++.h>
#include "parser.h"
#include "communications.h"

using namespace std;

int main() {
  Parameters parameters;
  GetParameters(parameters);
  const int SUBCHANNEL_BANDWIDTH = GetSubchannelBandwidth(GetSubcarrierSpacing(parameters.NUMEROLOGY));
  const int SUBCHANNEL_THERMAL_NOISE = GetSubchannelThermalNoise(parameters.THERMAL_NOISE_DENSITY, SUBCHANNEL_BANDWIDTH);
  const double TIME_SLOT_DURATION = GetTimeSlotDuration(parameters.NUMEROLOGY);
  vector<Vector3Int> baseStationsPositions;
  GetPositions(string(getenv("MULTI_DIR")) + "base_stations_positions.txt", baseStationsPositions);
  for (size_t timeSlotIdx = 0; timeSlotIdx < parameters.TIME_SLOTS_NUM; ++timeSlotIdx) {
    vector<Vector3Int> positions;
    GetPositions(GetEmbbUsersPositionsFilepath(timeSlotIdx), positions);
    ofstream file;
    file.open(string(getenv("MULTI_DIR")) + "users_peak_rates/embb-" + to_string(timeSlotIdx) + ".txt");
    for (size_t embbUserIdx = 0; embbUserIdx < parameters.EMBB_USERS_NUM; ++embbUserIdx) {
      for (size_t baseStationIdx = 0; baseStationIdx < parameters.BASE_STATIONS_NUM; ++baseStationIdx) {
        const double DISTANCE = baseStationsPositions[baseStationIdx].GetDistanceTo(positions[embbUserIdx]); // downlink direction
        for (size_t subchannelIdx = 0; subchannelIdx < parameters.SUBCHANNELS_NUM; ++subchannelIdx) {
          const long long int SUBCHANNEL_FREQUENCY = GetSubchannelFrequency(parameters.BASE_FREQUENCY, subchannelIdx, SUBCHANNEL_BANDWIDTH);
          const double PATH_LOSS_SHADOWING = GetPathLossShadowing(SUBCHANNEL_FREQUENCY, DISTANCE);
          const double RECEIVED_POWER = GetReceivedPower(parameters.TRANSMITTED_POWER, PATH_LOSS_SHADOWING);
          file << GetTimeSlotPeakRate(SUBCHANNEL_BANDWIDTH, RECEIVED_POWER, SUBCHANNEL_THERMAL_NOISE, TIME_SLOT_DURATION) << endl;
        }
      }
    }
    file.close();
  }
  const double TIME_MINISLOT_DURATION = GetTimeMinislotDuration(TIME_SLOT_DURATION, parameters.TIME_MINISLOTS_NUM);
  for (size_t timeSlotIdx = 0; timeSlotIdx < parameters.TIME_SLOTS_NUM; ++timeSlotIdx) {
    for (size_t timeMinislotIdx = 0; timeMinislotIdx < parameters.TIME_MINISLOTS_NUM; ++timeMinislotIdx) {
      vector<Vector3Int> positions;
      GetPositions(GetUrllcUsersPositionsFilepath(timeSlotIdx, timeMinislotIdx), positions);
      ofstream file;
      file.open(string(getenv("MULTI_DIR")) + "users_peak_rates/urllc-" + to_string(timeSlotIdx) + "-" + to_string(timeMinislotIdx) + ".txt");
      for (size_t urllcUserIdx = 0; urllcUserIdx < parameters.URLLC_USERS_NUM; ++urllcUserIdx) {
        for (size_t baseStationIdx = 0; baseStationIdx < parameters.BASE_STATIONS_NUM; ++baseStationIdx) {
          vector<long long int> subchannelFrequencies(parameters.SUBCHANNELS_NUM);
          for (size_t subchannelIdx = 0; subchannelIdx < parameters.SUBCHANNELS_NUM; ++subchannelIdx) {
            subchannelFrequencies[subchannelIdx] = GetSubchannelFrequency(parameters.BASE_FREQUENCY, subchannelIdx, SUBCHANNEL_BANDWIDTH);
          }
          const double DISTANCE = baseStationsPositions[baseStationIdx].GetDistanceTo(positions[urllcUserIdx]); // downlink direction
          file << GetUrllcUserBaseStationTimeMinislotPeakRate(SUBCHANNEL_BANDWIDTH, parameters.TRANSMITTED_POWER, subchannelFrequencies, DISTANCE, SUBCHANNEL_THERMAL_NOISE, TIME_MINISLOT_DURATION, parameters.TIME_MINISLOTS_NUM) << endl;
        }
      }
      file.close();
    }
  }
  return 0;
}
