#define SEED_X 1
#define SEED_Y 2
class UsersPositionsGenerator {
public:
  // output @ _embbUsersBeginPositions
  UsersPositionsGenerator(const int embbUsersNum, const int urllcUsersNum, const int minX, const int maxX, const int minY, const int maxY, const int z) {
    default_random_engine engineX(SEED_X);
    default_random_engine engineY(SEED_Y);
    uniform_int_distribution<int> uniformX(minX, maxX);
    uniform_int_distribution<int> uniformY(minY, maxY);
    _embbUsersBeginPositions.resize(embbUsersNum);
    for (int i = 0; i < embbUsersNum; ++i) {
      _embbUsersBeginPositions[i] = Vector3Int(uniformX(engineX), uniformY(engineY), z);
    }
  }
  // output @ positions
  void GetEmbbUsersBeginPositions(vector<Vector3Int>& positions) {
    positions = _embbUsersBeginPositions;
  }
private:
  vector<Vector3Int> _embbUsersBeginPositions;
};
