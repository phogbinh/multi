#include "Vector3Int.h"

#define SEED_X 1
#define SEED_Y 50000
class UsersBeginEndPositionsGenerator {
public:
  // input @ embbUsersNum, urllcUsersNum, minX, maxX, minY, maxY, z
  // output @ _embbUsersBeginPositions, _embbUsersEndPositions, _urllcUsersBeginPositions, _urllcUsersEndPositions
  UsersBeginEndPositionsGenerator(const int embbUsersNum, const int urllcUsersNum, const int minX, const int maxX, const int minY, const int maxY, const int z) {
    default_random_engine engineX(SEED_X);
    default_random_engine engineY(SEED_Y);
    uniform_int_distribution<int> uniformX(minX, maxX);
    uniform_int_distribution<int> uniformY(minY, maxY);
    _embbUsersBeginPositions.resize(embbUsersNum);
    for (int i = 0; i < embbUsersNum; ++i) {
      _embbUsersBeginPositions[i] = Vector3Int(uniformX(engineX), uniformY(engineY), z);
    }
    _embbUsersEndPositions.resize(embbUsersNum);
    for (int i = 0; i < embbUsersNum; ++i) {
      _embbUsersEndPositions[i] = Vector3Int(uniformX(engineX), uniformY(engineY), z);
    }
    _urllcUsersBeginPositions.resize(urllcUsersNum);
    for (int i = 0; i < urllcUsersNum; ++i) {
      _urllcUsersBeginPositions[i] = Vector3Int(uniformX(engineX), uniformY(engineY), z);
    }
    _urllcUsersEndPositions.resize(urllcUsersNum);
    for (int i = 0; i < urllcUsersNum; ++i) {
      _urllcUsersEndPositions[i] = Vector3Int(uniformX(engineX), uniformY(engineY), z);
    }
  }
  // output @ positions
  void GetEmbbUsersBeginPositions(vector<Vector3Int>& positions) {
    positions = _embbUsersBeginPositions;
  }
  // output @ positions
  void GetEmbbUsersEndPositions(vector<Vector3Int>& positions) {
    positions = _embbUsersEndPositions;
  }
  // output @ positions
  void GetUrllcUsersBeginPositions(vector<Vector3Int>& positions) {
    positions = _urllcUsersBeginPositions;
  }
  // output @ positions
  void GetUrllcUsersEndPositions(vector<Vector3Int>& positions) {
    positions = _urllcUsersEndPositions;
  }
private:
  vector<Vector3Int> _embbUsersBeginPositions;
  vector<Vector3Int> _embbUsersEndPositions;
  vector<Vector3Int> _urllcUsersBeginPositions;
  vector<Vector3Int> _urllcUsersEndPositions;
};
