#include <bits/stdc++.h>

using namespace std;

struct Parameters {
  int BASE_FREQUENCY;
  int TIME_SLOTS_NUM;
  int TIME_MINISLOTS_NUM;
  int BASE_STATIONS_NUM;
  int EMBB_USERS_NUM;
  int URLLC_USERS_NUM;
  int MAXIMUM_URLLC_DEMAND_RATE;
  int CHANNEL_BANDWIDTH;
  int NUMEROLOGY;
  int SUBCHANNELS_NUM;
  int TRANSMISSION_POWER;
  int THERMAL_NOISE_DENSITY;
};

class Parser {
public:
  // output @ parameters
  void GetParameters(Parameters& parameters) {
    ifstream file;
    file.open("../problem_parameters.txt"); // path relative to build folder
    string line;
    while (getline(file, line)) {
      size_t startIdx = line.find_first_of("=") + 1;
      size_t endIdx = line.find_first_of(" ");
      if (endIdx == string::npos) {
        endIdx = line.size();
      }
      string value = line.substr(startIdx, endIdx - startIdx); // [startIdx, endIdx)
      string key = line.substr(0, startIdx - 1); // [0, startIdx)
      getParameter(key, stoi(value), parameters);
    }
    file.close();
  }
private:
  // get exactly one field of parameters
  // output @ parameters
  void getParameter(const string& key, const int value, Parameters& parameters) {
    if (key == "BASE_FREQUENCY") {
      parameters.BASE_FREQUENCY = value;
    }
    else if (key == "TIME_SLOTS_NUM") {
      parameters.TIME_SLOTS_NUM = value;
    }
    else if (key == "TIME_MINISLOTS_NUM") {
      parameters.TIME_MINISLOTS_NUM = value;
    }
    else if (key == "BASE_STATIONS_NUM") {
      parameters.BASE_STATIONS_NUM = value;
    }
    else if (key == "EMBB_USERS_NUM") {
      parameters.EMBB_USERS_NUM = value;
    }
    else if (key == "URLLC_USERS_NUM") {
      parameters.URLLC_USERS_NUM = value;
    }
    else if (key == "MAXIMUM_URLLC_DEMAND_RATE") {
      parameters.MAXIMUM_URLLC_DEMAND_RATE = value;
    }
    else if (key == "CHANNEL_BANDWIDTH") {
      parameters.CHANNEL_BANDWIDTH = value;
    }
    else if (key == "NUMEROLOGY") {
      parameters.NUMEROLOGY = value;
    }
    else if (key == "SUBCHANNELS_NUM") {
      parameters.SUBCHANNELS_NUM = value;
    }
    else if (key == "TRANSMISSION_POWER") {
      parameters.TRANSMISSION_POWER = value;
    }
    else if (key == "THERMAL_NOISE_DENSITY") {
      parameters.THERMAL_NOISE_DENSITY = value;
    }
    else {
      // TODO throw exception
    }
  }
};
