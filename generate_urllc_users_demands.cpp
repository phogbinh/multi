#include <bits/stdc++.h>
#include "parser.h"
#include "UrllcUsersDemandsGenerator.h"

using namespace std;

int main() {
  Parameters parameters;
  GetParameters(parameters);
  UrllcUsersDemandsGenerator generator(parameters.TIME_SLOTS_NUM, parameters.TIME_MINISLOTS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_URLLC_USER_DEMAND, parameters.MAXIMUM_URLLC_USER_DEMAND);
  vector<vector<vector<int>>> demands;
  generator.GetDemands(demands);
  for (size_t timeSlotIdx = 0; timeSlotIdx < parameters.TIME_SLOTS_NUM; ++timeSlotIdx) {
    for (size_t timeMinislotIdx = 0; timeMinislotIdx < parameters.TIME_MINISLOTS_NUM; ++timeMinislotIdx) {
      ofstream file;
      file.open(string(getenv("MULTI_DIR")) + "urllc_users_demands/" + to_string(timeSlotIdx) + "-" + to_string(timeMinislotIdx) + ".txt");
      for (size_t urllcUserIdx = 0; urllcUserIdx < parameters.URLLC_USERS_NUM; ++urllcUserIdx) {
        file << demands[timeSlotIdx][timeMinislotIdx][urllcUserIdx] << endl;
      }
      file.close();
    }
  }
  return 0;
}
