#include <bits/stdc++.h>
#include "Vector3Int.h"

using namespace std;

#define USERS_POSITIONS_DIR "users_positions/"

struct Parameters {
  long long int BASE_FREQUENCY;
  int TIME_SLOTS_NUM;
  int TIME_MINISLOTS_NUM;
  int BASE_STATIONS_NUM;
  int EMBB_USERS_NUM;
  int URLLC_USERS_NUM;
  int MAXIMUM_URLLC_DEMAND_RATE;
  int CHANNEL_BANDWIDTH;
  int NUMEROLOGY;
  int SUBCHANNELS_NUM;
  int TRANSMITTED_POWER;
  int THERMAL_NOISE_DENSITY;
  int MINIMUM_X;
  int MAXIMUM_X;
  int MINIMUM_Y;
  int MAXIMUM_Y;
  int BASE_STATION_Z;
  int USER_Z;
  int MINIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY;
  int MAXIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY;
  int MINIMUM_URLLC_USER_DEMAND;
  int MAXIMUM_URLLC_USER_DEMAND;
};

// get exactly one field of parameters
// output @ parameters
void getParameter(const string& key, const string& value, Parameters& parameters) {
  if (key == "BASE_FREQUENCY") {
    parameters.BASE_FREQUENCY = stoll(value, nullptr, 10);
  }
  else if (key == "TIME_SLOTS_NUM") {
    parameters.TIME_SLOTS_NUM = stoi(value);
  }
  else if (key == "TIME_MINISLOTS_NUM") {
    parameters.TIME_MINISLOTS_NUM = stoi(value);
  }
  else if (key == "BASE_STATIONS_NUM") {
    parameters.BASE_STATIONS_NUM = stoi(value);
  }
  else if (key == "EMBB_USERS_NUM") {
    parameters.EMBB_USERS_NUM = stoi(value);
  }
  else if (key == "URLLC_USERS_NUM") {
    parameters.URLLC_USERS_NUM = stoi(value);
  }
  else if (key == "MAXIMUM_URLLC_DEMAND_RATE") {
    parameters.MAXIMUM_URLLC_DEMAND_RATE = stoi(value);
  }
  else if (key == "CHANNEL_BANDWIDTH") {
    parameters.CHANNEL_BANDWIDTH = stoi(value);
  }
  else if (key == "NUMEROLOGY") {
    parameters.NUMEROLOGY = stoi(value);
  }
  else if (key == "SUBCHANNELS_NUM") {
    parameters.SUBCHANNELS_NUM = stoi(value);
  }
  else if (key == "TRANSMITTED_POWER") {
    parameters.TRANSMITTED_POWER = stoi(value);
  }
  else if (key == "THERMAL_NOISE_DENSITY") {
    parameters.THERMAL_NOISE_DENSITY = stoi(value);
  }
  else if (key == "MINIMUM_X") {
    parameters.MINIMUM_X = stoi(value);
  }
  else if (key == "MAXIMUM_X") {
    parameters.MAXIMUM_X = stoi(value);
  }
  else if (key == "MINIMUM_Y") {
    parameters.MINIMUM_Y = stoi(value);
  }
  else if (key == "MAXIMUM_Y") {
    parameters.MAXIMUM_Y = stoi(value);
  }
  else if (key == "BASE_STATION_Z") {
    parameters.BASE_STATION_Z = stoi(value);
  }
  else if (key == "USER_Z") {
    parameters.USER_Z = stoi(value);
  }
  else if (key == "MINIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY") {
    parameters.MINIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY = stoi(value);
  }
  else if (key == "MAXIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY") {
    parameters.MAXIMUM_EMBB_USER_MULTICONNECTIVITY_CAPABILITY = stoi(value);
  }
  else if (key == "MINIMUM_URLLC_USER_DEMAND") {
    parameters.MINIMUM_URLLC_USER_DEMAND = stoi(value);
  }
  else if (key == "MAXIMUM_URLLC_USER_DEMAND") {
    parameters.MAXIMUM_URLLC_USER_DEMAND = stoi(value);
  }
  else {
    // TODO throw exception
  }
}

// output @ parameters
void GetParameters(Parameters& parameters) {
  ifstream file;
  file.open(string(getenv("MULTI_DIR")) + "problem_parameters.txt");
  string line;
  while (getline(file, line)) {
    size_t startIdx = line.find_first_of("=") + 1;
    size_t endIdx = line.find_first_of(" ");
    if (endIdx == string::npos) {
      endIdx = line.size();
    }
    string value = line.substr(startIdx, endIdx - startIdx); // [startIdx, endIdx)
    string key = line.substr(0, startIdx - 1); // [0, startIdx)
    getParameter(key, value, parameters);
  }
  file.close();
}

// input @ filepath
// output @ positions
void GetPositions(const string& filepath, vector<Vector3Int>& positions) {
  ifstream file;
  file.open(filepath);
  string line;
  while (getline(file, line)) {
    vector<int> position;
    stringstream stream(line);
    int value = -1;
    while (stream >> value) {
      position.push_back(value);
      if (stream.peek() == ',') {
        stream.ignore();
      }
    }
    positions.push_back(Vector3Int(position[0], position[1], position[2]));
  }
  file.close();
}

// TODO test
// input @ timeSlotIdx
// output @
string GetEmbbUsersPositionsFilepath(const size_t timeSlotIdx) {
  return string(getenv("MULTI_DIR")) + USERS_POSITIONS_DIR + "embb-" + to_string(timeSlotIdx) + ".txt";
}

// TODO test
// input @ timeSlotIndex, timeMinislotIdx
// output @
string GetUrllcUsersPositionsFilepath(const size_t timeSlotIdx, const size_t timeMinislotIdx) {
  return string(getenv("MULTI_DIR")) + USERS_POSITIONS_DIR + "urllc-" + to_string(timeSlotIdx) + "-" + to_string(timeMinislotIdx) + ".txt";
}
