#include <bits/stdc++.h>
#include "parser.h"
#include "UsersBeginEndPositionsGenerator.h"
#include "Vector3Int.h"

using namespace std;

int main() {
  Parameters parameters;
  GetParameters(parameters);
  UsersBeginEndPositionsGenerator generator(parameters.EMBB_USERS_NUM, parameters.URLLC_USERS_NUM, parameters.MINIMUM_X, parameters.MAXIMUM_X, parameters.MINIMUM_Y, parameters.MAXIMUM_Y, parameters.USER_Z);
  auto generate_users_positions = [](const string filename, function<void(vector<Vector3Int>&)> GetPositions) {
    ofstream file;
    file.open(filename);
    vector<Vector3Int> positions;
    GetPositions(positions);
    for (auto position : positions) {
      file << position.GetX() << "," << position.GetY() << "," << position.GetZ() << endl;
    }
    file.close();
  };
  generate_users_positions(GetEmbbUsersPositionsFilepath(0), bind(&UsersBeginEndPositionsGenerator::GetEmbbUsersBeginPositions, generator, placeholders::_1));
  generate_users_positions(GetEmbbUsersPositionsFilepath(parameters.TIME_SLOTS_NUM - 1), bind(&UsersBeginEndPositionsGenerator::GetEmbbUsersEndPositions, generator, placeholders::_1));
  generate_users_positions(GetUrllcUsersPositionsFilepath(0, 0), bind(&UsersBeginEndPositionsGenerator::GetUrllcUsersBeginPositions, generator, placeholders::_1));
  generate_users_positions(GetUrllcUsersPositionsFilepath(parameters.TIME_SLOTS_NUM - 1, parameters.TIME_MINISLOTS_NUM - 1), bind(&UsersBeginEndPositionsGenerator::GetUrllcUsersEndPositions, generator, placeholders::_1));
  return 0;
}
