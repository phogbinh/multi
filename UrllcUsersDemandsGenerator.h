#define SEED_DEMAND 1

class UrllcUsersDemandsGenerator {
public:
  // input @ timeSlotsNum, timeMinislotsNum, urllcUsersNum, minDemand[bits/minislot], maxDemand[bits/minislot]
  // output @ _demands[bits/minislot]
  UrllcUsersDemandsGenerator(const int timeSlotsNum, const int timeMinislotsNum, const int urllcUsersNum, const int minDemand, const int maxDemand) {
    default_random_engine engine(SEED_DEMAND);
    uniform_int_distribution<int> uniform(minDemand, maxDemand);
    for (int i = 0; i < timeSlotsNum; ++i) {
      _demands.push_back(vector<vector<int>>());
      for (int j = 0; j < timeMinislotsNum; ++j) {
        _demands[i].push_back(vector<int>());
        for (int k = 0; k < urllcUsersNum; ++k) {
          _demands[i][j].push_back(uniform(engine));
        }
      }
    }
  }
  // output @ demands[bits/minislot]
  void GetDemands(vector<vector<vector<int>>>& demands) {
    demands = _demands;
  }
private:
  vector<vector<vector<int>>> _demands;
};
